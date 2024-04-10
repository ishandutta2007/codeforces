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
int n,m,a[N]; vector<int> v[N];
int dep[N],top[N],dfn[N],id[N],sz[N],son[N],fa[N],dfn_clock=0;
void dfs1(int u){
    sz[u]=1;
    for(auto &to : v[u]){
        if(to==fa[u]) continue; 
        fa[to]=u; dep[to]=dep[u]+1;
        dfs1(to); sz[u]+=sz[to];
        if(sz[son[u]]<sz[to]) son[u]=to;
    }
}

void dfs2(int u){
    dfn[u]=++dfn_clock; id[dfn_clock]=u;
    if(son[u]) top[son[u]]=top[u],dfs2(son[u]);
    for(auto &to : v[u]){
        if(to==fa[u]||to==son[u]) continue;
        top[to]=to; dfs2(to);
    }
}

struct BIT{
    int a[N];
    int lowbit(int x){return x&(-x);}
    void update(int x,int val){
        for(int i=x;i<=n;i+=lowbit(i)) a[i]+=val;
    }
    int query(int x){
        int ret=0;
        for(int i=x;i;i-=lowbit(i)) ret+=a[i];
        return ret; 
    }
}tree1,tree2;

int main()
{
    n=read(); m=read();
    for(int i=1;i<=n;i++) a[i]=read();
    for(int i=1;i<n;i++){
        int x=read(),y=read();
        v[x].push_back(y),v[y].push_back(x);
    }
    dep[1]=1; dfs1(1); top[1]=1; dfs2(1);
    for(int i=1;i<=n;i++){
        tree1.update(i,a[id[i]]-a[id[i-1]]);
        tree2.update(i,a[id[i]]-a[id[i-1]]);
    }
    for(int i=1;i<=m;i++){
        int opt=read(),u=read();
        if(opt==1){
            int val=read();
            if(dep[u]&1){
                tree1.update(dfn[u],val); tree1.update(dfn[u]+sz[u],-val);
                tree2.update(dfn[u],-val); tree2.update(dfn[u]+sz[u],val);
            }
            else{
                tree1.update(dfn[u],-val); tree1.update(dfn[u]+sz[u],val);
                tree2.update(dfn[u],val); tree2.update(dfn[u]+sz[u],-val);
            }
        }
        else{
            if(dep[u]&1) printf("%d\n",tree1.query(dfn[u]));
            else printf("%d\n",tree2.query(dfn[u]));
        }
    }
    return 0;
}