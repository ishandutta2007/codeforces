#include <bits/stdc++.h>
#include <bits/extc++.h>

#define ll long long
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
#define inf 2000000000
//#define inf 4000000000000000000
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
const int maxn=500005;
//i_am_noob
int n,m,k,u,v,a[maxn],cnt=0;
ll ans;
vector<int> adj[maxn],fliped,vec2;
vector<pii> vec;
map<pii,vector<pii>> mm;
bool alive[maxn],vis[maxn],same[maxn],flag;

int fa[maxn];
vector<int> child[maxn];
int Find(int _x){return fa[_x]==_x?_x:Find(fa[_x]);}

void dfs(int u, int pa, int rt){
    vis[u]=true;
    fa[u]=rt;
    child[rt].pb(u);
    same[u]=pa==-1?0:1^same[pa];
    for(auto v: adj[u]){
        if(vis[v]){
            if(same[u]==same[v]){
                alive[a[u]]=false;
                return;
            }
            continue;
        }
        else dfs(v,u,rt);
        if(!alive[a[u]]) return;
    }
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n >> m >> k;
    rep(n) cin >> a[i];
    rep(n) a[i]--;
    rep(m){
        cin >> u >> v;
        u--,v--;
        if(a[u]>a[v]) swap(u,v);
        if(a[u]==a[v]) adj[u].pb(v),adj[v].pb(u);
        else mm[{a[u],a[v]}].pb({u,v});
    }
    rep(n) fa[i]=i;
    rep(k) alive[i]=true;
    rep(n) if((!vis[i])&&alive[a[i]]) dfs(i,-1,i);
    rep(k) if(alive[i]) cnt++;
    ans=1ll*cnt*(cnt-1)/2;
    for(auto p: mm){
        int k1=p.first.first,k2=p.first.second;
        if(!(alive[k1]&&alive[k2])) continue;
        flag=true;
        vec.clear();
        fliped.clear();
        vec2.clear();
        for(auto [u,v]: p.second){
            int uu=Find(u),vv=Find(v);
            if(sz(child[uu])<sz(child[vv])) swap(uu,vv);
            if(uu==vv){
                if(!(same[u]^same[v])){
                    flag=false;
                    break;
                }
                continue;
            }
            vec.pb({uu,vv});
            vec2.pb(sz(child[vv]));
            fa[vv]=uu;
            if(same[u]==same[v]){
                fliped.pb(1);
                for(auto i: child[vv]) same[i]^=1;
            }
            else fliped.pb(0);
            for(auto i: child[vv]) child[uu].pb(i);
        }
        if(!flag) ans--;
        while(sz(vec)){
            int vv=vec.back().second;
            fa[vv]=vec.back().second;
            if(fliped.back()) for(auto j: child[vec.back().second]) same[j]^=1;
            rep1(j,vec2.back()) child[vec.back().first].pop_back();
            vec.pop_back();
            vec2.pop_back();
            fliped.pop_back();
        }
    }
    print1(ans);
    return 0;
}