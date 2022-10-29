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
const int M=500005;
int first[N],nxt[M],point[M],w[M],cur[N],e=0,tot=0;
int S,T,n,m,a[N];
namespace Flow{
    void add_edge(int x,int y,int z){
        point[e]=y; w[e]=z;
        nxt[e]=first[x]; first[x]=e++;
    }
    void add(int x,int y,int z){
        add_edge(x,y,z); add_edge(y,x,0);
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
vector<int> v[N]; int num[N];
void process(int x,int id){
    for(int i=2;i*i<=x;i++){
        if(x%i==0){
            int cnt=0; num[++tot]=i;
            while(x%i==0) x/=i,cnt++;
            if(id&1) Flow::add(S,tot,cnt); 
            else Flow::add(tot,T,cnt);
            v[id].push_back(tot);
        }
    }
    if(x>1){
        num[++tot]=x;
        if(id&1) Flow::add(S,tot,1);
        else Flow::add(tot,T,1);
        v[id].push_back(tot);
    }
}

int main()
{
    memset(first,-1,sizeof(first));
    S=++tot; T=++tot;
    n=read(); m=read();
    for(int i=1;i<=n;i++) a[i]=read(),process(a[i],i);
    for(int i=1;i<=m;i++){
        int x=read(),y=read();
        if(y&1) swap(x,y);
        for(auto &j1 : v[x]){
            for(auto &j2 : v[y]){
                if(num[j1]==num[j2]) Flow::add(j1,j2,inf); 
            }
        }
    }
    cout<<Flow::Dinic()<<endl;
    return 0;
}