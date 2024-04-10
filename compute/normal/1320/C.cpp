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
const int maxn=2e5+7;
const int maxv=1e6+7;
struct Ds{
    int v,cv;
}a[maxn];
struct Event{
    int x,y,v;
    bool operator<(const Event &a)const{
        if(x==a.x)  return y<a.y;
        return x<a.x;
    }
};
#define lson o<<1
#define rson o<<1|1
#define Lson L,mid,lson
#define Rson mid+1,R,rson
struct D{
    ll lz,mx;
    D(ll v=-0x3f3f3f3f3f3f3f3f):lz(0),mx(v){}
    inline void add(ll v)
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
        return D(max(x.mx,y.mx));
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
    ll query(int l,int r,int L=0,int R=sz-1,int o=1)
    {
        if(l<=L&&r>=R)
            return tree[o].mx;
        push(o);
        int mid=L+R>>1;
        ll ret=-0x3f3f3f3f3f3f3f3f;
        if(l<=mid) ret=max(ret,query(l,r,Lson));
        if(r>mid) ret=max(ret,query(l,r,Rson));
        return ret;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m,p;
    cin>>n>>m>>p;
    vc<Event> all;
    for(int i=0,v,cv;i<n;i++)
    {
        cin>>v>>cv;
        all.push_back(Event{v,-1,cv});
    }
    vc<ll> val(maxv,-0x3f3f3f3f3f3f3f3f);
    for(int i=0;i<m;i++)
    {
        cin>>a[i].v>>a[i].cv;
        val[a[i].v]=max(val[a[i].v],-1LL*a[i].cv);
    }
    sgt<D> seg(val);
    for(int i=0,x,y,z;i<p;i++)
    {
        cin>>x>>y>>z;
        all.push_back(Event{x,y,z});
    }
    sort(all.begin(),all.end());
    ll ans=-0x3f3f3f3f3f3f3f3f;
    for(auto u:all)
    {
        //dbg(u.x,u.y,u.v);
        if(u.y==-1)
            ans=max(ans,seg.query(1,maxv-1)-u.v);
        else{
            seg.add(u.y+1,maxv-1,u.v);
        }
    }
    print(ans);
}