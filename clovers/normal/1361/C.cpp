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
const int N=1100005;
namespace DSU{
    int fa[N];
    void init(){for(int i=0;i<N;i++) fa[i]=i;}
    int getfather(int x){return x==fa[x] ? x : fa[x]=getfather(fa[x]);}
    void unite(int x,int y){fa[getfather(x)]=getfather(y);}
}

int in[N],n,a[N],b[N],vis[N]; 
bool check(int bit){
    int B=(1<<bit);
    memset(in,0,sizeof(in));
    memset(vis,0,sizeof(vis));
    DSU::init();
    for(int i=1;i<=n;i++){
        int x=a[i]%B,y=b[i]%B;
        in[x]++; in[y]++;
        vis[x]=1; vis[y]=1;
        DSU::unite(x,y);
    }
    for(int i=0;i<B;i++) if(in[i]&1) return 0;
    int bl=0;
    for(int i=0;i<B;i++) bl+=(i==DSU::getfather(i)&&vis[i]);
    return bl==1;
}

struct Edge{
    int to,idx,idy;
    bool operator < (const Edge &rhs) const{
        if(to==rhs.to) return idx<rhs.idx;
        return to<rhs.to;
    }
};

set<Edge> v[N];
vector<int> ans;
void dfs(int u){
    while(!v[u].empty()){
        Edge E=*v[u].begin();
        v[u].erase(E);
        int to=E.to;
        //cout<<u<<" "<<to<<" "<<E.idx<<" "<<E.idy<<endl;
        v[to].erase(Edge{u,E.idy,E.idx});
        dfs(to);
        ans.push_back(E.idy);
        ans.push_back(E.idx);
    }
}

void build(int bit){
    int B=(1<<bit);
    memset(in,0,sizeof(in));
    int S=-1;
    for(int i=1;i<=n;i++){
        int x=a[i]%B,y=b[i]%B; S=x;
        int idx=i*2-1,idy=i*2;
        v[x].insert({y,idx,idy});
        v[y].insert({x,idy,idx});
    }
    dfs(S);
}

int main()
{
    n=read();
    for(int i=1;i<=n;i++) a[i]=read(),b[i]=read();
    int l=1,r=20,mid,best=0;
    while(l<=r){
        mid=(l+r)>>1;
        if(check(mid)) l=mid+1,best=mid;
        else r=mid-1;
    }
    if(!best){
        puts("0");
        for(int i=1;i<=2*n;i++) printf("%d ",i);
        puts("");
        return 0; 
    }
    printf("%d\n",best);
    build(best);
    for(auto &to : ans) printf("%d ",to); puts("");
    return 0;
}