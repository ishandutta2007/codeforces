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
const int mod=1e9+7;
const int maxn=3e5+7;
int p[maxn];
pi q[maxn];
ll two[maxn*2],inv2[maxn*2];

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
int sz;
#define lson o<<1
#define rson o<<1|1
#define Lson L,mid,lson
#define Rson mid+1,R,rson

//\sum 2^{i-j+1}a_ia_j=2^i a_i 2^(1-j) a_j
struct D{
    ll val,ls,rs,cnt;
    D(){}
}T[maxn<<3];
vc<pi> all;
inline void Merge(int o)
{
    T[o].val=(T[lson].val+T[rson].val+T[lson].ls*T[rson].rs%mod*inv2[T[lson].cnt]%mod)%mod;
    T[o].ls=(T[lson].ls+T[rson].ls*two[T[lson].cnt]%mod)%mod;
    T[o].rs=(T[rson].rs*inv2[T[lson].cnt]%mod+T[lson].rs)%mod;
    T[o].cnt=T[lson].cnt+T[rson].cnt;
}
void update(int p,int v,int L=0,int R=sz,int o=1)
{
    if(L==R)
    {
        if(v==1)
        {
            T[o].val=0;
            T[o].ls=all[p].first;
            T[o].rs=all[p].first*inv2[1]%mod;
            T[o].cnt=1;
        }
        else{
            T[o].val=0;
            T[o].ls=0;
            T[o].rs=0;
            T[o].cnt=0;
        }
        return;
    }
    int mid=L+R>>1;
    if(p<=mid) update(p,v,Lson);
    else update(p,v,Rson);
    Merge(o);
}
int main()
{
    two[0]=1;
    for(int i=1;i<maxn*2;i++) two[i]=two[i-1]*2%mod;
    inv2[maxn*2-1]=quick(two[maxn*2-1],mod-2);
    for(int i=maxn*2-2;i>=0;i--) inv2[i]=inv2[i+1]*2%mod;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>p[i];
        all.emplace_back(p[i],i);
    }
    int k;
    cin>>k;
    for(int i=0;i<k;i++)
    {
        cin>>q[i].first>>q[i].second;
        all.emplace_back(q[i].second,i+n);
    }
    sort(all.begin(),all.end());
    vi pos(n+k);
    sz=all.size()-1;
    for(int i=0;i<sz+1;i++)
        pos[all[i].second]=i;
    ll ans=0;
    for(int i=0;i<n;i++) update(pos[i],1);
    cout<<T[1].val<<'\n';
    for(int i=n;i<n+k;i++)
    {
        update(pos[q[i-n].first-1],-1);
        pos[q[i-n].first-1]=pos[i];
        update(pos[i],1);
        cout<<T[1].val<<'\n';
    }
}