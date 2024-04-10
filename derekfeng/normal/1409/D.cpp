#include<bits/stdc++.h>
using namespace std;
int n,T,S;
string s;
long long write(string s){
	long long ret=0;
	for(int i=0;i<s.size();i++)ret=ret*10+s[i]-'0';
	return ret;
}
int getst(string s){
	int ret=0;
	for(int i=0;i<s.size();i++)ret+=s[i]-'0';
	return ret;
}
void SOLVE(){
	if(getst(s)<=S){
		cout<<0<<"\n";
		return;
	}
	s="0"+s;
	string t=s;
	for(int i=t.size()-1;i>=0;i--){
		if(t[i]=='9');
		else{
			t[i]++;
			if(getst(t)<=S){
				cout<<write(t)-write(s)<<"\n";
				break;
			}
		}
		t[i]='0';
	}
}
int main(){
	cin>>T;
	while(T--){
		cin>>s>>S;
		SOLVE();
	}
}