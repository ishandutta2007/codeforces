#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2,fma,tune=native")

#define ll long long
//#define int ll
#define ull unsigned ll
#define ld long double
#define rep(a) rep1(i,a)
#define rep1(i,a) rep2(i,0,a)
#define rep2(i,b,a) for(int i=(b); i<((int)(a)); i++)
#define rep3(i,b,a) for(int i=(b); i>=((int)(a)); i--)
#define all(a) a.begin(),a.end()
#define pii pair<int,int>
#define pb push_back
#define inf 1010000000
//#define inf 4000000000000000000
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
template<typename T> void _do(T && x) {cerr << x << endl;}
template<typename T, typename ...S> void _do(T && x, S&&...y) {cerr << x << ", "; _do(y...);}
#else
#define bug(...) 826
#endif
template<typename T> void print(T && x) {cout << x << "\n";}
template<typename T, typename... S> void print(T && x, S&&... y) {cout << x << ' ';print(y...);}

const int Mod=1000000007,Mod2=998244353;
const int MOD=Mod2;
const int maxn=605;

//i_am_noob
//#define wiwihorz  
int n,m,val[maxn][maxn],dis[maxn];
vector<pii> adj[maxn];
bool vis[maxn];

void orzck(){
    cin >> n >> m;
    rep(m){
        int a,b,c;
        cin >> a >> b >> c;
        adj[a].pb({b,c});
    }
    rep(n){
        rep1(j,n) val[i][j]=inf;
        for(auto& [v,w]: adj[i]){
            rep1(j,n-v) val[i][v+j]=min(val[i][v+j],w+j);
            rep1(j,v) val[i][j]=min(val[i][j],w+n-v+j);
        }
        rep1(j,n) bug(i,j,val[i][j]);
    }
    rep(n){
        rep1(j,n) dis[j]=inf,vis[j]=0;
        dis[i]=0;
        int u=i;
        rep1(_,n-1){
            vis[u]=1;
            int k=dis[u]%n;
            rep1(j,n-k) dis[k+j]=min(dis[k+j],dis[u]+val[u][j]);
            rep1(j,k) dis[j]=min(dis[j],dis[u]+val[u][n-k+j]);
            int minn=inf,v;
            rep1(j,n) if((!vis[j])&&dis[j]<minn) minn=dis[j],v=j;
            u=v;
        }
        rep1(j,n) print0(dis[j]);
        cout << "\n";
    }
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