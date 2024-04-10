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
const int mod=998244353;
ll quick(ll a,ll b){
	ll ret=1;
	while(b)
	{
		if(b&1)
			ret=ret*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ret;
}
ll inv(ll a){
	return quick(a,mod-2);
}
ll sufm[maxn],sufsum[maxn];
int p[maxn];
ll calc(int l,int r)
{
	ll ret=sufsum[l]-sufsum[r];
	ret=(ret+mod)%mod;
	ret=ret*inv(sufm[r])%mod;
	return ret;
}
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>p[i];
	sufm[n+1]=1;
	for(int i=n;i>=1;i--) 
	{
		sufm[i]=sufm[i+1]*(100*inv(p[i])%mod)%mod;
		sufsum[i]=(sufsum[i+1]+sufm[i])%mod;
	}
	set<int> pos;
	pos.insert(1);
	pos.insert(n+1);
	ll ans=sufsum[1];
	while(q--)
	{
		int u;
		cin>>u;
		dbg(u);
		if(pos.count(u))
		{
			pos.erase(pos.find(u));
			auto pp=pos.lower_bound(u);
			ans=(ans-calc(u,*pp)+mod)%mod;
			auto ppp=pp;
			ppp--;
			ans=(ans-calc(*ppp,u)+mod)%mod;
			ans=(ans+calc(*ppp,*pp))%mod;
		}
		else{
			auto nxt=pos.lower_bound(u);
			auto pre=nxt;
			pre--;
			ans=(ans-calc(*pre,*nxt)+mod)%mod;
			ans=(ans+calc(*pre,u))%mod;
			ans=(ans+calc(u,*nxt))%mod;
			pos.insert(u);
		}
		cout<<ans<<endl;

	}
}