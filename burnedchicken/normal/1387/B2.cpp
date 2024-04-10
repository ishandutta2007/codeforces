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
int n,u,v,ans[maxn],siz[maxn],dep[maxn],G,maxx=0,x,y;
vector<int> adj[maxn],vec;
bool vis[maxn]={false},deleted[maxn]={false};
set<int> alive;
set<pii> st[maxn],st1;

void dfs(int u, int pa){
    siz[u]=1;
    for(auto v: adj[u]) if(v!=pa&&(!deleted[v])){
        dfs(v,u);
        siz[u]+=siz[v];
    }
}

void dfs2(int u, int pa){
    dep[u]=pa==-1?0:dep[pa]+1;
    for(auto v: adj[u]) if(v!=pa&&(!deleted[v])) dfs2(v,u);
}

void dfs3(int u, int pa, int rt){
    st[rt].insert({dep[u],u});
    for(auto v: adj[u]) if(v!=pa&&(!deleted[v])) dfs3(v,u,rt);
}

int getG(int u, int pa, int _n){
    for(auto v: adj[u]) if(v!=pa&&(!deleted[v])&&siz[v]>_n/2) return getG(v,u,_n);
    return u;
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n;
    rep(n-1){
        cin >> u >> v;
        u--,v--;
        adj[u].pb(v),adj[v].pb(u);
    }
    rep(n) alive.insert(i);
    dfs(0,-1);
    G=getG(0,-1,n);
    rep(n) maxx+=2*min(siz[i],n-siz[i]);
    while(!alive.empty()){
        if(sz(alive)==2){
            ans[*alive.begin()]=*alive.rbegin();
            ans[*alive.rbegin()]=*alive.begin();
            break;
        }
        dfs2(G,-1);
        vec.clear();
        for(auto u: adj[G]) if(!deleted[u]) vec.pb(u);
        rep(sz(vec)) st[i].clear();
        rep(sz(vec)) dfs3(vec[i],G,i);
        rep(sz(vec)) st1.insert({sz(st[i]),i});
        while(sz(alive)>=4&&sz(st1)>=2){
            x=(*st1.rbegin()).second;
            y=(*++st1.rbegin()).second;
            st1.erase({sz(st[x]),x});st1.erase({sz(st[y]),y});
            u=(*st[x].rbegin()).second;
            v=(*st[y].rbegin()).second;
            deleted[u]=deleted[v]=true;
            alive.erase(u),alive.erase(v);
            ans[u]=v,ans[v]=u;
            st[x].erase({dep[u],u});
            st[y].erase({dep[v],v});
            if(!st[x].empty()) st1.insert({sz(st[x]),x});
            if(!st[y].empty()) st1.insert({sz(st[y]),y});
        }
        if(sz(alive)==3){
            if(sz(st1)==2){
                u=vec[(*st1.rbegin()).second];
                v=vec[(*++st1.rbegin()).second];
            }
            else{
                x=(*st1.rbegin()).second;
                u=vec[x];
                v=(*st[x].rbegin()).second;
            }
            ans[u]=G,ans[G]=v,ans[v]=u;
            break;
        }
        dfs(*alive.begin(),-1);
        G=getG(*alive.begin(),-1,sz(alive));
    }
    print1(maxx);
    rep(n) print0(ans[i]+1);
    cout << "\n";
    return 0;
}