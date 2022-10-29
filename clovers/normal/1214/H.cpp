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
int n,k; vector<int> v[N];
int dis[N],dep[N];
int mx=0,rt,fa[N];
void dfs(int u,int f){
    fa[u]=f;
    if(mx<dep[u]) mx=dep[u],rt=u;
    for(auto &to : v[u]) if(to!=f){
        dep[to]=dep[u]+1; dfs(to,u);
    }
}
int col[N],vis[N],mxdep;
vector<int> seq;
void dfs2(int u,int f,int flag,int now){
    col[u]=now; checkmax(mxdep,dep[u]);
    now+=flag; if(now<=0) now+=k; if(now>k) now-=k;
    for(auto &to : v[u]) if(to!=f&&!vis[to]) 
        dep[to]=dep[u]+1,dfs2(to,u,flag,now);
}
void GG(){puts("No"); exit(0);}

int main()
{
    n=read(); k=read();
    for(int i=1;i<n;i++){
        int x=read(),y=read();
        v[x].push_back(y),v[y].push_back(x);
    }
    dfs(1,0); mx=0; dep[rt]=0;
    int rt1=rt;
    dfs(rt,0); mx=0; dep[rt]=0;
    for(int i=1;i<=n;i++) dis[i]=dep[i];
    dfs(rt,0); int rt2=rt;
    int x=rt1;
    while(x) seq.push_back(x),vis[x]=1,x=fa[x];
    x=1;
    for(auto &u : seq){
        col[u]=x++; if(x>k) x-=k;
    } 
    for(int i=0;i<sz(seq);i++){
        int dis1=i+1,dis2=sz(seq)-i;
        int u=seq[i]; dep[u]=0; mxdep=0;
        if(i<sz(seq)/2){
            dfs2(u,0,-1,col[u]);
            if(mxdep&&mxdep+dis1>=k&&k!=2) GG();
        }
        else{
            dfs2(u,0,1,col[u]);
            if(mxdep&&mxdep+dis2>=k&&k!=2) GG();
        }
    }
    puts("Yes");
    for(int i=1;i<=n;i++) printf("%d ",col[i]);
    return 0;
}