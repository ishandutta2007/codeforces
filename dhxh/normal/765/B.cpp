#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int n;

string str;
int cnt = -1;

int main(){
	int i, j;
	char ch;
	char chb;
	bool flag = true;	
	
	cin >> str;
	
	for(i=0;i<str.length();i++){
		ch = cnt + 'a';
		chb = cnt + 'a' + 1;
		if(ch >= str[i]){
			continue;
		}else if(str[i] == chb){
			cnt++;
		}else{
			flag = false;
		}
	}
	
	if(!flag){
		cout << "NO" << endl;
	}else{
		cout << "YES" << endl;
	}
	
	return 0;
}