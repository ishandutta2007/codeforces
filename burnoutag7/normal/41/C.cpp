/******************
*  Author: BD747  *
******************/
#include<algorithm>
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<map>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#include<vector>
using namespace std;

string s;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>s;
	if(s.size()<=2){
		cout<<s;
	}
	for(int i=1;i<(s.size())-2;i++){
		if(s[i]=='a' && s[i+1]=='t'){
			s.erase(i+1,1);
			s[i]='@';
			break;
		}
	}
	for(int i=1;i<s.size()-3;){
		if(s[i]=='d' && s[i+1]=='o' && s[i+2]=='t'){
			s.erase(i+1,2);
			s[i]='.';
		}else{
			i++;
		}
	}
	cout<<s;
	
	return 0;
}