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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin>>T;
    while(T--)
    {
        int n,m;
        cin>>n>>m;
        vc<vi> need(n+1);
        vi a(n),b(n);
        for(int i=0;i<n;i++) cin>>a[i];
        vi tar(n+1);
        for(int i=0;i<n;i++)
        {
            cin>>b[i];
            tar[b[i]]=1;
            if(a[i]!=b[i]) need[b[i]].push_back(i);
        }
        vi hav(n+1);
        vi c(m);
        for(int i=0;i<m;i++)
        {
            cin>>c[i];
            hav[c[i]]++;
        }
        bool suc=tar[c[m-1]];
        for(int i=1;i<=n;i++)
        {
            if(hav[i]<need[i].size()) suc=0;
        }
        if(!suc) cout<<"NO\n";
        else{
            vi pos(n+1);
            vi ans;
            int tp=-1;
            for(int i=0;i<n;i++)
            {
                if(b[i]==c[m-1]&&a[i]!=b[i])
                {
                    tp=i;
                    break;
                }
            }
            if(tp==-1)
            {
                for(int i=0;i<n;i++)
                {
                    if(b[i]==c[m-1])
                    {
                        tp=i;
                        break;
                    }
                }
            }
            assert(tp!=-1);
            for(int i=0;i<n;i++) pos[b[i]]=i;
            for(int i=0;i<m;i++)
            {
                if(need[c[i]].size())
                {
                    ans.push_back(need[c[i]].back());
                    need[c[i]].pop_back();
                }
                else{
                    ans.push_back(tp);
                }
            }
            for(auto &u:ans) u++;
            cout<<"YES\n";
            print(ans);
        }
    }
}