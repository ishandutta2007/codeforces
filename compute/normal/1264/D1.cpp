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
const int maxn=2e3+7;
const int mod=998244353;
ll C[maxn][maxn];
ll sC[maxn][maxn];
void init()
{
	for(int i=0;i<maxn;i++)
	{
		C[i][0]=C[i][i]=1;
		for(int j=1;j<i;j++)
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
		sC[i][i]=1;
		for(int j=i-1;j>=0;j--) sC[i][j]=(sC[i][j+1]+C[i][j])%mod;
	}
}
ll comb(int n,int m)
{
	if(n<0||m<0||m>n) return 0;
	return C[n][m];
}
ll scomb(int n,int m)
{
	m=max(0,m);
	if(n<0||m>n) return 0;
	return sC[n][m];
}
int lp[maxn],rp[maxn],qp[maxn];
int main()
{
	init();
	string s;
	cin>>s;
	for(int i=0;i<s.length();i++)
	{
		if(i)
		{
			rp[i]=rp[i-1];
			lp[i]=lp[i-1];
			qp[i]=qp[i-1];
		}
		if(s[i]=='?') qp[i]++;
		else if(s[i]=='(') lp[i]++;
		else rp[i]++;
	}
	ll ans=0;
	for(int d=1;d<s.length();d++)
	{
		for(int i=0;i<s.length();i++)
		{
			if(s[i]==')') continue;
			ll l=comb(i?qp[i-1]:0,d-(i?lp[i-1]:0)-1),r=scomb(qp[s.length()-1]-qp[i],d-(rp[s.length()-1]-rp[i]));
			dbg(d,i,l,r);
			ans=(ans+l*r%mod)%mod;
		}
	}
	cout<<ans<<'\n';
}