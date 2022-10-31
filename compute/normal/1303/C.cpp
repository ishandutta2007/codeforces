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
        vc<int> vis(26,-1);
        bool ok=1;
        string ans;
        ans+=s[0];
        vis[s[0]-'a']=0;
        int pos=0;
        for(int i=1;i<s.length();i++)
        {
            if(vis[s[i]-'a']==-1)
            {
                if(pos==ans.length()-1)
                {
                    ans+=s[i];
                    vis[s[i]-'a']=++pos;
                }
                else if(pos==0)
                {
                    ans=s[i]+ans;
                    for(int i=0;i<26;i++)
                    {
                        if(vis[i]!=-1) vis[i]++;
                    }
                    vis[s[i]-'a']=0;
                }
                else{
                    ok=0;
                    break;
                }
            }
            else{
                if(vis[s[i]-'a']==pos-1||vis[s[i]-'a']==pos+1)
                    pos=vis[s[i]-'a'];
                else{
                    ok=0;break;
                }
            }
        }
        if(!ok) cout<<"NO\n";
        else{
            cout<<"YES\n";
            for(int i=0;i<26;i++)
            {
                if(vis[i]==-1) ans+='a'+i;
            }
            cout<<ans<<'\n';
        }
    }
}