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
#define eps 1e-9
#define sz(a) ((int)a.size())
#define pow2(x) (1ll<<(x))
#define ceiling(a,b) (((a)+(b)-1)/(b))
#define print0(a) cout << (a) << ' '
#define print1(a) cout << (a) << '\n'
#define print2(a,b) cout << (a) << ' ',print1(b)
#define print3(a,b,c) cout << (a) << ' ',print2(b,c)
#define print4(a,b,c,d) cout << (a) << ' ',print3(b,c,d)
#ifdef i_am_noob
#define debug(a) print2(#a,a)
#else
#define debug(a)
#endif
#define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>

using namespace std;
using namespace __gnu_pbds;

const int Mod=1000000007,Mod2=998244353;
const int MOD=Mod;

inline int add(int a, int b){return (a+b>=MOD?a+b-MOD:a+b);}
inline int sub(int a, int b){return (a+MOD-b>=MOD?a-b:a+MOD-b);}
int Pow(int a, int b){
	if(!b) return 1;
	int tmp=Pow(a*a%MOD,b>>1);
	return (b&1?tmp*a%MOD:tmp);
}
inline int inverse(int n){return Pow(n,MOD-2);}

const int maxn=100005;
//i_am_noob
int t,n,m,u,v,b[maxn],dep[maxn],fa[maxn][17],cnt[maxn],low[maxn];
vector<int> adj[maxn],bin[maxn],bout[maxn],ans;
bool vis[maxn],flag,flag1,ok[maxn];
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void dfs(int u, int x){
    vis[u]=true;
    dep[u]=(x==-1?0:dep[x]+1);
    fa[u][0]=x;
    rep2(i,1,17) fa[u][i]=(fa[u][i-1]==-1?-1:fa[fa[u][i-1]][i-1]);
    for(auto v: adj[u]){
        if(vis[v]){
            if(dep[v]>=dep[u]){
                flag1=true;
                return;
            }
            int tmp=u;
            rep(17) if((dep[tmp]-dep[v])&pow2(i)){
                tmp=fa[tmp][i];
                if(dep[tmp]==dep[v]) break;
            }
            if(tmp!=v){
                flag1=true;
                return;
            }
            continue;
        }
        dfs(v,u);
        if(flag1) return;
    }
}

void dfs2(int u, int x){
    cnt[u]=sz(bout[u])-sz(bin[u]),low[u]=4e18;
    for(auto v: bout[u]) low[u]=min(low[u],dep[v]);
    for(auto v: adj[u]) if(u==fa[v][0]){
        dfs2(v,u);
        cnt[u]+=cnt[v];
        low[u]=min(low[u],low[v]);
    }
}

void dfs3(int u, int x){
    if(x==-1) ok[u]=true;
    else{
        if(cnt[u]!=1) ok[u]=false;
        else{
            int tmp=u;
            rep(17) if((dep[tmp]-low[u])&pow2(i)){
                tmp=fa[tmp][i];
                if(dep[tmp]==low[u]) break;
            }
            if(ok[tmp]) ok[u]=true;
            else ok[u]=false;
        }
    }
    for(auto v: adj[u]) if(u==fa[v][0]) dfs3(v,u);
}

bool solve(int x){
    rep(n) vis[i]=false;
    flag1=false;
    dfs(x,-1);
    if(flag1) return false;
    rep(n) if(!vis[i]) return false;
    rep(n) for(auto u: adj[i]) if(i!=fa[u][0]) bin[u].pb(i),bout[i].pb(u);
    dfs2(x,-1);
    ans.clear();
    dfs3(x,-1);
    rep(n) if(ok[i]) ans.pb(i);
    if(5*sz(ans)<n){
        print1(-1);
        return true;
    }
    for(auto u: ans) print0(u+1);
    cout << "\n";
    return true;
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> m;
        rep(n) adj[i].clear(),bin[i].clear(),bout[i].clear();
        rep(m){
            cin >> u >> v;
            u--,v--;
            adj[u].pb(v);
        }
        rep(n) b[i]=i;
        shuffle(b,b+n,rng);
        flag=false;
        rep(min(n,30ll)) if(solve(b[i])){
            flag=true;
            break;
        }
        if(!flag) print1(-1);
    }
    return 0;
}