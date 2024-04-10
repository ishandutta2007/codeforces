#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

#define int long long
#define ull unsigned long long
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
#define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
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
const int MOD=Mod;
const int maxn=300005;
//i_am_noob
int t,n,m,u,v,p;
vector<int> adj[maxn],ans,vec;
bool vis[maxn],flag;
set<int> st;

void dfs(int u){
    vis[u]=true;
    for(auto v: adj[u]) if(!vis[v]) dfs(v);
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    #ifdef i_am_noob
    freopen("input1.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    #endif
    cin >> t;
    while(t--){
        cin >> n >> m;
        rep(n) adj[i].clear();
        rep(m){
            cin >> u >> v;
            u--,v--;
            adj[u].pb(v),adj[v].pb(u);
        }
        rep(n) vis[i]=0;
        dfs(0);
        flag=false;
        rep(n) if(!vis[i]) flag=true;
        if(flag){
            print("NO");
            continue;
        }
        rep(n) vis[i]=0;
        ans.clear();
        ans.pb(0);
        st.clear();
        vis[0]=1;
        for(auto u: adj[0]) vis[u]=1;
        for(auto u: adj[0]) for(auto v: adj[u]) if(!vis[v]) st.insert(v);
        while(!st.empty()){
            p=*st.begin();
            st.erase(p);
            if(vis[p]) continue;
            ans.pb(p);
            vis[p]=1;
            vec.clear();
            for(auto u: adj[p]) if(!vis[u]) vis[u]=1,vec.pb(u);
            for(auto u: vec) for(auto v: adj[u]) if(!vis[v]) st.insert(v);
        }
        print("YES");
        print(sz(ans));
        for(auto i: ans) print0(i+1);
        cout << "\n";
    }
    return 0;
}