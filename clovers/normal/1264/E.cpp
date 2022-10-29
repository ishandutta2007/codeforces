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
const int N=50005;
const int M=500005;
int S,T,tot;
int first[N],nxt[M],point[M],w[M],cost[M],cur[N],e;
namespace Flow{
    void init(){memset(first,-1,sizeof(first)); e=0;}
    int vis[N],dis[N];
    void add_edge(int x,int y,int z,int c){
        point[e]=y; w[e]=z; cost[e]=c;
        nxt[e]=first[x]; first[x]=e++;
    }
    void add(int x,int y,int z,int c){
        add_edge(x,y,z,c);
        add_edge(y,x,0,-c);
    }
    bool spfa(){
        memset(vis,0,sizeof(vis));
        memset(dis,0x3f,sizeof(dis));
        queue<int> q; vis[S]=1; dis[S]=0; q.push(S);
        while(!q.empty()){
            int u=q.front(); q.pop(); vis[u]=0;
            for(int i=first[u];i!=-1;i=nxt[i]) if(w[i]){
                int to=point[i];
                if(dis[u]+cost[i]<dis[to]){
                    dis[to]=dis[u]+cost[i];
                    if(!vis[to]) q.push(to),vis[to]=1;
                }
            }
        } 
        return dis[T]<inf;
    }
    int C=0;
    int dfs(int u,int flow){
        if(u==T) return flow;
        int ret=flow;
        vis[u]=1;
        for(int i=first[u];i!=-1;i=nxt[i]){
            int to=point[i];
            if(!w[i]||dis[to]==INF||vis[to]||dis[to]!=dis[u]+cost[i]) continue;
            int tmp=dfs(to,min(w[i],ret));
            if(tmp) w[i]-=tmp,w[i^1]+=tmp,ret-=tmp,C+=cost[i]*tmp;
        }
        return flow-ret;
    }
    int MCMF(){
        int ret=0;
        while(spfa()){
            memset(vis,0,sizeof(vis));
            for(int i=1;i<=tot;i++) cur[i]=first[i];
            ret+=dfs(S,inf);
        }
        return C;
    }
}
int mp[105][105],deg[105],n,m,id[105][105];

int main()
{
    n=read(); m=read(); tot=n; S=++tot,T=++tot;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) mp[i][j]=2;
        mp[i][i]=0;
    }
    for(int i=1;i<=m;i++){
        int x=read(),y=read();
        mp[x][y]=1; mp[y][x]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i!=j&&mp[i][j]==1) deg[i]++;
        }
    }
    Flow::init();
    for(int i=1;i<=n;i++){
        for(int j=0;j<n;j++) Flow::add(S,i,1,j);
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++) if(mp[i][j]==2){
            tot++;
            Flow::add(i,tot,1,0); id[i][j]=e-1;
            Flow::add(j,tot,1,0);
            Flow::add(tot,T,1,0);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) if(mp[i][j]==1){
            Flow::add(i,T,1,0);
        }
    }
    
    int C=Flow::MCMF();
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++) if(mp[i][j]==2){
            if(w[id[i][j]]) mp[i][j]=1,mp[j][i]=0;
            else mp[i][j]=0,mp[j][i]=1;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) printf("%d",mp[i][j]);
        puts("");
    }
    return 0;
}