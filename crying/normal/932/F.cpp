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
const ll MAXN=2e5+10,ADD=1e5+1,LIM=2e5+1,INF=1e18;
int n,a[MAXN],b[MAXN];
int rt[MAXN],tot;
ll dp[MAXN];
vector<int>e[MAXN];
struct Node{int lc,rc,idx;}tree[MAXN*20];
ll calc(ll x,int idx){if(idx==0)return INF;return b[idx]*(x-ADD)+dp[idx];}
void seg_upd(int& x,int l,int r,int idx){
    if(!x){x=++tot;tree[x].idx=idx;return;}
    int mid=(l+r)>>1;
    if(calc(mid,idx)<calc(mid,tree[x].idx))swap(idx,tree[x].idx);
    if(l==r)return;
    if(calc(l,idx)<calc(l,tree[x].idx))seg_upd(tree[x].lc,l,mid,idx);
    if(calc(r,idx)<calc(r,tree[x].idx))seg_upd(tree[x].rc,mid+1,r,idx);
}
int seg_merge(int x,int y,int l,int r){
    if(!x || !y)return x+y;
    int mid=(l+r)>>1;
    if(l==r){return calc(l,tree[x].idx)<calc(l,tree[y].idx?x:y);}
    tree[x].lc=seg_merge(tree[x].lc,tree[y].lc,l,mid);
    tree[x].rc=seg_merge(tree[x].rc,tree[y].rc,mid+1,r);
    if(tree[y].idx){seg_upd(x,l,r,tree[y].idx);}
    return x;
}
void seg_qry(int x,int l,int r,int pos,ll& ans){
    if(!x)return;
    ans=min(ans,calc(pos,tree[x].idx));
    if(l==r)return;
    int mid=(l+r)>>1;
    if(pos<=mid)seg_qry(tree[x].lc,l,mid,pos,ans);
    else seg_qry(tree[x].rc,mid+1,r,pos,ans);
}
void dfs(int u,int fa){
    int tag=0;
    for(auto v:e[u])if(v!=fa){
        tag=1;dfs(v,u);
        rt[u]=seg_merge(rt[u],rt[v],1,LIM);
    }
    if(tag)dp[u]=INF,seg_qry(rt[u],1,LIM,a[u]+ADD,dp[u]);
    seg_upd(rt[u],1,LIM,u);
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    rep(i,1,n)cin>>a[i];
    rep(i,1,n)cin>>b[i];
    rep(i,1,n-1){
        int u,v;cin>>u>>v;
        e[u].push_back(v);e[v].push_back(u);
    }
    dfs(1,0);
    rep(i,1,n)cout<<dp[i]<<' ';cout<<endl;
    return 0;
}