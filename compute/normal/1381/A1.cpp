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
    auto rev=[&](char c){
        if(c=='0')return '1';
        else return '0';
    };
    while(T--)
    {
        int n;
        cin>>n;
        string a,b;
        cin>>a>>b;
        vi ans;
        for(int i=n-1;i>=1;i--)
        {
            if(a[i]==b[i])
                continue;
            else{
                if(a[0]!=a[i])
                {
                    ans.push_back(0);
                    a[0]=rev(a[0]);
                }
                ans.push_back(i);
                for(int j=0;j<=i;j++) a[j]=rev(a[j]);
                for(int j=0;j<i;j++)
                {
                    if(j>i-j) break;
                    swap(a[j],a[i-j]);
                }
            }
        }
        if(a[0]!=b[0]) ans.push_back(0);
        for(auto &u:ans) u++;
        print(ans.size(),2);
        print(ans);
        if(!ans.size()) cout<<'\n';
    }
}