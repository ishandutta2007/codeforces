#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
#define next Cry_For_theMoon
#define il inline
#define pb(x) push_back(x)
#define is(x) insert(x)
#define sit set<int>::iterator
#define mapit map<int,int>::iterator
#define pi pair<int,int>
#define ppi pair<int,pi>
#define pp pair<pi,pi>
#define fr first
#define se second
#define vit vector<int>::iterator
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double db;
using namespace std;
const int MAXN=2e5+10;
int n;
int fa[MAXN],depth[MAXN],sz[MAXN],son[MAXN];
int dfn[MAXN],ord[MAXN],top[MAXN],dfntot;
int faw[MAXN],u[MAXN],v[MAXN],tag[MAXN];
vector<int>e[MAXN],ans;
void dfs1(int u){
    depth[u]=depth[fa[u]]+1;
    sz[u]=1;
    for(auto v:e[u]){
        if(v==fa[u])continue;
        fa[v]=u;
        dfs1(v);
        sz[u]+=sz[v];
        if(!son[u] || sz[son[u]]<sz[v])son[u]=v;
    }
}
void dfs2(int u,int node){
    dfn[u]=++dfntot;ord[dfntot]=u;top[u]=node;
    if(son[u])dfs2(son[u],node);
    for(auto v:e[u]){
        if(v==fa[u] || v==son[u])continue;
        dfs2(v,v);
    }
}
void dfs3(int u){
    if(!tag[u])sz[u]=0;
    else sz[u]=1;
    for(auto v:e[u]){
        if(v==fa[u])continue;
        dfs3(v);
        sz[u]+=sz[v];
    }
}
ll sum[MAXN];
struct SegmenTree{
    ll t[MAXN<<2],cnt[MAXN<<2],tag[MAXN<<2];
    void pushup(int x){
        t[x]=t[lc(x)]+t[rc(x)];
        cnt[x]=cnt[lc(x)]+cnt[rc(x)];
    }
    void rev(int x,int l,int r){
        cnt[x]=(r-l+1)-cnt[x];
        t[x]=(sum[r]-sum[l-1])-t[x];
    }
    void pushdown(int x,int l,int r){
        if(!tag[x])return;
        int mid=(l+r)>>1;
        rev(lc(x),l,mid);rev(rc(x),mid+1,r);
        tag[lc(x)]^=1;tag[rc(x)]^=1;tag[x]^=1;
    }
    void upd(int x,int l,int r,int ql,int qr){
        if(ql<=l && qr>=r){rev(x,l,r);tag[x]^=1;return;}
        pushdown(x,l,r);int mid=(l+r)>>1;
        if(ql<=mid)upd(lc(x),l,mid,ql,qr);
        if(qr>mid)upd(rc(x),mid+1,r,ql,qr);
        pushup(x);
    }
}t;
void upd(int u){
    tag[u]=1;
    while(u){
        t.upd(1,1,n,dfn[top[u]],dfn[u]);
        u=fa[top[u]];
    }
}
int main(){
    scanf("%d",&n);
    rep(i,1,n-1){
        scanf("%d%d",&u[i],&v[i]);
        e[u[i]].pb(v[i]);e[v[i]].pb(u[i]);
    }
    dfs1(1);
    dfs2(1,1);
    rep(i,1,n-1)if(fa[v[i]]==u[i])faw[v[i]]=i;else faw[u[i]]=i;
    rep(i,1,n)sum[i]=sum[i-1]+faw[ord[i]];
    t.upd(1,1,n,1,1);tag[1]=1;
    int cnt=1;
    while(1){
        int op;scanf("%d",&op);
        assert(op>0);
        if(op==3)return 0;
        if(op==1){
            int u;scanf("%d",&u);cnt++;
            upd(u);
            if(even(cnt) && cnt/2==t.cnt[1]){
                printf("%lld\n",t.t[1]);
            }else{  
                printf("0\n");
            }
            fflush(stdout);
        }else{
            if(even(cnt) && cnt/2==t.cnt[1]){
                ans.clear();
                dfs3(1);
                rep(i,1,n)if(tag[i] && odd(sz[i]))ans.pb(faw[i]);
                sort(ans.begin(),ans.end());
                printf("%d ",ans.size());for(auto u:ans)printf("%d ",u);printf("\n");
            }else{  
                printf("0\n");
            }
            fflush(stdout);
        }
    }

    return 0;
}