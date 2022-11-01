#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int mod=1000000007;
int add(int a,int b){return a+b-(a+b>=mod?mod:0);}
int sub(int a,int b){return a-b+(a-b<0?mod:0);}
int mul(int a,int b){return (ll(a)*b)%mod;}
const int N=200005;
int sz[N];
vector<int> v[N];
vector<array<int,2>> g[N];
vector<bool> vis(N,0);
int lvl[N];
vector<int> ch[N];
vector<int> st[N];
int one[N][18];
int cnt[N][18];
int sum[N][18];
int val[N];

void find_sz(int a,int p)
{
    sz[a]=1;
    for(int to:v[a])
    {
        if(vis[to]||to==p) continue;
        find_sz(to,a);
        sz[a]+=sz[to];
    }
}

int find_centroid(int a,int p,int nnow)
{
    for(int to:v[a])
    {
        if(vis[to]||to==p) continue;
        if(sz[to]>nnow/2) return find_centroid(to,a,nnow);
    }
    return a;
}

void find_d(int a,int p,int l,int e,int o,int c,int s)
{
    if(p!=0)
    {
        one[a][l]=o;
        cnt[a][l]=c;
        sum[a][l]=s;
    }
    for(auto [to,f]:g[a])
    {
        if(vis[to]||to==p) continue;
        if(p==0) find_d(to,a,l,f,f,0,val[to]);
        else find_d(to,a,l,f,o,c+(e!=f),add(s,val[to]));
    }
}

void build_cd(int a,int p)
{
    find_sz(a,0);
    int centroid=find_centroid(a,0,sz[a]);
    ch[p].push_back(centroid);
    if(p!=0) lvl[centroid]=lvl[p]+1;
    else lvl[centroid]=0;
    find_d(centroid,0,lvl[centroid],0,0,0,0);
    vis[centroid]=1;
    for(int to:v[centroid]) if(!vis[to]) build_cd(to,centroid);
}

array<int,2> operator+(const array<int,2> &a,const array<int,2> &b){return {a[0]+b[0],add(a[1],b[1])};}
array<int,2> operator-(const array<int,2> &a,const array<int,2> &b){return {a[0]-b[0],sub(a[1],b[1])};}

struct ST
{
    int n;
    vector<array<int,2>> tree;
    void ini(int _n)
    {
        n=_n;
        tree.assign(4*(n+5),{0,0});
    }
    void update(int idx,int l,int r,int pos,array<int,2> x,bool tp)
    {
        if(l==r)
        {
            if(tp==1) tree[idx]=tree[idx]+x;
            else tree[idx]=tree[idx]-x;
        }
        else
        {
            int m=(l+r)/2;
            if(pos<=m) update(2*idx,l,m,pos,x,tp);
            else update(2*idx+1,m+1,r,pos,x,tp);
            tree[idx]=tree[2*idx]+tree[2*idx+1];
        }
    }
    void upd(int pos,array<int,2> x,bool tp){update(1,0,n,pos,x,tp);}
    array<int,2> query(int idx,int l,int r,int ql,int qr)
    {
        if(ql>qr) return {0,0};
        if(l==ql&&r==qr) return tree[idx];
        int m=(l+r)/2;
        return query(2*idx,l,m,ql,min(qr,m))+query(2*idx+1,m+1,r,max(ql,m+1),qr);
    }
    array<int,2> qry(int ql,int qr){return query(1,0,n,ql,qr);}
};

int n,k;
vector<ST> tree(2);
int res=0;

void go(int a)
{
    int l=lvl[a];
    st[a].push_back(a);
    for(int b:ch[a])
    {
        go(b);
        for(int to:st[b]) st[a].push_back(to);
    }
    for(int b:ch[a])
    {
        for(int to:st[b])
        {
            if(cnt[to][l]<=k) res=add(res,add(val[a],sum[to][l]));
            int o=one[to][l];
            for(int e=0;e<2;e++)
            {
                auto [c,s]=tree[e].qry(0,k-cnt[to][l]-(e!=o));
                res=add(res,s);
                res=add(res,mul(c,add(val[a],sum[to][l])));
            }
        }
        for(int to:st[b])
        {
            tree[one[to][l]].upd(cnt[to][l],{1,sum[to][l]},1);
        }
    }
    for(int b:ch[a])
    {
        for(int to:st[b]) tree[one[to][l]].upd(cnt[to][l],{1,sum[to][l]},0);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(int i=1;i<=n;i++) cin >> val[i];
    for(int i=1;i<=n-1;i++)
    {
        int a,b,e;
        cin >> a >> b >> e;
        v[a].push_back(b);
        v[b].push_back(a);
        g[a].push_back({b,e});
        g[b].push_back({a,e});
    }
    build_cd(1,0);
    for(int i=0;i<2;i++) tree[i].ini(n);
    go(ch[0][0]);
    for(int i=1;i<=n;i++) res=add(res,val[i]);
    cout << res << "\n";
    return 0;
}