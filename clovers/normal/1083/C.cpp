/*
the vast starry sky,
bright for those who chase the light.
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define mk make_pair
const int inf=(int)1e9;
const ll INF=(ll)5e18;
const int MOD=998244353;
int _abs(int x){return x<0 ? -x : x;}
int add(int x,int y){x+=y; return x>=MOD ? x-MOD : x;}
int sub(int x,int y){x-=y; return x<0 ? x+MOD : x;}
#define mul(x,y) (ll)(x)*(y)%MOD
void Add(int &x,int y){x+=y; if(x>=MOD) x-=MOD;}
void Sub(int &x,int y){x-=y; if(x<0) x+=MOD;}
void Mul(int &x,int y){x=mul(x,y);}
int qpow(int x,int y){int ret=1; while(y){if(y&1) ret=mul(ret,x); x=mul(x,x); y>>=1;} return ret;}
void checkmin(int &x,int y){if(x>y) x=y;}
void checkmax(int &x,int y){if(x<y) x=y;}
void checkmin(ll &x,ll y){if(x>y) x=y;}
void checkmax(ll &x,ll y){if(x<y) x=y;}
#define out(x) cerr<<#x<<'='<<x<<' '
#define outln(x) cerr<<#x<<'='<<x<<endl
#define sz(x) (int)(x).size()
inline int read(){
    int x=0,f=1; char c=getchar();
    while(c>'9'||c<'0'){if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c^48),c=getchar();
    return x*f;
}
const int N=200005;
int n,q,a[N],pos[N]; vector<int> v[N];
int dep[N],sz[N],son[N],top[N],fa[N],in[N],out[N],cnt=0;
void dfs1(int u){
    sz[u]=1; in[u]=++cnt;
    for(auto &to : v[u]) if(to!=fa[u]){
        fa[to]=u; dep[to]=dep[u]+1;
        dfs1(to);
        sz[u]+=sz[to];
        if(sz[to]>sz[son[u]]) son[u]=to;
    }
    out[u]=cnt;
}
void dfs2(int u){
    if(son[u]) top[son[u]]=top[u],dfs2(son[u]);
    for(auto &to : v[u]) if(to!=son[u]&&to!=fa[u]){
        top[to]=to; dfs2(to);
    }
}
bool isfa(int x,int y){return in[x]<=in[y]&&out[x]>=out[y];}
bool chain(int x,int y,int z){return isfa(x,y)&&isfa(y,z);}
int LCA(int x,int y){
    while(top[x]!=top[y]) dep[top[x]]>dep[top[y]] ? x=fa[top[x]] : y=fa[top[y]];
    return dep[x]>dep[y] ? y : x;
}
int dist(int x,int y){return dep[x]+dep[y]-2*dep[LCA(x,y)];}
struct node{int x,y;};
pii calc(int x,int y,int z){
    int disxy=dist(x,y),disyz=dist(y,z),disxz=dist(x,z);
    if(disxy==disyz+disxz) return mk(x,y);
    if(disxz==disyz+disxy) return mk(x,z);
    if(disyz==disxy+disxz) return mk(y,z);
    return mk(-1,-1);
}
node merge(node A,node B){
    if(A.x==-1||B.x==-1) return {-1,-1};
    int x=A.x,y=A.y; pii tmp=calc(x,y,B.x);
    x=tmp.first,y=tmp.second;
    if(x==-1) return{-1,-1};
    tmp=calc(x,y,B.y);
    return {tmp.first,tmp.second};
}
struct Segment_Tree{
    node a[N<<2];
    void pushup(int x){a[x]=merge(a[x<<1],a[x<<1|1]);}
    void build(int x,int l,int r){
        if(l==r){a[x]={pos[l],pos[l]}; return;}
        int mid=(l+r)>>1;
        build(x<<1,l,mid); build(x<<1|1,mid+1,r);
        pushup(x);
        // out(l); out(r); out(a[x].x); outln(a[x].y);
    }
    void insert(int x,int l,int r,int p){
        if(l==r){a[x]={pos[l],pos[l]}; return;}
        int mid=(l+r)>>1;
        if(mid>=p) insert(x<<1,l,mid,p);
        else insert(x<<1|1,mid+1,r,p);
        pushup(x);
    }
    int find(int x,int l,int r,node A){
        if(l==r){return l;}
        int mid=(l+r)>>1; node tmp=merge(A,a[x<<1]);
        if(tmp.x!=-1) return find(x<<1|1,mid+1,r,tmp);
        return find(x<<1,l,mid,A);
    }
}T;

void init(){
    n=read();
    for(int i=1;i<=n;i++) a[i]=read(),pos[a[i]]=i;
    for(int i=2;i<=n;i++) v[read()].push_back(i);
    dep[1]=1; dfs1(1);
    top[1]=1; dfs2(1);
    pos[n]=-1;
}

int main()
{
    init(); T.build(1,0,n);
    int q=read();
    while(q--){
        int opt=read();
        if(opt==2) printf("%d\n",T.find(1,0,n,{pos[0],pos[0]}));
        else{
            int x=read(),y=read();
            swap(a[x],a[y]); swap(pos[a[x]],pos[a[y]]);
            T.insert(1,0,n,a[x]); T.insert(1,0,n,a[y]);
        }
    }
    return 0;
}