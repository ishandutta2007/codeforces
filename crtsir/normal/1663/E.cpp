#include<bits/stdc++.h>
using namespace std;
int n,cnt[26];
string s[103],t="theseus";
int main(){
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>s[i];
	for(int i=0;i<n;i++)
		for(int j=0;j<n-7;j++){
			bool ok=1;
			for(int k=0;k<7;k++)
				if(s[i][j+k]!=t[k])
					ok=0;
			if(ok){
				cout<<"YES";
				return 0;
			}
		}
	for(int i=0;i<n-7;i++)
		for(int j=0;j<n;j++){
			bool ok=1;
			for(int k=0;k<7;k++)
				if(s[i+k][j]!=t[k])
					ok=0;
			if(ok){
				cout<<"YES";
				return 0;
			}
		}
	for(int i=0;i<n-7;i++)
		for(int j=0;j<n-7;j++){
			bool ok=1;
			for(int k=0;k<7;k++)
				if(s[i+k][j+k]!=t[k])
					ok=0;
			if(ok){
				cout<<"YES";
				return 0;
			}
		}
	cout<<"NO";
}