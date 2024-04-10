#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#ifndef ONLINE_JUDGE
#define dbg(x...) do{cout << "\033[32;1m" << #x << "->" ; err(x);} while(0)
void err(){cout << "\033[39;0m" << endl;}
template<template<typename...> class T,typename t,typename... A>
void err(T<t> a,A... x){for (auto v:a) cout << v << ' '; err(x...);}
template<typename T,typename... A>
void err(T a,A... x){cout << a << ' '; err(x...);}
#else
#define dbg(...)
#endif
int f[2][55];
ll dp[1005][55][55];
string c,s[2];
void kmp(int ty)
{
	int m=s[ty].length();
	int i=0,j=f[ty][0]=-1;
	while(i<m)
	{
		while(j!=-1&&s[ty][i]!=s[ty][j]) j=f[ty][j];
		f[ty][++i]=++j;
	}
}
const ll INF=1LL<<60;
ll dfs(int i,int j,int k)
{
	if(i==c.length()) return 0;
	if(j==s[0].length()) j=f[0][j];
	if(k==s[1].length()) k=f[1][k];
	if(dp[i][j+1][k+1]!=-INF) return dp[i][j+1][k+1];
	ll ret=-INF;
	bool one=(c[i]!='*');
	if(one)
	{
		int nxtj;
		if(j==-1) nxtj=0;
		else {
			nxtj=j;
			while(nxtj!=-1&&c[i]!=s[0][nxtj])  nxtj=f[0][nxtj]; 
			nxtj++;
		}
		int val=(nxtj==s[0].length());
		int nxtk=0;
		if(k==-1) nxtk=0;
		else {
			nxtk=k;
			while(nxtk!=-1&&c[i]!=s[1][nxtk])  nxtk=f[1][nxtk]; 
			nxtk++;
		}
		int val2=(nxtk==s[1].length());
		ret=max(ret,dfs(i+1,nxtj,nxtk)+val-val2);
	}
	else
	{
		for(int p=0;p<26;p++)
		{	
			char nxt='a'+p;
			int nxtj;
			if(j==-1) nxtj=0;
			else{
				nxtj=j;
				while(nxtj!=-1&&nxt!=s[0][nxtj]) nxtj=f[0][nxtj];
				nxtj++;
			}
			int val=(nxtj==s[0].length());
			int nxtk;
			if(k==-1) nxtk=0;
			else{
				nxtk=k;
				while(nxtk!=-1&&nxt!=s[1][nxtk]) nxtk=f[1][nxtk];
				nxtk++;
			}
			int val2=(nxtk==s[1].length());
			ret=max(ret,dfs(i+1,nxtj,nxtk)+val-val2);
		}
	}
	dp[i][j+1][k+1]=ret;
	dbg(i,j,k,ret);
	return ret;
}

int main()
{
	for(int i=0;i<1005;i++)
		for(int j=0;j<55;j++)
			for(int k=0;k<55;k++)
				dp[i][j][k]=-INF;
	cin>>c>>s[0]>>s[1];
	kmp(0);
	kmp(1);
	cout<<dfs(0,0,0)<<endl;
}