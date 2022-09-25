#include <bits/stdc++.h>
//#include <bits/extc++.h>
using namespace std;
//using namespace __gnu_pbds;

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
//#define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
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
const int maxn=300005;
//i_am_noob
int n,m,u,v,e[maxn][2],ans[maxn],cnt,deg[maxn],cur=-1,iord[maxn];
vector<int> adj[maxn],radj[maxn],ord;
unordered_set<int> st;
bool vis[maxn];

void rdfs(int u){
    vis[u]=true;
    for(auto v: radj[u]) if(!vis[v]) rdfs(v);
    ord.pb(u);
}

inline void add(int u){
    if(!deg[u]) st.erase(u);
    deg[u]++;
}

inline void sub(int u){
    deg[u]--;
    if(!deg[u]) st.insert(u);
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n >> m;
    rep(m){
        cin >> u >> v;
        u--,v--;
        e[i][0]=u,e[i][1]=v;
        radj[v].pb(u);
    }
    rep(n) if(!vis[i]) rdfs(i);
    rep(n) radj[i].clear();
    rep(n) iord[ord[i]]=i;
    rep(m) adj[iord[e[i][0]]].pb(iord[e[i][1]]),radj[iord[e[i][1]]].pb(iord[e[i][0]]);
    cur=-1;
    rep2(i,1,n){
        st.insert(i-1);
        for(auto v: radj[i]) add(v);
        if(cur>=0&&!st.count(cur)){
            for(auto v: radj[cur]) add(v);
            cur=-1;
        }
        if(sz(st)==0) continue;
        if(cur==-1&&sz(st)==1){
            cur=*st.begin();
            for(auto v: radj[cur]) sub(v);
        }
        if(sz(st)>=2) ans[i]+=2;
        else ans[i]++;
    }
    memset(deg,0,sizeof(deg));
    cur=-1;
    st.clear();
    rep3(i,n-2,0){
        st.insert(i+1);
        for(auto v: adj[i]) add(v);
        if(cur>=0&&!st.count(cur)){
            for(auto v: adj[cur]) add(v);
            cur=-1;
        }
        if(sz(st)==0) continue;
        if(cur==-1&&sz(st)==1){
            cur=*st.begin();
            for(auto v: adj[cur]) sub(v);
        }
        if(sz(st)>=2) ans[i]+=2;
        else ans[i]++;
    }
    rep(n) if(ans[i]<=1) cnt++;
    print(cnt);
    return 0;
}