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
const int MOD=Mod;
const int maxn=200005;
//i_am_noob
int n,m,k,e[maxn][2],deg[maxn]={0},ans[maxn],u,v;
set<int> adj[maxn];
set<pii> st;

void Remove(int u){
    for(auto v: adj[u]){
        st.erase({sz(adj[v]),v});
        adj[v].erase(u);
        st.insert({sz(adj[v]),v});
    }
    st.erase({sz(adj[u]),u});
    adj[u].clear();
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n >> m >> k;
    rep(m){
        cin >> e[i][0] >> e[i][1];
        e[i][0]--,e[i][1]--;
        adj[e[i][0]].insert(e[i][1]),adj[e[i][1]].insert(e[i][0]);
    }
    rep(n) st.insert({sz(adj[i]),i});
    rep3(i,m-1,0){
        while(!st.empty()){
            u=(*st.begin()).second;
            if(sz(adj[u])>=k) break;
            Remove(u);
        }
        ans[i]=sz(st);
        if(adj[e[i][0]].count(e[i][1])){
            st.erase({sz(adj[e[i][0]]),e[i][0]});
            adj[e[i][0]].erase(e[i][1]);
            st.insert({sz(adj[e[i][0]]),e[i][0]});
            st.erase({sz(adj[e[i][1]]),e[i][1]});
            adj[e[i][1]].erase(e[i][0]);
            st.insert({sz(adj[e[i][1]]),e[i][1]});
        }
    }
    rep(m) print1(ans[i]);
    return 0;
}