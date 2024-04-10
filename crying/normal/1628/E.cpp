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
const int MAXN=6e5+10,INF=2e9;
int n,q;
struct Edge{
    int u,v,w;
    bool operator<(const Edge& e2)const{return w<e2.w;}
}edge[MAXN];
int fa[MAXN],val[MAXN];
int lc[MAXN],rc[MAXN];
int dfn[MAXN],f[MAXN][20],ord[MAXN],dfntot,depth[MAXN];
int Find(int x){
    if(fa[x]==x)return x;
    return fa[x]=Find(fa[x]);
}
void dfs(int u){
    rep(j,1,19)f[u][j]=f[f[u][j-1]][j-1];
    depth[u]=depth[f[u][0]]+1;
    if(lc[u])dfs(lc[u]);
    dfn[u]=++dfntot;ord[dfntot]=u;
    if(rc[u])dfs(rc[u]);
}
int LCA(int x,int y){
    if(depth[x]<depth[y])swap(x,y);
    per(j,19,0){
        if(depth[x]-(1<<j)>=depth[y])x=f[x][j];
    }
    if(x==y)return x;
    per(j,19,0){
        if(f[x][j]!=f[y][j])x=f[x][j],y=f[y][j];
    }
    return f[x][0];
}
int minst[MAXN][20],maxst[MAXN][20],logn[MAXN];
int qrymin(int l,int r){
    int len=logn[r-l+1];
    return min(minst[l][len],minst[r-(1<<len)+1][len]);
}
int qrymax(int l,int r){
    int len=logn[r-l+1];
    return max(maxst[l][len],maxst[r-(1<<len)+1][len]);
}
void upd(pi& p1,pi p2){
    p1.fr=min(p1.fr,p2.fr);
    p1.se=max(p1.se,p2.se);
}
struct seg{
    int minn[MAXN<<2],maxn[MAXN<<2],tag[MAXN<<2];
    void pushup(int x){
        minn[x]=min(minn[lc(x)],minn[rc(x)]);
        maxn[x]=max(maxn[lc(x)],maxn[rc(x)]);
    }
    void pushdown(int x,int l,int r){
        if(tag[x]==0)return;
        if(tag[x]==-1){ //
            minn[lc(x)]=minn[rc(x)]=INF;
            maxn[lc(x)]=maxn[rc(x)]=-INF;
            tag[lc(x)]=tag[rc(x)]=-1;tag[x]=0;
        }else if(tag[x]==1){ //
            int mid=(l+r)>>1;
            minn[lc(x)]=qrymin(l,mid);
            minn[rc(x)]=qrymin(mid+1,r);
            maxn[lc(x)]=qrymax(l,mid);
            maxn[rc(x)]=qrymax(mid+1,r);
            tag[lc(x)]=tag[rc(x)]=1;tag[x]=0;
        }
    }
    void remove(int x,int l,int r,int ql,int qr){
        if(ql<=l && qr>=r){
            minn[x]=INF;
            maxn[x]=-INF;
            tag[x]=-1;
            return;
        }
        pushdown(x,l,r);
        int mid=(l+r)>>1;
        if(ql<=mid)remove(lc(x),l,mid,ql,qr);
        if(qr>mid)remove(rc(x),mid+1,r,ql,qr);
        pushup(x);
    }
    void cover(int x,int l,int r,int ql,int qr){
        if(ql<=l && qr>=r){
            minn[x]=qrymin(l,r);
            maxn[x]=qrymax(l,r);
            tag[x]=1;
            return;
        }
        pushdown(x,l,r);
        int mid=(l+r)>>1;
        if(ql<=mid)cover(lc(x),l,mid,ql,qr);
        if(qr>mid)cover(rc(x),mid+1,r,ql,qr);
        pushup(x);
    }
    void build(int x,int l,int r){
        if(l==r){minn[x]=INF;maxn[x]=-INF;return;}
        int mid=(l+r)>>1;
        build(lc(x),l,mid);build(rc(x),mid+1,r);
        pushup(x);
    }
}t;
void solve(int x){
    int minn=t.minn[1],maxn=t.maxn[1],ret=-1;
    if(minn!=INF){
        int p=ord[minn];
        p=LCA(p,x);
        if(p!=x)ret=max(ret,val[p]);
    }
    if(maxn!=-INF){
        int p=ord[maxn];
        p=LCA(p,x);
        if(p!=x)ret=max(ret,val[p]);
    }
    printf("%d\n",ret);
}
int main(){
    logn[0]=-1;rep(i,1,300000)logn[i]=logn[i>>1]+1;
    scanf("%d%d",&n,&q);
    rep(i,1,n+n-1){
        fa[i]=i;
    }
    rep(i,1,n-1){
        scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);
    }
    sort(edge+1,edge+n);
    rep(i,1,n-1){
        val[n+i]=edge[i].w;
        int a=Find(edge[i].u),b=Find(edge[i].v);
        fa[a]=fa[b]=n+i;
        lc[n+i]=a;rc[n+i]=b;
        f[a][0]=f[b][0]=n+i;
    }
    n=n*2-1;
    dfs(n);
    rep(i,1,n)minst[i][0]=maxst[i][0]=dfn[i];
    rep(j,1,19){
        rep(i,1,(n+1)/2){
            if(i+(1<<j)-1>(n+1)/2)break;
            minst[i][j]=min(minst[i][j-1],minst[i+(1<<(j-1))][j-1]);
            maxst[i][j]=max(maxst[i][j-1],maxst[i+(1<<(j-1))][j-1]);
        }
    }
    t.build(1,1,(n+1)/2);
    rep(i,1,q){
        int op,l,r;
        scanf("%d",&op);
        if(op==1){
            scanf("%d%d",&l,&r);
            t.cover(1,1,(n+1)/2,l,r);
        }else if(op==2){
            scanf("%d%d",&l,&r);
            t.remove(1,1,(n+1)/2,l,r);
        }else{
            scanf("%d",&op);
            solve(op);
        }
    }
    return 0;
}