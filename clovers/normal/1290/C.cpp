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
const int N=300005;
int n,m,ans=0,sz[N]; 
int t1[N],t2[N],ret[N],fae[N],sum[N],bl[N];
char s[N]; pii E[N];
vector<pii> v[N];
namespace DSU{
    int fa[N];
    void init(){for(int i=1;i<=m;i++) fa[i]=i,bl[i]=-1;}
    int getfather(int x){return fa[x]==x ? x : fa[x]=getfather(fa[x]);}
}
void dfs(int u,int f,int w,int from){
    fae[u]=w; sum[u]=(sum[f]^fae[u]);
    if(sum[u]==1) t1[from]++; else t2[from]++;
    for(auto &to : v[u]) if(to.first!=f) dfs(to.first,u,to.second,from);
}

void add_edge(int x,int y,int id){
    int xx=DSU::getfather(x),yy=DSU::getfather(y);
    if(xx==yy) return;
    if(sz[xx]<sz[yy]) swap(x,y),swap(xx,yy);
    sz[xx]+=sz[yy]; DSU::fa[yy]=xx;
    ans-=(ret[xx]+ret[yy]);
    v[x].push_back(mk(y,id)); v[y].push_back(mk(x,id));
    dfs(y,x,id,xx);
    if(bl[yy]!=-1) bl[xx]=(bl[yy]^sum[yy]); 
    ret[xx]=min(t1[xx],t2[xx]);
    if(bl[xx]!=-1) ret[xx]=(bl[xx]==1 ? t2[xx] : t1[xx]);
    ans+=ret[xx];
}

int main()
{
    n=read(); m=read();
    DSU::init(); for(int i=1;i<=m;i++) sz[i]=1,t2[i]=1;
    scanf("%s",s+1);
    for(int i=1;i<=m;i++){
        int k=read();
        while(k--){
            int x=read();
            if(!E[x].first) E[x].first=i;
            else E[x].second=i;
        }
    }
    for(int i=1;i<=n;i++){
        if(E[i].second) add_edge(E[i].first,E[i].second,'1'-s[i]);
        else if(E[i].first){
            int x=E[i].first,xx=DSU::getfather(x);
            ans-=ret[xx];
            bl[xx]=('1'-s[i])^sum[x];
            ret[xx]=(bl[xx]==1 ? t2[xx] : t1[xx]);
            ans+=ret[xx];
        }
        printf("%d\n",ans);
    }
    return 0;
}