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
const int maxn=1e6+7;
struct node{
    int sz,id;
    int ch[26];
}rt[maxn];
int tot=1;
int ans[maxn];
void Insert(int p,int c,int id)
{
    assert(tot==id);
    if(!rt[p].ch[c]) rt[p].ch[c]=tot++;
    rt[rt[p].ch[c]].id=id;
}
#define lson o<<1
#define rson o<<1|1
#define Lson L,mid,lson
#define Rson mid+1,R,rson
struct D{
    int lz,mx;
    D(int v=0):lz(0),mx(v){}
    inline void add(int v)
    {
        lz+=v;
        mx+=v;
    }
    inline void push(D &x,D &y)
    {
        x.add(lz);
        y.add(lz);
        lz=0;
    }
    static D merge(D &x,D &y)
    {
        return D(min(x.mx,y.mx));
    }
};
int sz;
template<class D>
struct sgt{
    vc<D> tree;
    sgt(){}
    template<class T>
    sgt(const vc<T>& a)
    {
        int n=a.size();
        sz=1;
        while(sz<n) sz*=2;
        tree.resize(sz*2);
        for(int i=0;i<n;i++) tree[sz+i]=D(a[i]);
        for(int i=sz-1;i>=1;i--) upd(i);
    }
    inline void push(int o)
    {
        tree[o].push(tree[lson],tree[rson]);
    }
    inline void upd(int o)
    {
        tree[o]=D::merge(tree[lson],tree[rson]);
    }
    void ch(int p,int val,int L=0,int R=sz-1,int o=1)
    {
        if(L==R)
        {
            tree[o].mx=val;
            return;
        }
        push(o);
        int mid=L+R>>1;
        if(p<=mid) ch(p,val,Lson);
        else ch(p,val,Rson);
        upd(o);
    }
    void add(int l,int r,int val,int L=0,int R=sz-1,int o=1)
    {
        if(l<=L&&r>=R)
        {
            tree[o].add(val);
            return;
        }
        push(o);
        int mid=L+R>>1;
        if(l<=mid) add(l,r,val,Lson);
        if(r>mid) add(l,r,val,Rson);
        upd(o);
    }
    int query(int l,int r,int L=0,int R=sz-1,int o=1)
    {
        if(l<=L&&r>=R)
            return tree[o].mx;
        push(o);
        int mid=L+R>>1;
        int ret=0x3f3f3f3f;
        if(l<=mid) ret=min(ret,query(l,r,Lson));
        if(r>mid) ret=min(ret,query(l,r,Rson));
        return ret;
    }
};
sgt<D> segdis,segsz;
void dfs(int u,int dis=0)
{
    if(dis)
    {
        segdis.add(0,dis-1,1);
        int cur=segdis.query(0,dis-1);
        if(rt[u].sz)
            cur=min(cur,segsz.query(0,dis-1)+1);
        if(rt[u].id)
            ans[rt[u].id]=cur;
        segdis.ch(dis,cur);
        segsz.ch(dis,cur);
        if(rt[u].sz)
            segsz.add(0,dis,1);
        //dbg(u,cur);
    }
    int tot=rt[u].sz;
    for(int i=0;i<26;i++)
    {
        int v=rt[u].ch[i];
        if(v)
        {
            dfs(v,dis+1);
            rt[u].sz+=rt[v].sz;
            segsz.add(0,dis,rt[v].sz);
            tot+=rt[v].sz;
        }
    }
    segsz.add(0,dis,-tot);
    if(dis)
        segdis.add(0,dis-1,-1);
}
int main()
{
    int n;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int p;
        string c;
        cin>>p>>c;
        Insert(p,c[0]-'a',i+1);
    }
    segdis=sgt<D>(vi(n+1));
    segsz=sgt<D>(vi(n+1));
    int k;
    cin>>k;
    vi a(k);
    for(int i=0;i<k;i++)
    {
        cin>>a[i];
        rt[a[i]].sz++;
    }
    dfs(0);
    for(int i=0;i<k;i++) cout<<ans[a[i]]<<' ';
    cout<<'\n';

}