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
#define chkmin(a,b) (a=min(a,b))
#define chkmax(a,b) (a=max(a,b))
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
const int maxn=200005;

//i_am_noob
#define wiwihorz  

int n,a[maxn],l,r,mid,dp[maxn][2];
vector<int> adj[maxn];
bool flag;

void dfs(int u, int par){
    for(auto v: adj[u]) if(v!=par){
        dfs(v,u);
        if(!flag) return;
    }
    bool ok=0;
    rep1(j,2){
        if(a[u]==j+1){
            dp[u][j]=inf;
            continue;
        }
        vector<int> vec;
        for(auto v: adj[u]) if(v!=par) vec.pb(min(dp[v][j],dp[v][j^1]+1));
        if(!sz(vec)){
            dp[u][j]=0;
            ok=1;
            continue;
        }
        int pos=max_element(all(vec))-vec.begin();
        int k=vec[pos];
        dp[u][j]=k;
        vec[pos]=-inf;
        if(sz(vec)>=2) k+=*max_element(all(vec));
        bug(k);
        if(k>mid){
            dp[u][j]=inf;
            continue;
        }
        ok=1;
    }
    bug(u,dp[u][0],dp[u][1]);
    if(!ok) flag=0;
}

void orzck(){
    cin >> n;
    rep(n) cin >> a[i];
    rep(n) adj[i].clear();
    rep(n-1){
        int u,v;
        cin >> u >> v;
        u--,v--;
        adj[u].pb(v),adj[v].pb(u);
    }
    bug("de");
    l=0,r=n-1;
    while(l<r){
        mid=l+r>>1;
        flag=1;
        dfs(0,-1);
        if(flag) r=mid;
        else l=mid+1;
    }
    bug(l);
    print((l+3)/2);
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