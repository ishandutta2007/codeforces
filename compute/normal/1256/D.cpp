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
    int q;
    cin>>q;
    while(q--)
    {
        int n;
        ll k;
        cin>>n>>k;
        string s;
        cin>>s;
        int cc=0,rem=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='0')
            {
                if(k>=i-cc)
                {
                    k-=i-cc;
                    cc++;
                }
                else{
                    rem=i-cc-k;
                    break;
                }
            }
        }
        //dbg(cc,rem);
        string ans;
        for(int i=0;i<cc;i++) ans+='0';
        if(rem)
        {
            for(int j=0;j<rem;j++) ans+='1';
            ans+='0';
            cc++;
        }
        for(int i=0;i<n;i++)
        {
            if(s[i]=='0')
            {
                if(cc) cc--;
                else ans+='0';
            }
            else{
                if(rem) rem--;
                else ans+='1';
            }
        }
        cout<<ans<<'\n';
    }
}