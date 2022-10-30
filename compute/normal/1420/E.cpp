#include<bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define dbg(x...) do { cout << "\033[32;1m " << #x << " -> "; err(x); } while (0)
void err() { cout << "\033[39;0m" << endl; }
template<template<typename...> class T, typename t, typename... A>
void err(T<t> a, A... x) { for (auto v: a) cout << v << ' '; err(x...); }
template<typename T, typename... A>
void err(T a, A... x) { cout << a << ' '; err(x...); }
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
ll rand_int(ll l, ll r) //[l, r]
{
    static mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
    return uniform_int_distribution<ll>(l, r)(gen);
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
int dp[82][82][3400];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	int n;
	cin>>n;
	vi a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	memset(dp,-0x3f,sizeof(dp));
	vi all;
	vi pos;
	{
		int pre=0;
		for(int i=0;i<n;i++)
		{
			if(a[i])
			{
				all.push_back(i-pre);
				pos.push_back(i);
				pre=i+1;
			}
		}
		all.push_back(n-pre);
		pos.push_back(n);
	}
	int sz=all.size();
	int zcnt=n-sz+1;
	dp[0][0][0]=0;
	for(int i=1;i<=sz;i++)
	{
		for(int j=0;j<=zcnt;j++)
		{
			for(int k=0;k<=n*(n-1)/2;k++)
			{
				if(dp[i-1][j][k]<0) continue;
				for(int cc=0;cc+j<=zcnt;cc++)
				{
					int pre=i-1+j+cc;
					int d=abs(pre-pos[i-1]);
					int cur=cc*j;
	//				dbg(i,j,cc,k,d);
					dp[i][j+cc][k+d]=max(dp[i-1][j][k]+cur,dp[i][j+cc][k+d]);
				}
			}
		}
	}
	vi ans(n*(n-1)/2+1);
	for(int i=0;i<ans.size();i++) ans[i]=dp[sz][zcnt][i];
	for(int i=1;i<ans.size();i++) ans[i]=max(ans[i-1],ans[i]);
	print(ans);
}