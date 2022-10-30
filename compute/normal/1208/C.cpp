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
const int maxn=1e3+7;
int ans[maxn][maxn];
int n;
inline int getid(int i,int j)
{
	return j/4+i/4*n/4;
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			ans[i][j]=getid(i,j)*16+((i%4)*4+j%4);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			printf("%d%c",ans[i][j],j==n-1?'\n':' ');
	}
	/*for(int i=0;i<n;i++)
	{
		int X=0;
		for(int j=0;j<n;j++)
			X^=ans[i][j];
		dbg(i,X);
	}
	for(int j=0;j<n;j++)
	{
		int C=0;
		for(int i=0;i<n;i++)
			C^=ans[i][j];
		dbg(j,C);
	}*/
}