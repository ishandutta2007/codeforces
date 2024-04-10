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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        vi a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        vi all;
        for(int i=0;i<n;i++)
        {
            if(a[i]==-1)
            {
                if(i&&a[i-1]!=-1) all.push_back(a[i-1]);
                if(i!=n-1&&a[i+1]!=-1) all.push_back(a[i+1]);
            }
        }
        if(!all.size())
        {
            cout<<0<<" "<<0<<'\n';
            continue;
        }
        mkuni(all);
        int tar=(*all.begin()+*all.rbegin())/2;
        for(int i=0;i<n;i++) if(a[i]==-1) a[i]=tar;
        int m=0;
        for(int i=1;i<n-1;i++) m=max({m,abs(a[i]-a[i-1]),abs(a[i]-a[i+1])});
        cout<<m<<" "<<tar<<'\n';
    }
}