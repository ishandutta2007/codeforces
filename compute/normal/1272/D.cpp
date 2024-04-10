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
typedef pair<int,int> PII;
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
const int maxn=2e5+7;
int dp[maxn][2];
int a[maxn];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	memset(dp,-0x3f,sizeof(dp));
	dp[0][0]=0;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>a[i-1])
		{
			dp[i][0]=dp[i-1][0]+1;
			dp[i][1]=dp[i-1][1]+1;
		}
		else{
			dp[i][0]=1;
		}
		if(i>=3&&a[i]>a[i-2])
			dp[i][1]=max(dp[i][1],dp[i-2][0]+1);
		ans=max({ans,dp[i][0],dp[i][1]});
		dbg(i,dp[i][0],dp[i][1]);
	}
	cout<<ans<<endl;
}