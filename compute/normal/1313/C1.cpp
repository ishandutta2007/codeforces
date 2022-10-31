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
const int maxn=5e5+7;

ll lose[maxn];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vi m(n);
    vc<ll> pre(n);
    for(int i=0;i<n;i++)
    {
        cin>>m[i];
        if(i) pre[i]=pre[i-1]+m[i];
        else pre[i]=m[i];
    }
    int tar=0;
    {
        ll cur=0;
        stack<int> st;
        for(int i=0;i<n;i++)
        {
            while(!st.empty()&&m[i]<=m[st.top()])
            {
                int v=st.top();
                st.pop();
                if(st.empty()) cur=0;
                else{
                    int u=st.top();
                    cur-=pre[v-1]-pre[u]-(ll)(v-1-u)*m[v];
                }
            }
            if(!st.empty())
            {
                int pp=st.top();
                cur+=pre[i-1]-pre[pp]-(ll)(i-1-pp)*m[i];
            }
            else if(i)
                cur+=pre[i-1]-(ll)i*m[i];
            st.push(i);
            //dbg(cur);
            lose[i]+=cur;
        }
    }
    {
        ll cur=0;
        stack<int> st;
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty()&&m[i]<=m[st.top()])
            {
                int v=st.top();
                st.pop();
                if(st.empty()) cur=0;
                else{
                    int u=st.top();
                    cur-=pre[u-1]-pre[v]-(ll)(u-v-1)*m[v];
                }
            }
            if(!st.empty())
            {
                int pp=st.top();
                cur+=pre[pp-1]-pre[i]-(ll)(pp-i-1)*m[i];
            }
            else if(i!=n-1) cur+=pre[n-1]-pre[i]-(ll)(n-1-i)*m[i];
            st.push(i);
            lose[i]+=cur;
            //dbg(i,lose[i]);
        }
    }
    ll opt=lose[0];
    for(int i=0;i<n;i++)
    {
        if(lose[i]<opt)
        {
            opt=lose[i];
            tar=i;
        }
    }
    for(int i=tar-1;i>=0;i--)
        m[i]=min(m[i],m[i+1]);
    for(int i=tar+1;i<n;i++)
        m[i]=min(m[i],m[i-1]);
    print(m);
    
}