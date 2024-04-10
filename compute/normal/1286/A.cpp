#include<bits/stdc++.h>
using namespace std;
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
typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
template<class T> using vc=vector<T>;
template<class T> using vvc=vc<vc<T>>;
template<class T> void mkuni(vector<T>&v)
{
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
}
template<class T>
void print(T x,int suc=1)
{
    cout<<x;
    if(suc==1) cout<<'\n';
    else cout<<' ';
}
template<class T>
void print(const vector<T>&v,int suc=1)
{
    for(int i=0;i<v.size();i++)
        print(v[i],i==(int)(v.size())-1?suc:2);
}
const int INF=0x3f3f3f3f;
const int maxn=105;
int dp[maxn][maxn][maxn][2];
int main()
{
	int n;
	cin>>n;
	int even=n/2,odd=(n+1)/2;
	vi a(n);
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		if(a[i])
		{
			if(a[i]&1) odd--;
			else even--;
		}
	}
	memset(dp,0x3f,sizeof(dp));
	dp[0][odd][even][0]=dp[0][odd][even][1]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=odd;j++)
		{
			for(int k=0;k<=even;k++)
			{
				if(a[i]==0)
				{
					dp[i][j][k][0]=min(dp[i-1][j][k+1][0],dp[i-1][j][k+1][1]+1);
					dp[i][j][k][1]=min(dp[i-1][j+1][k][0]+1,dp[i-1][j+1][k][1]);
				}
				else if(a[i]&1)
					dp[i][j][k][1]=min(dp[i-1][j][k][0]+1,dp[i-1][j][k][1]);
				else
					dp[i][j][k][0]=min(dp[i-1][j][k][0],dp[i-1][j][k][1]+1);
				dbg(i,j,k,dp[i][j][k][0],dp[i][j][k][1]);
			}
		}
	}
	cout<<min(dp[n][0][0][0],dp[n][0][0][1])<<'\n';
}