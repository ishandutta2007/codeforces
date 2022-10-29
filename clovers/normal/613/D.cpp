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
int fa[N][20],dfn[N],out[N],n,q,cnt=0,vis[N],vis2[N],dep[N],up[N];
vector<int> v[N],G[N];
bool cmp(int x,int y){return dfn[x]<dfn[y];}

void dfs(int u){
    dfn[u]=++cnt;
    for(auto &to : v[u]) if(to!=fa[u][0]){
        fa[to][0]=u;
        for(int i=1;i<20;i++) fa[to][i]=fa[fa[to][i-1]][i-1];
        dep[to]=dep[u]+1; dfs(to);
    }
    out[u]=cnt;
}
bool isfa(int x,int y){return dfn[x]<=dfn[y]&&out[x]>=out[y];}

int LCA(int x,int y){
    if(dep[x]<dep[y]) swap(x,y);
    for(int i=19;i>=0;i--) if(dep[fa[x][i]]>=dep[y]) x=fa[x][i];
    if(x==y) return x;
    for(int i=19;i>=0;i--) if(fa[x][i]!=fa[y][i]) x=fa[x][i],y=fa[y][i];
    return fa[x][0];
}

int dp[N][2];
void dfs2(int u){
    dp[u][0]=0; dp[u][1]=1;
    int mi=inf;
    for(auto &to : G[u]){
        dfs2(to);
        dp[u][1]+=min(dp[to][0],dp[to][1]);
        dp[u][0]+=dp[to][1];
        checkmin(mi,dp[to][0]-dp[to][1]);
    }
    if(vis[u]) dp[u][1]=inf;
    else{
        checkmin(dp[u][1],dp[u][0]);
        if(mi<0) dp[u][0]+=mi;
    }
    checkmin(dp[u][1],dp[u][0]+1);
}

int main()
{
    n=read();
    for(int i=1;i<n;i++){
        int x=read(),y=read();
        v[x].push_back(y); v[y].push_back(x);
    }
    dep[1]=1; dfs(1);
    memset(dp,0x3f,sizeof(dp));
    q=read();
    while(q--){
        int k=read(),flag=1; 
        vector<int> seq,p; seq.clear(); p.clear();
        for(int i=1;i<=k;i++){
            int x=read(); seq.push_back(x); p.push_back(x);
            vis[x]=1;
        }
        sort(seq.begin(),seq.end(),cmp);
        for(auto &u : seq) if(vis[fa[u][0]]) flag=0;
        if(!flag){
            puts("-1"); 
            for(auto &u : p) vis[u]=0,vis2[u]=0,G[u].clear();
            continue;
        }
        stack<int> stk;
        stk.push(1),vis2[1]=1;
        if(!vis[1]) p.push_back(1);
        for(auto &u : seq){
            if(vis2[u]) continue;
            int tmp=-1;
            while(!isfa(stk.top(),u)){
                tmp=stk.top(); stk.pop();
                if(isfa(stk.top(),u)) break;
                G[stk.top()].push_back(tmp);
            }
            if(tmp!=-1){
                int lca=LCA(tmp,u);
                if(!vis2[lca]) 
                    stk.push(lca),p.push_back(lca),vis2[lca]=1;
                G[lca].push_back(tmp);
            }
            stk.push(u); vis2[u]=1;
        }
        while(!stk.empty()){
            int tmp=stk.top(); stk.pop();
            if(stk.empty()) break;
            G[stk.top()].push_back(tmp);
        }
        dfs2(1);
        printf("%d\n",min(dp[1][0],dp[1][1]));
        for(auto &u : p) vis[u]=0,vis2[u]=0,G[u].clear();
    }
    return 0;
}