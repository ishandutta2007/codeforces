#include <bits/stdc++.h>
#include <string>
using namespace std;
string k;
string s[1000];
int main(){
	int n,m;
	cin>>n>>k;
	cin>>m;
	for(int i=0;i<m;++i)cin>>s[i];
	bool cmap[128]={false};
	bool hmap[128];
	for(int j=0;j<n;++j){
		if(k[j]!='*'){
			cmap[k[j]]=true;
		}
	}
	for(char j='a';j<='z';++j){
			hmap[j]=true;
		}
	
	for(int i=0;i<m;++i){
		int j;
		for(j=0;j<n;++j){
			if(k[j]!='*'&&s[i][j]!=k[j])break;
		}
		if(j<n)continue;
		for(j=0;j<n;++j){
			if(k[j]=='*'&&cmap[s[i][j]])break;
		}
		if(j<n)continue;
		bool lmap[128]={false};
		for(j=0;j<n;++j){
			if(k[j]=='*')lmap[s[i][j]]=true;
		}
		for(char j='a';j<='z';++j){
			hmap[j]&=lmap[j];
		}
	}
	int ct=0;
	for(char j='a';j<='z';++j){
		if(hmap[j])++ct;
	}
	cout<<ct<<endl;
}