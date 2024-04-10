#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2,fma,tune=native")

#define ll long long
#define int ll
#define ull unsigned ll
#define ld long double
#define rep(a) rep1(i,a)
#define rep1(i,a) rep2(i,0,a)
#define rep2(i,b,a) for(int i=(b); i<((int)(a)); i++)
#define rep3(i,b,a) for(int i=(b); i>=((int)(a)); i--)
#define all(a) a.begin(),a.end()
#define pii pair<int,int>
#define pb push_back
//#define inf 1010000000
#define inf 4000000000000000000
#define eps 1e-9
#define sz(a) ((int)a.size())
#define pow2(x) (1ll<<(x))
#define ceiling(a,b) (((a)+(b)-1)/(b))
#define print0(a) cout << (a) << ' '
#define ykh mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#ifdef i_am_noob
#define bug(...) cerr << "#" << __LINE__ << ' ' << #__VA_ARGS__ << "- ", _do(__VA_ARGS__)
template<typename T> void _do(vector<T> x){for(auto i: x) cerr << i << ' ';cerr << "\n";}
template<typename T> void _do(set<T> x){for(auto i: x) cerr << i << ' ';cerr << "\n";}
template<typename T> void _do(unordered_set<T> x){for(auto i: x) cerr << i << ' ';cerr << "\n";}
template<typename T> void _do(T && x) {cerr << x << endl;}
template<typename T, typename ...S> void _do(T && x, S&&...y) {cerr << x << ", "; _do(y...);}
#else
#define bug(...) 826
#endif
template<typename T> void print(T && x) {cout << x << "\n";}
template<typename T, typename... S> void print(T && x, S&&... y) {cout << x << ' ';print(y...);}

const int Mod=1000000007,Mod2=998244353;
const int MOD=Mod2;
const int maxn=305;

//i_am_noob
//#define wiwihorz  
int n,siz[maxn],G,par[maxn],h[maxn],dep[maxn],cnt[maxn][maxn],lst[maxn][maxn];
int res[maxn],dp[maxn][maxn/2][maxn/2],sum[maxn][maxn/2][maxn/2],Pow[maxn],inv[maxn];
bool vis[maxn][maxn][maxn];
vector<int> adj[maxn],vec[maxn][maxn],vec1;
ld start;

void dfs0(int u, int fa){
    siz[u]=1;
    for(auto v: adj[u]) if(v!=fa){
        dfs0(v,u);
        siz[u]+=siz[v];
    }
}

void dfs1(int u, int fa){
    siz[u]=1;
    h[u]=0;
    par[u]=fa;
    dep[u]=fa==-1?0:dep[fa]+1;
    vec1.pb(u);
    for(auto v: adj[u]) if(v!=fa){
        dfs1(v,u);
        siz[u]+=siz[v];
        h[u]=max(h[u],h[v]);
        rep2(i,1,n) cnt[u][i]+=cnt[v][i-1];
        rep2(i,1,h[v]+1) vec[u][i].pb(v);
        lst[u][h[v]+1]=h[v];
    }
    lst[u][1]=-1;
    h[u]++;
    rep2(i,2,h[u]) if(!lst[u][i]) lst[u][i]=lst[u][i-1];
    cnt[u][0]=siz[u];
}

int findG(int u, int fa){
    for(auto v: adj[u]) if(v!=fa&&siz[v]>n/2) return findG(v,u);
    return u;
}

void solve(int x){
    int tmp1[maxn],tmp2[maxn];
    for(auto i: vec1){
        if(par[i]!=-1&&siz[par[i]]<=x+1) continue;
        if(siz[i]<=x+1){
            rep1(j,min(h[i]+1,x+1)) rep1(k,min(h[i]+1,j+x+1)){
                if(k<h[i]) dp[i][j][k]=(Pow[cnt[i][k]]-Pow[cnt[i][k+1]]+MOD)%MOD;
                else if(j>=h[i]) dp[i][j][k]=1;
                else dp[i][j][k]=0;
                //bug(x,i,j,k,dp[i][j][k]);
            }
        }
        else{
            rep1(j,min(h[i]+1,x+1)) rep1(k,min(h[i]+1,j+x+1)){
                dp[i][j][k]=0;
                if(k==0){
                    dp[i][j][k]=1;
                    for(auto v: vec[i][1]) dp[i][j][k]=dp[i][j][k]*sum[v][min(h[v],x)][0]%MOD;
                }
                else if(k==h[i]){
                    if(j==h[i]) dp[i][j][k]=1;
                    else dp[i][j][k]=0;
                }
                else{
                    //if(x==2&&i==G) bug(j,k);
                    if(j<=lst[i][k]&&x<k+lst[i][k]){
                        dp[i][j][k]=0;
                        continue;
                    }
                    auto& vec2=vec[i][k];
                    tmp1[0]=1;
                    rep1(ii,sz(vec2)) tmp1[ii+1]=tmp1[ii]*sum[vec2[ii]][min(h[vec2[ii]],max({0ll,j-1,x-k}))][min({h[vec2[ii]]+1,min(h[vec2[ii]],max({0ll,j-1,x-k}))+x+1,k})]%MOD;
                    tmp2[0]=1;
                    rep3(ii,sz(vec2)-1,0) tmp2[sz(vec2)-ii]=tmp2[sz(vec2)-1-ii]*sum[vec2[ii]][min(h[vec2[ii]],max({0ll,j-1,x-k}))][min({h[vec2[ii]]+1,min(h[vec2[ii]],max({0ll,j-1,x-k}))+x+1,k-1})]%MOD;
                    rep1(ii,sz(vec2)) dp[i][j][k]=(dp[i][j][k]+tmp1[ii]*tmp2[sz(vec2)-1-ii]%MOD*dp[vec2[ii]][min(h[vec2[ii]],max(0ll,j-1))][min({h[vec2[ii]]+1,min(h[vec2[ii]],max({0ll,j-1}))+x+1,k-1})])%MOD;
                }
                //if(x==2&&i==G) bug(j,k,dp[i][j][k]);
            }
        }
        rep1(j,min(h[i]+1,x+1)) sum[i][j][min(h[i]+1,j+x+1)]=dp[i][j][min(h[i]+1,j+x+1)]=0;
        rep1(j,min(h[i]+1,x+1)) rep3(k,min(h[i],j+x),0){
            sum[i][j][k]=dp[i][j][k]+sum[i][j][k+1];
            if(sum[i][j][k]>=MOD) sum[i][j][k]-=MOD;
            //bug(i,j,k,sum[i][j][k]);
        }
    }
    res[x]=sum[G][0][0];
    //bug(x,res[x]);
    bug(x,(clock()-start)/CLOCKS_PER_SEC);
}

void orzck(){
    start=clock();
    cin >> n;
    rep(n-1){
        int u,v;
        cin >> u >> v;
        u--,v--;
        adj[u].pb(v),adj[v].pb(u);
    }
    dfs0(0,-1);
    G=findG(0,-1);
    dfs1(G,-1);
    bug(G);
    reverse(all(vec1));
    //bug(vec1);
    Pow[0]=inv[0]=1;
    Pow[1]=2,inv[1]=(MOD+1)/2;
    rep2(i,2,maxn) Pow[i]=Pow[i-1]*2%MOD;
    rep2(i,2,maxn) inv[i]=inv[i-1]*((MOD+1)/2)%MOD;
    rep2(i,1,n) solve(i);
    int ans=n-1;
    res[0]=1;
    rep2(i,1,n) ans=(ans+(res[i]-res[i-1]+MOD)*(i-1))%MOD;//bug(ans);
    print(ans*inv[n]%MOD);

}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    #ifdef i_am_noob
    freopen("input1.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    freopen("output2.txt","w",stderr);
    #endif
    cout << fixed << setprecision(15);
    int t;
    #ifdef wiwihorz
    cin >> t;
    #else
    t=1;
    #endif
    while(t--) orzck();
    return 0;
}