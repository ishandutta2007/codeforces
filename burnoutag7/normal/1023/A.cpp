/******************
*  Writer: Oh no  *
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
string s,t;
int ls,lt;
bool f=1;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>ls>>lt;
	cin>>s>>t;
	if(ls-1>lt){
		cout<<"NO"<<endl;return 0;
	}
	if(s==t){
		cout<<"YES"<<endl;return 0;
	}
	for(int i=0;s[i]!='*';i++){
		if(s[i]!=t[i]){
			f=0;
			break;
		}
	}
	for(int i=1;s[s.size()-i]!='*';i++){
		if(s[s.size()-i]!=t[t.size()-i]){
			f=0;
			break;
		}
	}
	if(f){
		cout<<"YES"<<endl;
	}else{
		cout<<"NO"<<endl;
	}
	return 0;
}