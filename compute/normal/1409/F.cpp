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
int dp[205][205][205];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,cc;
	cin>>n>>cc;
	string s,t;
	cin>>s>>t;
	if(t[0]==t[1])
	{
		for(auto &u:s)
		{
			if(!cc) break;
			if(u!=t[0]) u=t[0],cc--;
		}
		int cnt=0;
		for(auto u:s) if(u==t[0]) cnt++;
		print(cnt*(cnt-1)/2);
		return 0;
	}
	memset(dp,-0x3f,sizeof(dp));
	dp[0][0][0]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=min(i-1,cc);j++)
		{
			for(int k=0;k<i;k++)
			{
				if(s[i-1]!=t[0]&&s[i-1]!=t[1])
					dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]);
				if(s[i-1]==t[0])
					dp[i][j][k+1]=max(dp[i][j][k+1],dp[i-1][j][k]);
				if(s[i-1]==t[1])
					dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+k);
				dp[i][j+1][k+1]=max(dp[i][j+1][k+1],dp[i-1][j][k]);
				dp[i][j+1][k]=max(dp[i][j+1][k],dp[i-1][j][k]+k);
			}
		}
	}
	int ans=0;
	for(int k=0;k<=n;k++) ans=max(ans,dp[n][cc][k]);
	print(ans);
}