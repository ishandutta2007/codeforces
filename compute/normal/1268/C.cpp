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
const int maxn=2e5+7;
int tree[maxn];
ll dis[maxn];
void add(int x,int v)
{
    int pos=x;
    while(x<maxn)
    {
        dis[x]+=pos;
        tree[x]+=v;
        x+=x&-x;
    }
}
int query(int x)
{
    int ret=0;
    while(x)
    {
        ret+=tree[x];
        x-=x&-x;
    }
    return ret;
}
ll qd(int x)
{
    ll ret=0;
    while(x)
    {
        ret+=dis[x];
        x-=x&-x;
    }
    return ret;
}
int main()
{
    int n;
    cin>>n;
    vi p(n+1);
    vi pos(n+1);
    vc<ll> ans(n);
    ll cur=0;
    for(int i=1;i<=n;i++)
    {
        cin>>p[i];
        pos[p[i]]=i;
    }
    auto getpos=[&](int x)
    {
        int L=1,R=n,ret=-1;
        while(L<=R)
        {
            int mid=L+R>>1;
            if(query(mid)>=x)
            {
                R=mid-1;
                ret=mid;
            }
            else L=mid+1;
        }
        return ret;
    };
    for(int i=1;i<=n;i++)
    {
        cur+=i-1-query(pos[i]);
        add(pos[i],1);
        int pos=getpos((i+1)/2);
        ll LD=qd(pos-1);
        ll lcnt=query(pos-1);
        ll rcnt=i-query(pos);
        ll RD=qd(maxn-1)-qd(pos);
        ans[i-1]=cur+RD-(rcnt*pos)-rcnt*(rcnt+1)/2+lcnt*pos-LD-lcnt*(lcnt+1)/2;
    }
    print(ans);

}