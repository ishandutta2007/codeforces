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
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n,x,y;
        cin>>n>>x>>y;
        if(x<y) swap(x,y);
        int mx=min(y-1,n-x)+min(x-1,n-y)+1+min(max(0,y-1-(n-x)),max(0,x-1-(n-y)));
        int mi=0;
        int rx=0,ry=0;
        if(n-x>1)
        {
            mi+=min(y-1,n-x-1);
            rx=n-x-min(y-1,n-x-1);
        }
        else if(n-x==1) rx=1;
        if(n-y>1)
        {
            mi+=min(x-1,n-y-1);
            ry=n-y-min(x-1,n-y-1);
        }
        else if(n-y==1) ry=1;
        //dbg(rx,ry);
        mi+=min(rx,ry);
        mi=n-mi;
        cout<<mi<<" "<<mx<<'\n';
    }
}