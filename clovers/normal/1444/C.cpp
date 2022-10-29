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
int add(int x,int y){x+=y; return x>=MOD ? x-MOD : x;}
int sub(int x,int y){x-=y; return x<0 ? x+MOD : x;}
#define mul(x,y) (ll)(x)*(y)%MOD
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
int k,n,m,scc[N];
struct Edge{
    int from,to;
    bool operator < (const Edge &rhs)const{
        if(scc[from]==scc[rhs.from]) return scc[to]<scc[rhs.to];
        return scc[from]<scc[rhs.from];
    }
}E[N];


int tot=0;
namespace DSU{
    int fa[N<<1],sz[N<<1];
    pii opt[N<<1];
    void init(){for(int i=1;i<=n+n;i++) fa[i]=i,sz[i]=1;}
    int getfather(int x){
        if(x==fa[x]) return x;
        return getfather(fa[x]);
    }
    void unite(int x,int y){//y->x
        if(x==y) return;
        if(sz[y]>sz[x]) swap(x,y);
        fa[y]=x; sz[x]+=sz[y];
        opt[++tot]=mk(x,y);
        return;
    }
    bool connect(int x,int y){
        int xn=getfather(x+n),yn=getfather(y+n);
        x=getfather(x); y=getfather(y);
        unite(xn,y); unite(x,yn);
        if(fa[x]==fa[xn]||fa[y]==fa[yn]) return 0;
        return 1;
    }
    void back(int pre){
        while(tot!=pre){
            int x=opt[tot].first,y=opt[tot].second;
            sz[x]-=sz[y]; fa[y]=y;
            tot--;
        }
    }
}

ll ans; bool able[N];
void init(){
    scanf("%d%d%d",&n,&m,&k);
    ans=1ll*k*(k-1)/2;
    int tmpm=m;
    for(int i=1;i<=n;i++) scc[i]=read();
    DSU::init();
    for(int i=1;i<=m;i++){
        E[i].from=read(),E[i].to=read();
        if(scc[E[i].from]>scc[E[i].to]) swap(E[i].from,E[i].to);
    }
    int cnt=0,tmp=k-1;
    for(int i=1;i<=n;i++) able[i]=1;
    for(int i=1;i<=m;i++){
        if(scc[E[i].from]==scc[E[i].to]){
            if(!DSU::connect(E[i].from,E[i].to)){
                if(able[scc[E[i].from]]) ans-=tmp, tmp--;
                able[scc[E[i].from]]=0;
            }
        }
        else E[++cnt]=E[i];
    }
    
    m=cnt; cnt=0;
    for(int i=1;i<=m;i++){
        if(able[scc[E[i].from]]&&able[scc[E[i].to]]) E[++cnt]=E[i];
    }
    m=cnt;
    sort(E+1,E+m+1);
}
#define u E[j].from
#define v E[j].to
void solve(){
    for(int i=1,j=1;i<=m;i=j){
        j=i; int fromcol=scc[u];
        while(scc[u]==fromcol&&j<=m){
            int tocol=scc[v], pre=tot,flag=1;
            while(scc[v]==tocol&&scc[u]==fromcol&&j<=m){
                if(!flag){j++; continue;}
                if(!DSU::connect(u,v)){
                    ans-=flag; flag=0;
                }
                j++;
            }
            DSU::back(pre);
        }
    }
    cout<<ans<<endl;
}

int main()
{
    init(); solve();
    return 0;
}