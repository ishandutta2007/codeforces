#include<bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define dbg(x...) do { cout << "\033[33;1m " << #x << " -> "; err(x); } while (0)
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
const int maxn=2e5+7;
string lk[maxn];
ll val[maxn];
void solve()
{
    int n,m,p;
    cin>>n>>m>>p;
    for(int i=0;i<n;i++)
    {
        cin>>lk[i];
        for(int j=0;j<m;j++)
            val[i]|=(1LL<<j)*(lk[i][j]=='1');
    }
    ll mx=0;
    int T=20;
    int var=(n+1)/2;
    while(T--)
    {
        int org=rand_int(0,n-1);
        vc<ll> cv(n);
        map<ll,int> cnt;
        for(int i=0;i<n;i++)
        {
            cv[i]=val[i]&val[org];
            cnt[cv[i]]++;
        }
        //dbg(org,val[org]);
        //for(auto u:cnt) dbg(u.first,u.second);
        for(int j=0;j<m;j++)
        {
            for(ll S=val[org];S;S=(S-1)&(val[org]))
            {
                if(S>>j&1) cnt[S^(1LL<<j)]+=cnt[S];
            }
        }
        for(auto u:cnt) //dbg(u.first,u.second);
        {
            if(u.second>=var)
            {
                if(__builtin_popcountll(mx)<__builtin_popcountll(u.first))
                    mx=u.first;
            }
        }
    }
    for(int j=0;j<m;j++)
    {
        cout<<(mx>>j&1);
    }
    cout<<'\n';
}
int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int T=1;
    while(T--) solve();
}