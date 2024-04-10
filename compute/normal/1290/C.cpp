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
const int maxn=6e5+7;
const int INF=0x3f3f3f3f;
int fa[maxn];
int Find(int x)
{
    return x==fa[x]?x:fa[x]=Find(fa[x]);
}
ll sz[maxn];
void Union(int x,int y)
{
    x=Find(x),y=Find(y);
    if(x!=y)
    {
        fa[y]=x;
        sz[x]+=sz[y];
    }
}
vi st[maxn];
int main()
{
    for(int i=0;i<maxn;i++) fa[i]=i;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    for(int i=0;i<k;i++)
    {
        sz[i]=1;
        int c;
        cin>>c;
        for(int j=0,tmp;j<c;j++)
        {
            cin>>tmp;
            tmp--;
            st[tmp].push_back(i);
        }
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        //dbg(i,st[i]);
        if(st[i].size()==0) assert(s[i]=='1');
        else if(st[i].size()==1)
        {
            int tt=st[i][0];
            ans-=min(sz[Find(tt)],sz[Find(tt+k)]);
            if(s[i]=='1') sz[Find(tt)]+=INF;
            else sz[Find(tt+k)]+=INF;
            //dbg(sz[Find(tt)],sz[Find(tt+k)]);
            ans+=min(sz[Find(tt)],sz[Find(tt+k)]);
        }
        else{
            int u=st[i][0],v=st[i][1];
            //dbg(u,v);
            ans-=min(sz[Find(u)],sz[Find(u+k)]);
            if(Find(u)!=Find(v)&&Find(u)!=Find(v+k)) ans-=min(sz[Find(v)],sz[Find(v+k)]);
            if(s[i]=='0')
            {
                Union(u+k,v);
                Union(u,v+k);
            }
            else{
                Union(u,v);
                Union(u+k,v+k);
            }
            ans+=min(sz[Find(u)],sz[Find(u+k)]);
            if(Find(u)!=Find(v)&&Find(u)!=Find(v+k)) ans+=min(sz[Find(v)],sz[Find(v+k)]);
        }
        print(ans);
    }

}