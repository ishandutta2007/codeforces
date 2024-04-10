#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

string pokemon[] = {"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};

int main(){
	int n;
	string str;
	cin >> n;
	cin >> str;
	for(int i = 0;i < 8;i++){
		if(str.size() != pokemon[i].size())continue;
		bool ok = true;
		for(int j = 0;j < str.size();j++){
			if(str[j] == '.')continue;
			if(str[j] != pokemon[i][j])ok = false;
		}
		if(ok){
			cout << pokemon[i] << endl;
			return 0;
		}
	}
	return 0;
}