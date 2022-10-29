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
const int N=200005;
int n,a[N];
vector<int> v[N];
vector<pii> G[N][2];
ll dp[N][2];

void dfs(int u,int f){
    int flag=0;
    ll mi=INF;
    for(auto &to : v[u]) if(to!=f){
        flag=1; dfs(to,u);
        dp[u][0]+=dp[to][0];
        checkmin(mi,dp[to][1]-dp[to][0]);
    }
    if(!flag) dp[u][0]=INF;
    else dp[u][1]=dp[u][0]+mi;

    int bl=-1;
    for(auto &to : v[u]) if(to!=f&&dp[to][1]-dp[to][0]==mi){
        if(bl!=-1) bl=0; else bl=to;
        G[u][1].push_back(mk(to,1));
    }
    for(auto &to : v[u]) if(to!=f&&to!=bl) G[u][1].push_back(mk(to,0));
    if(dp[u][0]<=dp[u][1]+a[u]){
        for(auto &to : v[u]) if(to!=f) G[u][0].push_back(mk(to,0));
    }
    if(dp[u][0]>=dp[u][1]+a[u]) G[u][0].push_back(mk(u,1)),dp[u][0]=dp[u][1]+a[u];
    // out(u); out(dp[u][0]); outln(dp[u][1]);
}
int vis[N][2],bl[N];
void dfs2(int u,int typ){
    vis[u][typ]=1;
    for(auto &to : G[u][typ]){
        if(to.first==u) bl[u]=1;
        if(!vis[to.first][to.second]) dfs2(to.first,to.second);
    }
}

int main()
{
    n=read(); for(int i=1;i<=n;i++) a[i]=read();
    for(int i=1;i<n;i++){
        int x=read(),y=read();
        v[x].push_back(y); v[y].push_back(x);
    }
    dfs(1,-1);
    cout<<dp[1][0]<<" ";
    dfs2(1,0);
    vector<int> ans;
    for(int i=1;i<=n;i++) if(bl[i]) ans.push_back(i);
    printf("%d\n",sz(ans));
    for(auto &u : ans) printf("%d ",u);
    return 0;
}