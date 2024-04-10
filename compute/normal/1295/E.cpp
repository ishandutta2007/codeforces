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
ll mx[maxn<<2];
ll pre[maxn];
ll lz[maxn<<2];
#define lson o<<1
#define rson o<<1|1
#define Lson L,mid,lson
#define Rson mid+1,R,rson
int n;
void build(int L=0,int R=n,int o=1)
{
    if(L==R)
    {
        mx[o]=pre[L];
        return;
    }
    int mid=L+R>>1;
    build(Lson);
    build(Rson);
    mx[o]=min(mx[lson],mx[rson]);
}
inline void pushdown(int o)
{
    if(lz[o])
    {
        lz[lson]+=lz[o];
        lz[rson]+=lz[o];
        mx[lson]+=lz[o];
        mx[rson]+=lz[o];
        lz[o]=0;
    }
}
void add(int l,int r,int val,int L=0,int R=n,int o=1)
{
    if(l<=L&&r>=R)
    {
        mx[o]+=val;
        lz[o]+=val;
        return;
    }
    pushdown(o);
    int mid=L+R>>1;
    if(l<=mid) add(l,r,val,Lson);
    if(r>mid) add(l,r,val,Rson);
    mx[o]=min(mx[lson],mx[rson]);
}
int main()
{
    cin>>n;
    vi p(n);
    vi a(n),v(n+1);
    for(int i=0;i<n;i++) 
    {
        cin>>p[i];
    }
    for(int i=0;i<n;i++) 
    {
        cin>>a[i];
        v[p[i]]=a[i];
    }
    for(int i=1;i<=n;i++) pre[i]=pre[i-1]+v[i];
    build();
    ll ans=0x3f3f3f3f3f3f3f3f;
    for(int i=0;i<n-1;i++)
    {
        add(0,p[i]-1,a[i]);
        add(p[i],n,-a[i]);
        ans=min(ans,mx[1]);
        //dbg(i);
        //for(int j=0;j<n;j++) dbg()
    }
    print(ans);
    
}