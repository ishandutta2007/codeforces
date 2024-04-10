#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
using namespace std;
const int MAXN=1e3+10,mod=1e9+7;
int mypow(int a,int n){
    if(!n)return 1;
    int tmp=mypow(a,n/2);tmp=1ll*tmp*tmp%mod;
    if(n&1)tmp=1ll*tmp*a%mod;
    return tmp;
}
int myinv(int a){return mypow(a,mod-2);}
int fact[20],inv[20];
void add(int& x,int y){x=(x+y)%mod;}
struct DSU{
    int fa[15],sz[15];
    void init(int n){
        rep(i,0,n-1)fa[i]=i,sz[i]=1;
    }
    int find(int x){
        if(fa[x]==x)return x;
        return fa[x]=find(fa[x]);
    }
    void merge(int x,int y){
        x=find(x);y=find(y);if(x==y)return;
        fa[x]=y;sz[y]+=sz[x];
    }
}dsu;
int pcnt[1<<12],lb[1<<12];
int fa[MAXN],sz[MAXN];
int n,m,ans;
vector<int>E[MAXN],e[MAXN];

int pre_solve(int,int);
void solve(int);
void dfs(int u){
    sz[u]=1;
    for(auto v:E[u])if(v!=fa[u]){
        fa[v]=u;
        dfs(v);
        sz[u]+=sz[v];
    }
}   
int main(){
    //freopen("trtr.in","r",stdin);
    //freopen("trtr.out","w",stdout);

    fact[0]=1;rep(i,1,15)fact[i]=1ll*fact[i-1]*i%mod;
    inv[15]=myinv(fact[15]);per(i,14,0)inv[i]=1ll*inv[i+1]*(i+1)%mod;

    rep(i,1,(1<<12)-1)pcnt[i]=pcnt[i^lowbit(i)]+1;
    rep(i,0,11)lb[1<<i]=i;
    cin>>n;
    rep(i,1,n-1){
        int u,v;cin>>u>>v;u--;v--;
        E[u].push_back(v);E[v].push_back(u);
    }
    cin>>m;
    rep(i,1,m-1){
        int u,v;cin>>u>>v;u--;v--;
        e[u].push_back(v);e[v].push_back(u);
    }
    //T
    dsu.init(m);
    rep(i,0,m-1)rep(j,i+1,m-1)if(pre_solve(i,j))dsu.merge(i,j);
    //
    fa[0]=-1;dfs(0);
    rep(i,0,m-1)if(dsu.find(i)==i)solve(i);

    cout<<ans<<"\n";
    return 0;
}
int sz1[MAXN],sz2[MAXN];
int pre_f[15][15];
void pre_dfs(int u,int fa,int* sz){
    sz[u]=1;
    for(auto v:e[u])if(v==fa)continue;else{
        pre_dfs(v,u,sz);
        sz[u]+=sz[v];
    }
}
int state[MAXN],pre_g[1<<12],tot;
int pre_dp(int x,int y,int fax,int fay){
    if(pre_f[x][y]!=-1)return pre_f[x][y];
    int& res=pre_f[x][y];
    if(sz1[x]!=sz2[y])return res=0;
    int cnt1=e[x].size(),cnt2=e[y].size();
    if(fax!=-1)cnt1--;if(fay!=-1)cnt2--;
    if(cnt1!=cnt2)return res=0;
    for(auto u:e[x])if(u!=fax){
       for(auto v:e[y])if(v!=fay)pre_dp(u,v,x,y);
    }
    tot=0;
    for(auto u:e[x])if(u!=fax){
        state[tot]=0;
        for(auto v:e[y])if(v!=fay){
            if(pre_dp(u,v,x,y)){
                state[tot]|=(1<<v);
            }
        }
        tot++;
    }
    pre_g[0]=0;
    rep(i,1,(1<<tot)-1)pre_g[i]=pre_g[i^lowbit(i)] | state[lb[lowbit(i)]];
    rep(i,0,(1<<tot)-1)if(pcnt[i] > pcnt[pre_g[i]])return res=0; 
    return res=1;
}   
int pre_solve(int X,int Y){
    //TXY
    pre_dfs(X,-1,sz1);
    pre_dfs(Y,-1,sz2);
    rep(i,0,m-1)rep(j,0,m-1)pre_f[i][j]=-1;
    return pre_dp(X,Y,-1,-1);
}
int f[MAXN][15],tmpdp[MAXN][15];
int xishu[15]; //
int dp(int x,int y,int fax,int fay){
    if(f[x][y]!=-1)return f[x][y];
    int& res=f[x][y];res=0;
    if(sz[x]<sz1[y])return res=0;
    int cnt1=E[x].size(),cnt2=e[y].size();
    if(fax!=-1)cnt1--;if(fay!=-1)cnt2--;
    if(cnt1<cnt2)return res=0;
    for(auto u:E[x])if(u!=fax)for(auto v:e[y])if(v!=fay)dp(u,v,x,y);
    tot=0;
    for(auto u:E[x])if(u!=fax){
        state[tot]=0;
        for(auto v:e[y])if(v!=fay){
            if(dp(u,v,x,y))state[tot]|=(1<<v),tmpdp[tot][v]=dp(u,v,x,y);
        }
        tot++;
    }
    memset(pre_g,0,sizeof pre_g);
    pre_g[0]=1;
    
    rep(i,0,tot-1){
        per(mask,(1<<m)-1,0){
            int val=(mask&state[i]);
            while(val){
                add(pre_g[mask],1ll*pre_g[mask^lowbit(val)]*tmpdp[i][lb[lowbit(val)]]);
                val^=lowbit(val);
            }
        }
    }

    rep(i,0,(1<<m)-1)if(pcnt[i]==cnt2)add(res,pre_g[i]);
    res=1ll*res*xishu[y]%mod;
    return res;
}
int tmpfa[15];
void tmpdfs(int u){
    for(auto v:e[u])if(v==tmpfa[u])continue;else{
        tmpfa[v]=u;tmpdfs(v);
    }
}
void solve(int u){
    //S(T,u)
    pre_dfs(u,-1,sz1);
    //
    rep(i,0,m-1)rep(j,0,m-1)pre_f[i][j]=-1;
    tmpfa[u]=-1;
    tmpdfs(u);
    rep(i,0,m-1)rep(j,0,m-1)pre_dp(i,j,tmpfa[i],tmpfa[j]);
    rep(u,0,m-1){
        DSU dsu;dsu.init(m);
        for(auto x:e[u])if(x!=tmpfa[u])for(auto y:e[u])if(y!=tmpfa[u])if(pre_dp(x,y,tmpfa[x],tmpfa[y]))dsu.merge(x,y);
        xishu[u]=1;
        rep(i,0,m-1)if(dsu.find(i)==i)xishu[u]=1ll*xishu[u]*inv[dsu.sz[i]]%mod;
    }
    //dp
    rep(i,0,n)rep(j,0,m-1)f[i][j]=-1; 
    
    rep(i,0,n-1){
        dp(i,u,fa[i],-1);
        add(ans,f[i][u]);
    }
}