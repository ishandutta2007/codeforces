#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

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
#define mp make_pair
//#define inf 2000000000
#define inf 8000000000000000000
#define eps 1e-9
#define sz(a) ((int)a.size())
#define pow2(x) (1ll<<(x))
#define ceiling(a,b) (((a)+(b)-1)/(b))
#define print0(a) cout << (a) << ' '
#define print1(a) cout << (a) << '\n'
#define print2(a,b) cout << (a) << ' ',print1(b)
#define print3(a,b,c) cout << (a) << ' ',print2(b,c)
#define print4(a,b,c,d) cout << (a) << ' ',print3(b,c,d)
#define ykh mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>

using namespace std;
using namespace __gnu_pbds;

const int Mod=1000000007,Mod2=998244353;
const int MOD=Mod2;
const int maxn=100005;
//i_am_noob
int n,u,v,dep[maxn],fa[maxn],k=0,ans[maxn];
vector<int> adj[maxn],vec[maxn];
set<pii> st;
bool used[maxn]={false};

void dfs(int u, int pa){
    fa[u]=pa;
    dep[u]=pa==-1?0:dep[pa]+1;
    for(auto v: adj[u]) if(v!=pa) dfs(v,u);
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n;
    rep(n-1){
        cin >> u >> v;
        u--,v--;
        adj[u].pb(v),adj[v].pb(u);
    }
    dfs(0,-1);
    rep(n) st.insert({dep[i],i});
    rep(n) ans[i]=-1;
    while(sz(st)>1){
        u=(*st.rbegin()).second;
        u=fa[u];
        vec[k].pb(u);
        used[u]=true;
        st.erase({dep[u],u});
        for(auto v: adj[u]) if(v!=fa[u]&&(!used[v])){
            vec[k].pb(v);
            used[v]=true;
            st.erase({dep[v],v});
        }
        k++;
    }
    if(sz(st)==1) vec[k-1].pb(0);
    rep(k){
        rep1(j,sz(vec[i])-1) ans[vec[i][j]]=vec[i][j+1];
        ans[vec[i].back()]=vec[i][0];
    }
    print1(2*n-2*k);
    rep(n) print0(ans[i]+1);
    cout << "\n";
    return 0;
}