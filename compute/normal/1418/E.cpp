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
const int mod=998244353;
ll quick(ll a,ll b)
{
	ll ret=1;
	while(b)
	{
		if(b&1) ret=ret*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ret;
}
ll inv(ll a){return quick(a,mod-2);}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m;
	cin>>n>>m;
	vc<ll> d(n);
	for(int i=0;i<n;i++) cin>>d[i];
	sort(d.begin(),d.end());
	vc<ll> pre(n);
	pre[0]=d[0];
	for(int i=1;i<n;i++) pre[i]=(pre[i-1]+d[i])%mod;
	ll tot=pre[n-1];
	while(m--)
	{
		int a,b;
		cin>>a>>b;
		b=lower_bound(d.begin(),d.end(),b)-d.begin();
		b--;
		ll sd=b>=0?pre[b]:0,sD=(tot-sd+mod)%mod;
		b=n-(b+1);
		dbg(b);
		ll ans=0;
		if(b>a) ans=(b-a)*inv(b)%mod*sD%mod;
		//if(n>b) ans=(ans+sd*inv(n-b)%mod*inv(2)%mod*(n-b+1)%mod*(n-b)%mod)%mod;
		if(n>b&&a<=b) ans=(ans+sd*inv(b+1)%mod*(b-a+1)%mod)%mod;
		print(ans);
	}
}