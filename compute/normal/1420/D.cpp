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
const int mod=998244353;
const int maxn=3e5+7;
ll fac[maxn];
ll invfac[maxn];
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
void init()
{
	fac[0]=1;
	for(int i=1;i<maxn;i++) fac[i]=fac[i-1]*i%mod;
	invfac[maxn-1]=inv(fac[maxn-1]);
	for(int i=maxn-2;i>=0;i--) invfac[i]=invfac[i+1]*(i+1)%mod;
}
ll C(int n,int m)
{
	if(m<0||m>n) return 0;
	return fac[n]*invfac[m]%mod*invfac[n-m]%mod;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	init();
	int n,k;
	cin>>n>>k;
	vc<pi> all(n);
	vi aa;
	for(int i=0,l,r;i<n;i++)
	{
		cin>>l>>r;
		aa.push_back(l);
		aa.push_back(r);
		all[i]={l,r};
	}
	mkuni(aa);
	auto getid=[&](int x){
		return lower_bound(aa.begin(),aa.end(),x)-aa.begin();
	};
	int sz=aa.size();
	vi add(sz+1),del(sz+1);
	for(auto u:all)
	{
		int l=u.first,r=u.second;
		l=getid(l),r=getid(r);
		add[l]++;
		del[r+1]++;
	}
	ll ans=0;
	int cur=0;
	for(int i=0;i<=sz;i++)
	{
		cur-=del[i];
		for(int j=1;j<=add[i];j++)
			ans=(ans+C(add[i],j)*C(cur,k-j)%mod)%mod;
		cur+=add[i];
	}
	print(ans);
}