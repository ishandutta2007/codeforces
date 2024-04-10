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
int n,m,k,u,v,e[200005][2],fa[maxn],dep[maxn],odd=0,even=0;
bool vis[maxn]={false};
vector<int> adj[maxn],vec,vec1,vec2;
set<int> st;

void dfs(int u, int x){
    vis[u]=true;
    fa[u]=x;
    dep[u]=(x==-1?0:dep[x]+1);
    vec.pb(u);
    if(sz(vec)<=k){
        if(dep[u]%2) odd++;
        else even++;
        st.insert(u);
    }
    for(auto v: adj[u]) if(v!=x&&(!vis[v])){
        dfs(v,u);
    }
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n >> m >> k;
    rep(m){
        cin >> u >> v;
        u--,v--;
        e[i][0]=u,e[i][1]=v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(0,-1);
    rep(m) if(st.count(e[i][0])&&st.count(e[i][1])) if(e[i][0]!=fa[e[i][1]]&&e[i][1]!=fa[e[i][0]]){
        if(dep[e[i][0]]>dep[e[i][1]]) swap(e[i][0],e[i][1]);
        while(dep[e[i][1]]>dep[e[i][0]]){
            vec2.pb(e[i][1]);
            e[i][1]=fa[e[i][1]];
        }
        while(e[i][0]!=e[i][1]){
            vec1.pb(e[i][0]),vec2.pb(e[i][1]);
            e[i][0]=fa[e[i][0]],e[i][1]=fa[e[i][1]];
        }
        vec1.pb(e[i][0]);
        reverse(all(vec2));
        for(auto j: vec2) vec1.pb(j);
        print1(2);
        print1(sz(vec1));
        for(auto j: vec1) print0(j+1);
        cout << "\n";
        return 0;
    }
    print1(1);
    k=k+1>>1;
    if(odd>even){
        for(auto i: st) if(dep[i]%2){
            print0(i+1);
            k--;
            if(!k) break;
        }
    }
    else{
        for(auto i: st) if(dep[i]%2==0){
            print0(i+1);
            k--;
            if(!k) break;
        }
    }
    cout << "\n";
    return 0;
}