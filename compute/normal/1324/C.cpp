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
        string s;
        cin>>s;
        int n=s.length();
        vi l(n,-1);
        int cur=-1;
        for(int i=0;i<n;i++)
        {
            l[i]=cur;
            if(s[i]=='R') cur=i;
        }
        int L=1,R=n+1,ans=-1;
        while(L<=R)
        {
            int mid=L+R>>1;
            int pos=mid-1;
            bool ok=1;
            while(pos<n)
            {
                if(s[pos]=='R') pos+=mid;
                else{
                    int lp=l[pos];
                    if(lp==-1||pos-lp>=mid)
                    {
                        //dbg(233);
                        ok=0;
                        break;
                    }
                    pos=lp;
                }
            }
            if(ok)
            {
                R=mid-1;
                ans=mid;
            }
            else L=mid+1;
        }
        assert(ans!=-1);
        print(ans);

    }
}