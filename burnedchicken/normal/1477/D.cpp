#include <bits/stdc++.h>
#include <bits/extc++.h>
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
const int maxn=500005;

//i_am_noob
#define wiwihorz  


using namespace __gnu_pbds;
gp_hash_table<int,null_type> adj[maxn];
int n,m,res1[maxn],res2[maxn],cur1,cur2;
bool good[maxn];
set<pii> st;

void Erase(int u){
    for(auto v: adj[u]){
        st.erase({sz(adj[v]),v});
        adj[v].erase(u);
        st.insert({sz(adj[v]),v});
    }
    st.erase({sz(adj[u]),u});
    adj[u].clear();
}

void orzck(){
    cin >> n >> m;
    rep(n) adj[i].clear();
    rep(m){
        int u,v;
        cin >> u >> v;
        u--,v--;
        adj[u].insert(v),adj[v].insert(u);
    }
    st.clear();
    rep(n) st.insert({sz(adj[i]),i});
    cur1=0,cur2=0;
    while(sz(st)){
        auto [de,u]=*st.rbegin();
        vector<int> vec1,vec2;
        gp_hash_table<int,null_type> st1,st2;
        st1.insert(u);
        for(auto [i,j]: st) st2.insert(j);
        st2.erase(u);
        for(auto v: adj[u]) st2.erase(v);
        if(sz(st2)){
            for(auto v: adj[u]) if(sz(adj[v])==sz(adj[u])) st1.insert(v);
            for(auto i: st2) for(auto j: adj[i]) st1.erase(j);
        }
        for(auto i: st1) res1[i]=++cur1;
        for(auto i: st2) res1[i]=++cur1;
        for(auto i: st2) res2[i]=++cur2;
        for(auto i: st1) res2[i]=++cur2;
        for(auto i: st1) Erase(i);
        for(auto i: st2) Erase(i);
    }
    rep(n) print0(res1[i]);
    cout << "\n";
    rep(n) print0(res2[i]);
    cout << "\n";
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