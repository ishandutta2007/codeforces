#include <bits/stdc++.h>
using namespace std;
int n;
int s[200000],g[200000],e[200000];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>s[i]>>g[i];
	}
	e[0]=s[0]+g[0];
	for(int i=1;i<n;++i){
		e[i]=min(e[i-1]+1,s[i]+g[i]);
		/*if(e[i]>s[i]+g[i]){
			e[i]=s[i]+g[i];
			for(int j=i-1;j>=0;--j){
				if(e[j]>e[j+1]+1){
					e[j]=e[j+1]+1;
				}
				else break;
			}
		}*/
	}
	for(int i=n-2;i>=0;--i){
		e[i]=min(e[i],e[i+1]+1);
	}
	bool w=true;
	long long ct=0;
	for(int i=0;i<n;++i){
		if(e[i]<s[i]){
			w=false;
			break;
		}
		else{
			ct+=e[i]-s[i];
		}
	}
	if(!w)cout<<-1<<endl;
	else{
		cout<<ct<<endl;
		for(int i=0;i<n;++i)cout<<e[i]<<' ';
		cout<<endl;
	}
}