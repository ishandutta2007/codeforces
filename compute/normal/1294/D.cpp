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
const int maxn=4e5+7;
#define lson o<<1
#define rson o<<1|1
#define Lson L,mid,lson
#define Rson mid+1,R,rson
pi mx[maxn<<2];
int q,x;
void build(int L=0,int R=x-1,int o=1)
{
    if(L==R)
    {
        mx[o].second=L;
        return;
    }
    int mid=L+R>>1;
    build(Lson);
    build(Rson);
    mx[o]=min(mx[lson],mx[rson]);
}
void add(int p,int L=0,int R=x-1,int o=1)
{
    if(L==R)
    {
        mx[o].first++;
        return;
    }
    int mid=L+R>>1;
    if(p<=mid) add(p,Lson);
    else add(p,Rson);
    mx[o]=min(mx[lson],mx[rson]);
}
int main()
{
    cin>>q>>x;
    build();
    for(int i=0;i<q;i++)
    {
        int y;
        cin>>y;
        y%=x;
        add(y);
        int ans=x*mx[1].first+mx[1].second;
        cout<<ans<<'\n';

    }
}