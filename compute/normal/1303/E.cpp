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
        string t;
        cin>>s>>t;
        string t1,t2;
        int var=s.length()+1;
        vc<vi> nxt(s.length()+2,vi(26,var));
        vi cur(26,var);
        for(int i=s.length()-1;i>=0;i--)
        {
            for(int j=0;j<26;j++)
                nxt[i+1][j]=cur[j];
            cur[s[i]-'a']=i+1;
        }
        for(int j=0;j<26;j++) nxt[0][j]=cur[j];
        bool ok=0;
        for(int len=1;len<=t.length();len++)
        {
            t1=t.substr(0,len);
            t2=t.substr(len,t.length()-len);
            //dbg(t1);
            //dbg(t2);
            vc<vi> dp(t1.length()+1,vi(t2.length()+1,var));
            dp[0][0]=0;
            for(int i=0;i<=t1.length();i++)
            {
                for(int j=0;j<=t2.length();j++)
                {
                    int pos=dp[i][j];
                    if(i!=t1.length())
                        dp[i+1][j]=min(dp[i+1][j],nxt[pos][t1[i]-'a']);
                    if(j!=t2.length())
                        dp[i][j+1]=min(dp[i][j+1],nxt[pos][t2[j]-'a']);
                    //dbg(i,j,dp[i][j]);
                }
            }
            if(dp[t1.length()][t2.length()]!=var)
            {
                ok=1;
                break;
            }
        }
        if(ok) cout<<"YES\n";
        else cout<<"NO\n";
    }
}