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
        string s,t;
        cin>>s>>t;
        vc<vi> nxt(s.length(),vi(26,-1));
        vi cur(26,-1);
        for(int i=s.length()-1;i>=0;i--)
        {
            for(int j=0;j<26;j++) nxt[i][j]=cur[j];
            cur[s[i]-'a']=i;
        }
        int p=-1;
        int ans=0;
        for(int j=0;j<t.length();j++)
        {
            if(p==-1)
            {
                int nn=cur[t[j]-'a'];
                //dbg(j,nn);
                if(nn==-1)
                {
                    ans=-1;
                    break;
                }
                ans++;
                p=nn;
            }
            else {
                p=nxt[p][t[j]-'a'];
                if(p==-1) j--;
            }
        }
        cout<<ans<<'\n';
    }
}