#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2,tune=native")

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
template<typename T> void _do(T && x) {cerr << x << endl;}
template<typename T, typename ...S> void _do(T && x, S&&...y) {cerr << x << ", "; _do(y...);}
#else
#define bug(...) 826
#endif
template<typename T> void print(T && x) {cout << x << "\n";}
template<typename T, typename... S> void print(T && x, S&&... y) {cout << x << ' ';print(y...);}

const int Mod=1000000007,Mod2=998244353;
const int MOD=Mod2;
const int maxn=100005;
//i_am_noob
//#define wiwihorz  
int n,m,mex[maxn],b[maxn],cnt[515],arr[515][515];
vector<int> adj[maxn],ord;
bool vis[maxn];

void dfs(int u){
    vis[u]=true;
    for(auto v: adj[u]) if(!vis[v]) dfs(v);
    ord.pb(u);
}

inline int Pow(int a, int b){
    int res=1;
    while(b){
        if(b&1) res=res*a%MOD;
        a=a*a%MOD,b>>=1;
    }
    return res;
}

inline int inv(int a){return Pow(a,MOD-2);}

void hhhhauraorz(){
    cin >> n >> m;
    rep(m){
        int u,v;
        cin >> u >> v;
        u--,v--;
        adj[u].pb(v);
    }
    rep(n) if(!vis[i]) dfs(i);
    rep(n+1) b[i]=-1;
    for(auto i: ord){
        mex[i]=0;
        for(auto j: adj[i]) b[mex[j]]=i;
        while(b[mex[i]]==i) mex[i]++;
        bug(i,mex[i]);
    }
    rep(n) cnt[mex[i]]++;
    rep(512){
        rep1(j,512) arr[i][j]=cnt[i^j];
        arr[i][512]=!!i;
        arr[i][i]=(arr[i][i]-n-1+MOD)%MOD;
    }
    rep(512){
        int x;
        rep1(j,512){
            if(arr[i][j]){
                x=j;
                break;
            }
        }
        if(!i) bug(arr[0][x]);
        int y=inv(arr[i][x]);
        rep1(j,513) arr[i][j]=arr[i][j]*y%MOD;
        if(!i) bug(arr[0][x]);
        rep1(j,512) if(i!=j){
            y=(MOD-arr[j][x])%MOD;
            #pragma GCC ivdep
            rep1(k,513) arr[j][k]=(arr[j][k]+arr[i][k]*y)%MOD;
            assert(!arr[j][x]);
        }
    }
    print((MOD-arr[0][512])%MOD);
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    #ifdef i_am_noob
    freopen("input1.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    freopen("output2.txt","w",stderr);
    #endif
    int t;
    #ifdef wiwihorz
    cin >> t;
    #else
    t=1;
    #endif
    while(t--) hhhhauraorz(); 
    return 0;
}