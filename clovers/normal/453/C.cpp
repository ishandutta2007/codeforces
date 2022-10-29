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
const int N=100005;
int t[N],vis[N],n,m,a[N]; vector<int> v[N];
namespace DSU{
    int b[N],fa[N];
    void init(){for(int i=1;i<=n;i++) fa[i]=i,b[i]=a[i];}
    int getfather(int x){return x==fa[x] ? x : fa[x]=getfather(fa[x]);}
    void unite(int x,int y){
        x=getfather(x); y=getfather(y);
        if(x==y) return;
        fa[x]=y; b[y]|=b[x];
    }
}

vector<int> ans;
void dfs(int u){
    vis[u]=1; t[u]++; ans.push_back(u);
    for(auto &to : v[u]) if(!vis[to]){
        dfs(to); t[u]++; ans.push_back(u);
        if(t[to]%2!=a[to]){
            t[to]++; t[u]++;
            ans.push_back(to); ans.push_back(u);
        }
    }
}

int main()
{
    n=read(); m=read();
    for(int i=1;i<=m;i++){
        int x=read(),y=read();
        v[x].push_back(y); v[y].push_back(x);
    }
    for(int i=1;i<=n;i++) a[i]=read();
    DSU::init();
    for(int i=1;i<=n;i++){
        for(auto &j : v[i]) DSU::unite(i,j);
    }
    int cnt=0;
    for(int i=1;i<=n;i++) cnt+=(i==DSU::getfather(i)&&DSU::b[i]);
    if(!cnt){puts("0"); return 0;}
    if(cnt>=2){puts("-1"); return 0;}
    int rt;
    for(int i=1;i<=n;i++) if(i==DSU::getfather(i)&&DSU::b[i]) rt=i;
    dfs(rt);
    int st=(a[rt]==t[rt]%2 ? 0 : 1);
    printf("%d\n",sz(ans)-st);
    for(int i=st;i<sz(ans);i++) printf("%d ",ans[i]);
    return 0;
}