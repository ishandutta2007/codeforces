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
const int N=1001;
const int M=500005;
int first[N],nxt[M],point[M],w[M],cur[N],e=0,tot=0;
int S,T,a[N],id[N][N];
namespace Flow{
    void add_edge(int x,int y,int z){
        point[e]=y; w[e]=z;
        nxt[e]=first[x]; first[x]=e++;
    }
    void add(int x,int y,int z){
        add_edge(x,y,z); add_edge(y,x,0);
        id[x][y]=e-1; id[y][x]=e-1;
    }
    int vis[N],dep[N];
    bool bfs(){
        queue<int> q; while(!q.empty()) q.pop();
        for(int i=1;i<=tot;i++) vis[i]=0;
        vis[S]=1; q.push(S); dep[S]=0;
        while(!q.empty()){
            int u=q.front(); q.pop();
            for(int i=first[u];i!=-1;i=nxt[i]) if(w[i]){
                int to=point[i];
                if(vis[to]) continue;
                dep[to]=dep[u]+1; vis[to]=1; q.push(to);
            }
        }
        return vis[T];
    }
    int dfs(int u,int flow){
        if(u==T) return flow;
        int ret=flow;
        for(int &i=cur[u];i!=-1;i=nxt[i]) if(w[i]){
            int to=point[i];
            if(dep[to]!=dep[u]+1) continue;
            int tmp=dfs(to,min(w[i],ret));
            if(tmp) w[i]-=tmp,w[i^1]+=tmp,ret-=tmp;
            if(!ret) break;
        }
        return flow-ret;
    }
    int Dinic(){
        int ret=0;
        while(bfs()){
            for(int i=1;i<=tot;i++) cur[i]=first[i];
            ret+=dfs(S,inf);
        }
        return ret;
    }
}

int n,bl[M];
void init(){
    memset(first,-1,sizeof(first));
    n=read(); for(int i=1;i<=n;i++) a[i]=read();
    for(int i=2;i<M;i++){
        if(!bl[i]) for(int j=i+i;j<M;j+=i) bl[j]=1;
    }
    tot=n; S=++tot; T=++tot;
    for(int i=1;i<=n;i++){
        if(a[i]&1){
            Flow::add(S,i,2);
            for(int j=1;j<=n;j++) if(!bl[a[i]+a[j]]){
                Flow::add(i,j,1);
            }
        }
        else Flow::add(i,T,2);
    }
}
int vis[N];
vector<vector<int> > ans;
int main()
{
    init(); int F=Flow::Dinic();
    if(F!=n){puts("Impossible"); return 0;}
    for(int i=1;i<=n;i++) if(!vis[i]){
        vector<int> v;
        int x=i;
        while(1){
            vis[x]=1; v.push_back(x); int to=-1;
            for(int j=1;j<=n;j++) if(w[id[x][j]]&&!vis[j]){to=j; break;}
            if(to==-1) break; x=to;
        }
        ans.push_back(v);
    }
    printf("%d\n",sz(ans));
    for(auto &v : ans){
        printf("%d ",sz(v));
        for(auto &u : v) printf("%d ",u); puts("");
    }
    return 0;
}