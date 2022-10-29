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
const int N=500005;
int n,T,now,ans;
namespace BIT{
    int a[N];
    void init(){for(int i=1;i<=n;i++) a[i]=0;}
    int lowbit(int x){return x&(-x);}
    void update(int x,int val){
        for(int i=x;i<=n;i+=lowbit(i)) a[i]+=val;
    }
    int query(int x){
        int ret=0;
        for(int i=x;i;i-=lowbit(i)) ret+=a[i];
        return ret;
    }
}

int dfn[N],top[N],son[N],sz[N],fa[N],id[N],dfn_clock;
struct Tree2{
    vector<int> v[N];
    void dfs1(int u){
        sz[u]=1;
        for(auto &to : v[u]) if(to!=fa[u]){
            fa[to]=u; dfs1(to);
            if(sz[to]>sz[son[u]]) son[u]=to; sz[u]+=sz[to];
        }
    }
    void dfs2(int u){
        dfn[u]=++dfn_clock; id[dfn_clock]=u;
        if(son[u]) top[son[u]]=top[u],dfs2(son[u]);
        for(auto &to : v[u]) if(to!=fa[u]&&to!=son[u]) top[to]=to,dfs2(to); 
    }
    void init(){
        dfn_clock=0;
        for(int i=1;i<=n;i++) v[i].clear();
        BIT::init();
        for(int i=1;i<=n;i++) son[i]=0;
        for(int x=2;x<=n;x++){
            int y=read();
            v[x].push_back(y); v[y].push_back(x);
        }
        dfs1(1); top[1]=1; dfs2(1);
    }
}T2;
int find(int x){
    while(x){
        int to=top[x],u=fa[to];
        if(BIT::query(dfn[x])-BIT::query(dfn[to]-1)){
            int l=dfn[to],r=dfn[x],pre=BIT::query(dfn[x]),mid,best;
            while(l<=r){
                mid=(l+r)>>1;
                if(BIT::query(mid-1)!=pre) best=mid,l=mid+1; 
                else r=mid-1;
            }
            return id[best];
        }
        x=u;
    }
    return -1;
}

struct Tree1{
    vector<int> v[N];
    void init(){
        for(int i=1;i<=n;i++) v[i].clear();
        for(int x=2;x<=n;x++){
            int y=read();
            v[x].push_back(y); v[y].push_back(x);
        }
    }
    void dfs(int u,int f){
        if(BIT::query(dfn[u]+sz[u]-1)==BIT::query(dfn[u]-1)){
            int pos=find(u);
            if(pos==-1||BIT::query(dfn[pos]+sz[pos]-1)-BIT::query(dfn[pos])) now++;
        }
        BIT::update(dfn[u],1);
        checkmax(ans,now);
        for(auto &to : v[u]) if(to!=f) dfs(to,u);
        BIT::update(dfn[u],-1);
        if(BIT::query(dfn[u]+sz[u]-1)==BIT::query(dfn[u]-1)){
            int pos=find(u);
            if(pos==-1||BIT::query(dfn[pos]+sz[pos]-1)-BIT::query(dfn[pos])) now--;
        }
    }
}T1;

void init(){
    n=read(); now=0; ans=0;
    T1.init(); T2.init();
}
void solve(){T1.dfs(1,-1); printf("%d\n",ans);}
int main()
{
    T=read();
    while(T--){init(); solve();}
    return 0;
}