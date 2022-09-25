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
#define pi 3.14159265358979323846264338328
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

const int maxn=200005;
//i_am_noob
int t,n,a[maxn],b[maxn],cnt[maxn],dep[maxn];
bool flag,vis[maxn];
vector<pii> adj[maxn];
vector<int> ans,vec1,vec2;
set<int> st;

void dfs(int u, int pa){
    vis[u]=true;
    dep[u]=(pa==-1?0:dep[pa]+1);
    for(auto p: adj[u]){
        int v=p.first;
        st.insert(p.second);
        if(vis[v]) continue;
        dfs(v,u);
    }
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        rep(n) cin >> a[i];
        rep(n) cin >> b[i];
        memset(cnt,0,8*n),memset(vis,0,n),memset(dep,0,8*n);
        rep(n) cnt[--a[i]]++,cnt[--b[i]]++;
        flag=false;
        rep(n) if(cnt[i]!=2) flag=true;
        if(flag){
            print1(-1);
            continue;
        }
        rep(n) adj[i].clear();
        rep(n){
            if(a[i]==b[i]){
                vis[a[i]]=true;
                continue;
            }
            adj[a[i]].pb(mp(b[i],i));
            adj[b[i]].pb(mp(a[i],i));
        }
        ans.clear();
        rep(n){
            if(vis[i]) continue;
            if(adj[i][0].first==adj[i][1].first){
                if(adj[i][0].first<i){
                    if(a[adj[i][0].second]==a[adj[i][1].second]) ans.pb(adj[i][0].second);
                }
                continue;
            }
            st.clear(),vec1.clear(),vec2.clear();
            dfs(i,-1);
            for(auto j: st){
                if(dep[a[j]]==sz(st)-1&&dep[b[j]]==0) vec1.pb(j);
                else if(dep[a[j]]==0&&dep[b[j]]==sz(st)-1) vec2.pb(j);
                else if(dep[a[j]]<dep[b[j]]) vec1.pb(j);
                else vec2.pb(j);
            }
            if(sz(vec1)>sz(vec2)) for(auto j: vec2) ans.pb(j);
            else for(auto j: vec1) ans.pb(j);
        }
        //rep(n) print0(dep[i]);
        //cout << "\n";
        print1(sz(ans));
        for(auto i: ans) print0(i+1);
        cout << "\n";
    }
    return 0;
}