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
typedef pair<ll,int> pi;
typedef vector<ll> vi;
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
ll mul(ll a, ll b, ll m)
{
    return (a * b - ll((long double)a * b / m) * m + m) % m;
}
ll power(ll v, ll p, ll m)
{
    ll r = 1;
    while (p)
    {
        if (p & 1)
			r=mul(r,v,m);
		v=mul(v,v,m);
        p >>= 1;
    }

    return r;
}

bool witness(ll a, ll p)
{
    int k = 0;
    ll q = p - 1;
    while ((q & 1) == 0)
        ++k, q >>= 1;
    ll v = power(a, q, p);
    if (v == 1 || v == p - 1)
        return false; // probably prime number
    while (k-- != 0)
    {
		v=mul(v,v,p);
        if (v == p - 1)
            return false;
    }

    return true; // composite number
}

bool miller_rabin(ll p)
{
    if (p == 1)
        return false;
    if (p == 2)
        return true;
    if (p % 2 == 0)
        return false;

    for (int i = 0; i != 50; ++i)
    {
        ll a = rand_int(0,1e18) % (p - 1) + 1;
        if (witness(a, p))
            return false;
    }

    return true;
}
ll pollard_rho(ll n, int a)//n
{
    ll x = 2, y = 2, d = 1, k = 0, i = 1;
    while(d == 1)
    {
        ++k;
        x = mul(x, x, n) + a;
        d = __gcd(x >= y ? x - y : y - x, n);
        if(k == i)
        {
            y = x;
            i <<= 1;
        }
    }
    if(d == n) return pollard_rho(n, a + 1);
    return d;
}
vc<ll> fac;
void decomp(ll n)
{
    if(miller_rabin(n))
    {
        fac.push_back(n);
        return;
    }
    ll d=pollard_rho(n,233);
    if(n!=d) decomp(n/d);
    decomp(d);
}
void getfac(ll n)
{
    fac.clear();
    if(n>1) decomp(n);
}
vc<pi> cfac;
vc<ll> dfac;
void getd(int u=0,ll cur=1)
{
	if(u>=cfac.size())
	{
		dfac.push_back(cur);
		return;
	}
	for(int c=0;c<=cfac[u].second;c++)
	{
		getd(u+1,cur);
		cur*=cfac[u].first;
	}
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	int n;
	cin>>n;
	vc<ll> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	int T=10;
	ll ans=1;
	while(T--)
	{
		ll v=a[rand_int(0,n-1)];
		getfac(v);
		sort(fac.begin(),fac.end());
		cfac.clear();
		for(auto u:fac)
		{
			if(cfac.empty()||cfac.back().first!=u)
				cfac.emplace_back(u,1);
			else cfac.back().second++;
		}
		dfac.clear();
		getd();
		sort(dfac.begin(),dfac.end());
		mkuni(fac);
		dbg(v,dfac);
		map<ll,int> id;
		for(int i=0;i<dfac.size();i++) id[dfac[i]]=i;
		vi cnt(dfac.size());
		for(int i=0;i<n;i++)
		{
			ll cur=__gcd(a[i],v);
			cnt[id[cur]]++;
		}
		for(int j=0;j<fac.size();j++)
		for(int i=dfac.size()-1;i>=0;i--)
		{
			//dbg(dfac[i],fac[j]);
			if(__int128(dfac[i])*fac[j]<=v&&id.count(dfac[i]*fac[j]))
				cnt[i]+=cnt[id[dfac[i]*fac[j]]];
		}
		for(int i=0;i<dfac.size();i++)
		{
			if(cnt[i]*2>=n) ans=max(ans,dfac[i]);
			dbg(dfac[i],cnt[i]);
		}
	}
	print(ans);
}