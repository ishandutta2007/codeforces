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
const int maxn=1000005;
//i_am_noob
//#define wiwihorz  
int n,m;
vector<int> adj[maxn],res;
vector<vector<int>> vec;
bool vis[maxn];

void hhhhauraorz(){
    cin >> n >> m;
    rep(m){
        int u,v;
        cin >> u >> v;
        u--,v--;
        adj[u].pb(v);
    }
    vector<int> tmp;
    rep(n) if(!vis[i]){
        tmp={i};
        for(auto j: adj[i]) if(!vis[j]) tmp.pb(j),vis[j]=1;
        vec.pb(tmp);
    }
    memset(vis,0,sizeof vis);
    rep3(i,sz(vec)-1,0){
        auto& vec1=vec[i];
        if(!vis[vec1[0]]){
            res.pb(vec1[0]);
            vis[vec1[0]]=1;
            for(auto u: adj[vec1[0]]) vis[u]=1;
        }
    }
    print(sz(res));
    for(auto i: res) print0(i+1);
    cout << "\n";
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