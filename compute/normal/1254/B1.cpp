#include<bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define dbg(x...) do{cout << "\033[32;1m" << #x << "->" ; err(x);} while(0)
void err(){cout << "\033[39;0m" << endl;}
template<template<typename...> class T,typename t,typename... A>
void err(T<t> a,A... x){for (auto v:a) cout << v << ' '; err(x...);}
template<typename T,typename... A>
void err(T a,A... x){cout << a << ' '; err(x...);}
#else
#define dbg(...)
#endif
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<int> vi;
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
const ll INF=0x3f3f3f3f3f3f3f3f;
const int maxn=1e6+7;
int a[maxn];
int rem[maxn];
ll pre[maxn],suf[maxn],cost[maxn];
int main()
{
    int n;
    scanf("%d",&n);
    ll tot=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        tot+=a[i];
    }
    if(tot==1) puts("-1");
    else{
        vector<ll> all;
        for(int i=2;1LL*i*i<=tot;i++)
        {
            if(tot%i==0)
            {
                all.push_back(i);
                while(tot%i==0)
                    tot/=i;
            }
        }
        ll ans=INF;
        if(tot>1) all.push_back(tot);
        for(auto u:all)
        {
            for(int i=0;i<n;i++) rem[i]=a[i]%u;
            ll cur=0;
            int st=0;
            vector<PII> block;
            for(int i=0;i<n;i++)
            {
                cur+=rem[i];
                if(cur>=u)
                {
                    block.push_back(make_pair(st,i));
                    cur%=u;
                    st=i;
                }
            }
            ll curcost=0;
            for(auto v:block)
            {
                //dbg(v.first,v.second);
                int l=v.first,r=v.second;
                pre[l]=rem[l];
                cost[l]=0;
                ll tot=0;
                for(int i=l+1;i<=r;i++)
                {
                    pre[i]=pre[i-1]+rem[i];
                    if(i==r)
                    {
                        tot=pre[i-1]+rem[i];
                        pre[i]=u;
                    }
                    cost[i]=cost[i-1]+pre[i-1];
                    //dbg(i,pre[i],cost[i]);
                }
                suf[r]=rem[r]-(tot-u);
                ll sss=0;
                for(int i=r-1;i>=l;i--)
                {
                    suf[i]=suf[i+1]+rem[i];
                    sss+=suf[i+1];
                    cost[i]+=sss;
                }
                ll mic=INF;
                for(int i=l;i<=r;i++) 
                {
                    mic=min(mic,cost[i]);
                    //dbg(i,cost[i]);
                }
                curcost+=mic;
                rem[r]=tot-u;
            }
            ans=min(ans,curcost);
        }
        printf("%lld\n",ans);
    }
}