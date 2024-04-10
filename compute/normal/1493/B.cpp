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
int rev[]={0,1,5,-1,-1,2,-1,-1,8,-1};
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int h,m;
        scanf("%d%d",&h,&m);
        int ch,cm;
        scanf("%d:%d",&ch,&cm);
        auto nxt=[&](){
            cm++;
            if(cm==m)cm=0,ch++;
            if(ch==h) ch=0;
        };
        auto check=[&](){
            int rh,rm;
            if(rev[cm%10]==-1||rev[cm/10%10]==-1) return false;
            if(rev[ch%10]==-1||rev[ch/10%10]==-1) return false;
            rh=rev[cm%10]*10+rev[cm/10%10];
            rm=rev[ch%10]*10+rev[ch/10%10];
            if(rh>=h||rm>=m) return false;
            return true;
        };
        while(!check()) nxt();
        printf("%02d:%02d\n",ch,cm);
    }
}