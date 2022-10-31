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
    int T;
    cin>>T;
    while(T--)
    {
        int n,m;
        cin>>n>>m;
        vi a(n+1);
        vi vis(n+2);
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1,p;i<=m;i++)
        {
            cin>>p;
            vis[p]=1;
        }
        int pre=1;
        int p=1;
        for(int i=1;i<=n;i++)
        {
            if(!vis[i])
            {
                if(pre!=i)
                    sort(a.begin()+pre,a.begin()+i+1);
                pre=i+1;
            }
            //dbg(i,a);
        }
        bool ok=1;
        for(int i=1;i<n;i++)
        {
            if(a[i]>a[i+1]) ok=0;
        }
        if(ok) cout<<"YES\n";
        else cout<<"NO\n";
    }
}