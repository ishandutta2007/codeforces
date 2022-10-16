#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
using namespace std;
const int MAXN=2e5+10;
int n,m,op[MAXN],x[MAXN],y[MAXN],ans[MAXN],lastans;
map<array<int,2>,int>pre;
struct DSU{
    int fa[MAXN],sz[MAXN];
    vector<array<int,2> >op;
    int find(int x){while(fa[x]!=x)x=fa[x];return x;}
    void merge(int x,int y){
        x=find(x),y=find(y);if(x==y){op.push_back({0,0});return;}
        if(sz[x]<sz[y])swap(x,y);
        op.push_back({x,y});
        fa[y]=x;sz[x]+=sz[y];
    }
    void back(){
        int x=op.back()[0],y=op.back()[1];op.pop_back();if(!x)return;
        fa[y]=y;sz[x]-=sz[y];
    }
}dsu;
vector<array<int,2> >edge[MAXN<<2];
void upd(int x,int l,int r,int ql,int qr,int u,int v){
    if(ql<=l && qr>=r){edge[x].push_back({u,v});return;}
    int mid=(l+r)>>1;
    if(ql<=mid)upd(lc(x),l,mid,ql,qr,u,v);
    if(qr>mid)upd(rc(x),mid+1,r,ql,qr,u,v);
}
void solve(int X,int l,int r){
    int cnt=0;
    for(auto e:edge[X]){
        int x=e[0],y=e[1];
        if(pre[{x,y}]){
            cnt++;
            dsu.merge(x,y);
        }
    }
    if(l==r){
        int u=(x[l]+lastans-1)%n+1,v=(y[l]+lastans-1)%n+1;
        if(u>v)swap(u,v);
        if(op[l]==2)ans[l]=lastans=(dsu.find(u)==dsu.find(v));
        else pre[{u,v}]=pre[{u,v}]^1;
        while(cnt--)dsu.back();
        return;
    }
    int mid=(l+r)>>1;
    solve(lc(X),l,mid);solve(rc(X),mid+1,r);
    while(cnt--)dsu.back();
}
int main(){
    cin>>n>>m;
    rep(i,1,n)dsu.fa[i]=i,dsu.sz[i]=1;
    rep(i,1,m){cin>>op[i]>>x[i]>>y[i];}
    rep(i,1,m){
        if(op[i]==1){
            int x1=x[i]%n+1,y1=y[i]%n+1;if(x1>y1)swap(x1,y1);
            int x2=(x[i]-1)%n+1,y2=(y[i]-1)%n+1;if(x2>y2)swap(x2,y2);
            if(pre.find({x1,y1})!=pre.end())upd(1,1,m,pre[{x1,y1}]+1,i,x1,y1);
            if(pre.find({x2,y2})!=pre.end())upd(1,1,m,pre[{x2,y2}]+1,i,x2,y2);
            pre[{x1,y1}]=i;pre[{x2,y2}]=i;
        }
    }
    for(auto p:pre){
        if(p.second==m)continue;
        upd(1,1,m,p.second+1,m,p.first[0],p.first[1]);
    }
    pre.clear();
    solve(1,1,m);
    rep(i,1,m)if(op[i]==2)cout<<ans[i];
    return 0;
}