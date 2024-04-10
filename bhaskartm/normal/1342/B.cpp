#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	for(int g=0; g<t; g++){
		string s;
		cin>>s;
		bool booly=true;
		char a=s[0];
		for(int i=0; i<s.size(); i++){
			if(s[i]!=a){
				booly=false;
				break;
			}
		}
		if(booly){
			cout<<s<<endl;
			continue;
		}
		int n=s.size();
		int val[n-1];
		for(int i=0; i<n-1; i++){
			val[i]=-1;
		}
		for(int i=0; i<s.size()-1; i++){
			if(s[i]=='1' && s[i+1]=='1'){
				val[i]=0;
				continue;
			}
			if(s[i]=='0' && s[i+1]=='0'){
				val[i]=1;
				continue;
			}
		}
		for(int i=0; i<s.size()-1; i++){
			cout<<s[i];
			if(val[i]!=-1){
				cout<<val[i];
			}
		}
		cout<<s[n-1];
		cout<<endl;
	}
	
	
	return 0;
}