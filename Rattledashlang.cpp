/*
02 - FOR LOOPS Homework Question 
Author: Taya
Date: Jan 12, 2024
Purpose: Write a program that displays an organized table to the user.
*/
#include <iostream> 	// include library for input wand output
#include <math.h>		// include library for math functions
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;	// Makes life slightly easier

string lowercase(string name){			//Defines a string function with a string parameter for making a string lowercase
	string lower_name="";		//Declares an empty string for the lowercase string
	
	for (int i=0;i<name.length();i++){		//From 0 to the length of the original string
		lower_name+=tolower(name.at(i));		//Adds the lowercase version of the current character to the new string
	}		
	return lower_name;		//Returns the new lowercase string
}

int position (string rattlebet[26], string word){
	for (int i=0;i<26;i++){
		if (lowercase(word)==rattlebet[i]){
			return i;
		}
	}
	return -1;
}

string english (string text){
	string english="";
	string alphabet[26];
	string letter;
	int pos;
	int hyphen, last;
	last=0;
	int words=1;
	for (int i=0;i<text.length();i++){
		if (text.at(i)==' '){
			words++;
		}
	}
	
	alphabet[0]="ratrattle";
	alphabet[1]="dashdashrat";
	alphabet[2]="dash";
	alphabet[3]="dashrat";
	alphabet[4]="rattletletle";
	alphabet[5]="rattletle";
	alphabet[6]="dashtletle";
	alphabet[7]="ratratrat";
	alphabet[8]="rat";
	alphabet[9]="ratdash";
	alphabet[10]="tledash";
	alphabet[11]="rattle";
	alphabet[12]="rattletlerat";
	alphabet[13]="dashdash";
	alphabet[14]="dashratdash";
	alphabet[15]="dashratdashrat";
	alphabet[16]="tle";
	alphabet[17]="tlerat";
	alphabet[18]="tlerattle";
	alphabet[19]="ratdashdash";
	alphabet[20]="tledashtle";
	alphabet[21]="ratrat";
	alphabet[22]="ratdashrat";
	alphabet[23]="tletle";
	alphabet[24]="ratratdash";
	alphabet[25]="rattlerat";
	
	for (int i=0;i<words;i++){
		for (int j=last;text.at(j)!='!';j++){
			hyphen=min(text.find(' ',last+1), text.find('-',last+1));
//			hyphen=text.find(' ',last+1);
//			if (text.find('-',last+1)!=string::npos and text.find('-',last+1)<text.find(' ',last+1)){
//				hyphen=text.find('-',last+1);
//			}
			
			if (last>0){
				letter=text.substr(last+1,hyphen-last-1);
			}
			else{
				letter=text.substr(last,hyphen-last);
			}
			pos=position(alphabet,letter);
//			cout<<letter<<" "<<hyphen<<" "<<last<<" "<<words<<endl;
			if (pos>-1){
				english+=char(pos+97);
			}
			else{
				english+=letter;
			}
			
			if (hyphen==string::npos or text.at(hyphen)==' '){
				last=hyphen;
				break;
			}
			last=hyphen;
		}
		english+=" ";
	}
	if (english.back()==' '){
		english.pop_back();
	}
	return english;
}

string rattlelang (string text){
	string rattle="";
	string alphabet[26];
	
	alphabet[0]="ratrattle";
	alphabet[1]="dashdashrat";
	alphabet[2]="dash";
	alphabet[3]="dashrat";
	alphabet[4]="rattletletle";
	alphabet[5]="rattletle";
	alphabet[6]="dashtletle";
	alphabet[7]="ratratrat";
	alphabet[8]="rat";
	alphabet[9]="ratdash";
	alphabet[10]="tledash";
	alphabet[11]="rattle";
	alphabet[12]="rattletlerat";
	alphabet[13]="dashdash";
	alphabet[14]="dashratdash";
	alphabet[15]="dashratdashrat";
	alphabet[16]="tle";
	alphabet[17]="tlerat";
	alphabet[18]="tlerattle";
	alphabet[19]="ratdashdash";
	alphabet[20]="tledashtle";
	alphabet[21]="ratrat";
	alphabet[22]="ratdashrat";
	alphabet[23]="tletle";
	alphabet[24]="ratratdash";
	alphabet[25]="rattlerat";
	
	for (int i=0;i<text.length();i++){
		text.at(i)=tolower(text.at(i));
		if (text.at(i)-96>0 and text.at(i)-96<27){
			rattle+=alphabet[text.at(i)-97];
			rattle+="-";
		}
		else if (text.at(i)==' '){
			rattle.pop_back();
			rattle+=" ";
		}
		else{
			rattle+=text.at(i);
		}
	}
	if (rattle.back()=='-'){
		rattle.pop_back();
	}
	
	return rattle;
}

int main(){				// starts the program
	string words;
	int mode=0;
	while (mode!=3){
		cout<<"1. Rattledashlang --> English\n";
		cout<<"2. English --> Rattledashlang\n";
		cout<<"3. Quit\n";
		cin>>mode;
		while (mode<1 or mode>3){
			cout<<"Retry.\n";
			cin>>mode;
		}
		cin.ignore();
		
		cout<<flush;
		system("CLS");
		
		if (mode==1){
			cout<<"Enter Rattledashlang text: ";
			getline(cin, words);
			while (words.length()==0){
				cout<<"Enter Rattledashlang text: ";
				getline(cin, words);
			}
			cout<<"\nThat means \""<<english(words)<<"\" in English.\n";
		}
		else if (mode==2){
			cout<<"Enter English text: ";
			getline(cin, words);
			while (words.length()==0){
				cout<<"Enter Rattledashlang text: ";
				getline(cin, words);
			}
			cout<<"\nThat means \""<<rattlelang(words)<<"\" in Rattledashlang.\n";
		}
		else{
			cout<<flush;
			system("CLS");
			cout<<"rattledash";
			break;
		}
		system("PAUSE");
		cout<<flush;
		system("CLS");
	}
	return 0;	// Ends the program
}
