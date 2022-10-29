/*
the vast starry sky,
bright for those who chase the light.
*/
#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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
inline ll read(){
    ll x=0,f=1; char c=getchar();
    while(c>'9'||c<'0'){if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c^48),c=getchar();
    return x*f;
}
const int N=100005;
#define int long long
typedef pair<int,int> pii;
vector<pii> v[N];
int n,down1[N],down2[N],up[N],f[N],id[N],rk[N],t[N];
bool cmp(int x,int y){return f[x]>f[y];}

void dfs1(int u,int f){
    for(auto &to : v[u]){
        if(to.first==f) continue;
        dfs1(to.first,u);
        int val=down1[to.first]+to.second;
        if(val>down1[u]) down2[u]=down1[u],down1[u]=val;
        else if(val>down2[u]) down2[u]=val;
    }
}

void dfs2(int u,int fa,int fe){
    if(fa!=-1){
        int val=(down1[u]+fe==down1[fa] ? down2[fa] : down1[fa]);
        up[u]=max(val,up[fa])+fe;
    }
    f[u]=max(up[u],down1[u]);
    for(auto &to : v[u]){
        if(to.first==fa) continue;
        dfs2(to.first,u,to.second);
    }
}

int now;
int del(int x){
    if(t[x]==now&&t[x]==1) now--;
    t[x]--;
}
int insert(int x){
    t[x]++;
    if(now<x) now=x;
}
namespace DSU{
    int fa[N],sz[N];
    void init(){for(int i=1;i<=n;i++) fa[i]=i,sz[i]=1;}
    int getfather(int x){return x==fa[x] ? x : fa[x]=getfather(fa[x]);}
    void unite(int x,int y){
        x=getfather(x); y=getfather(y);
        if(x==y) return;
        del(sz[x]); del(sz[y]);
        if(sz[x]<sz[y]) swap(x,y);
        sz[x]+=sz[y]; fa[y]=x;
        insert(sz[x]);
    }
}

void solve(int lim){
    for(int i=1;i<=n;i++) t[i]=0;
    DSU::init();
    int ret=1; now=1;
    t[1]=n;
    for(int l=1,r=1;r<=n;r++){
        while(f[id[l]]-f[id[r]]>lim){
            int F=DSU::getfather(id[l]);
            int tmp=DSU::sz[F];
            del(tmp);
            DSU::sz[F]--;
            insert(tmp-1);
            l++;
        }
        for(auto &to : v[id[r]]){
            if(rk[to.first]>=l&&rk[to.first]<=r){
                DSU::unite(id[r],to.first);
            }
        }
        checkmax(ret,now);
    }
    printf("%lld\n",ret);
}

signed main()
{
    n=read();
    for(int i=1;i<n;i++){
        int x=read(),y=read(),z=read();
        v[x].push_back(mk(y,z)); v[y].push_back(mk(x,z));
    }
    dfs1(1,-1); dfs2(1,-1,0);
    for(int i=1;i<=n;i++) id[i]=i;
    sort(id+1,id+n+1,cmp);
    for(int i=1;i<=n;i++) rk[id[i]]=i;
    int q=read();
    while(q--){
        int l=read();
        solve(l);
    }
    return 0;
}