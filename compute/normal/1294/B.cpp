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
    int R;
    cin>>R;
    while(R--)
    {
        int n;
        cin>>n;
        vc<pi> pk(n);
        for(int i=0;i<n;i++) cin>>pk[i].first>>pk[i].second;
        sort(pk.begin(),pk.end());
        string ans;
        bool ok=1;
        pi cur={0,0};
        for(auto u:pk)
        {
            if(u.second<cur.second)
            {
                ok=0;
                break;
            }
            while(cur.first<u.first)
            {
                ans+='R';
                cur.first++;
            }
            while(cur.second<u.second)
            {
                ans+='U';
                cur.second++;
            }
        }
        if(ok)
        {
            cout<<"YES\n";
            cout<<ans<<'\n';
        }
        else{
            cout<<"NO\n";
        }
    }
}