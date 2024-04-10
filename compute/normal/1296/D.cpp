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
int main()
{
    int n,a,b,k;
    cin>>n>>a>>b>>k;
    vi h(n);
    int ans=0;
    vi rem(n);
    for(int i=0;i<n;i++) 
    {
        cin>>h[i];
        int tmp=h[i];
        h[i]%=a+b;
        if(h[i]==0&&tmp>=a+b) h[i]=a+b;
        h[i]-=a;
        if(h[i]<=0) rem[i]=0;
        else rem[i]=(h[i]+(a-1))/a;
    }
    sort(rem.begin(),rem.end());
    for(int i=0;i<n;i++)
    {
        if(rem[i]>k) break;
        k-=rem[i];
        ans++;
    }
    print(ans);
}