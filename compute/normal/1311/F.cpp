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
struct D{
    int x,v;
    bool operator<(const D&a)const{
        return x<a.x;
    }
}a[maxn];
ll tree[maxn];
ll cnt[maxn];
void add(int x,int val)
{
    while(x<maxn)
    {
        tree[x]+=val;
        cnt[x]++;
        x+=x&-x;
    }
}
ll query(int x)
{
    ll ret=0;
    while(x)
    {
        ret+=tree[x];
        x-=x&-x;
    }
    return ret;
}
int qcnt(int x)
{
    int ret=0;
    while(x)
    {
        ret+=cnt[x];
        x-=x&-x;
    }
    return ret;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vi all;
    for(int i=0;i<n;i++)
        cin>>a[i].x;
    for(int i=0;i<n;i++)
    {
        cin>>a[i].v;
        all.push_back(a[i].v);
    }
    mkuni(all);
    sort(a,a+n);
    ll ans=0;
    for(int i=0;i<n;i++) a[i].v=lower_bound(all.begin(),all.end(),a[i].v)-all.begin()+1;
    for(int i=0;i<n;i++)
    {
        ans+=1LL*qcnt(a[i].v)*a[i].x-query(a[i].v);
        add(a[i].v,a[i].x);
        //dbg(i,ans);
    }
    print(ans);
    
}