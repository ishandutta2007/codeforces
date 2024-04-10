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
const int maxn=2e5+7;
int dp[maxn][1<<8];
vi Event[maxn];
int id[maxn];
struct seg{
    int l,r,id;
    bool operator<(const seg& a)const{
        if(l==a.l) return r<a.r;
        return l<a.l;
    }
}s[maxn];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m,k;
    cin>>n>>m>>k;
    vi all;
    for(int i=0;i<n;i++)
    {
        cin>>s[i].l>>s[i].r;
        all.push_back(s[i].l);
        all.push_back(s[i].r+1);
    }
    mkuni(all);
    sort(s,s+n);
    auto getid=[&](int x){return lower_bound(all.begin(),all.end(),x)-all.begin()+1;};
    for(int i=0;i<n;i++)
    {
        s[i].l=getid(s[i].l);
        s[i].r=getid(s[i].r+1);
        s[i].id=i;
        Event[s[i].l].push_back(i);
        Event[s[i].r].push_back(i);
    }
    memset(dp,-0x3f,sizeof(dp));
    int inf=dp[0][0];
    dp[0][0]=0;
    int curS=0;
    for(int i=1;i<=all.size();i++)
    {
        int out=0;
        int in=0;
        for(auto u:Event[i])
        {
            if(s[u].r==i)
            {
                out|=1<<id[u];
                curS-=1<<id[u];
            }
            else{
                id[u]=-1;
                for(int j=0;j<k;j++)
                {
                    if(!(curS>>j&1))
                    {
                        id[u]=j;
                        break;
                    }
                }
                assert(id[u]!=-1);
                in|=1<<id[u];
                curS|=1<<id[u];
            }
        }
        //dbg(i,all[i-1],in,out);
        for(int S=0;S<(1<<k);S++)
        {
            if(dp[i-1][S]==inf) continue;
            //dbg(i,S,dp[i-1][S]);
            int nxt=S;
            int cc=0;
            for(int i=0;i<k;i++)
            {
                if(nxt>>i&1)
                {
                    if(out>>i&1) nxt^=(1<<i);
                }
                cc+=S>>i&1;
            }
            if(i>1)
                dp[i][nxt]=max(dp[i][nxt],dp[i-1][S]+(cc&1?all[i-1]-all[i-2]:0));
            else dp[i][S]=dp[i-1][S];
        }
        for(int S=0;S<(1<<k);S++)
        {
            if(dp[i][S]==inf) continue;
            //dbg(i,S,dp[i][S]);
            for(int j=0;j<k;j++)
            {
                if(in>>j&1)
                    dp[i][S|(1<<j)]=max(dp[i][S|(1<<j)],dp[i][S]);
            }
        }
    }
    cout<<dp[all.size()][0]<<'\n';

}