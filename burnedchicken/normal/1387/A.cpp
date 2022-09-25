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
#define eps 1e-12
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
int n,m,u,v,w;
pii val[maxn];
vector<int> vec;
vector<pii> adj[maxn];
ld x,ans[maxn],l,r,mid1,mid2;
bool vis[maxn]={false},flag;

void dfs(int u){
    vec.pb(u);
    vis[u]=true;
    for(auto p: adj[u]){
        v=p.first;
        if(vis[v]){
            if(val[u].second==-val[v].second){
                if(val[u].first+val[v].first!=p.second){
                    print1("NO");
                    exit(0);
                }
            }
            else{
                if(flag){
                    if(abs(x-((ld)(p.second)-val[u].first-val[v].first)/((ld)(val[v].second)+val[u].second))>eps){
                        print1("NO");
                        exit(0);
                    }
                }
                else{
                    x=((ld)(p.second)-val[u].first-val[v].first)/((ld)(val[v].second)+val[u].second);
                    flag=true;
                }
            }
        }
        else{
            val[v]={p.second-val[u].first,-val[u].second};
            dfs(v);
        }
    }
}

ld sum(ld _x, vector<int>& vec){
    ld ret=0;
    for(auto i: vec) ret+=abs(val[i].first+_x*val[i].second);
    return ret;
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cout << fixed << setprecision(15);
    cin >> n >> m;
    rep(m){
        cin >> u >> v >> w;
        u--,v--;
        adj[u].pb({v,w}),adj[v].pb({u,w});
    }
    rep(n) if(!vis[i]){
        vec.clear();
        val[i]={0,1};
        flag=false;
        dfs(i);
        //for(auto j: vec) print2(val[j].first,val[j].second);
        if(flag) for(auto j: vec) ans[j]=val[j].first+x*val[j].second;
        else{
            l=-inf,r=inf;
            while(r-l>eps){
                mid1=(l+l+r)/3,mid2=(l+r+r)/3;
                if(sum(mid1,vec)>sum(mid2,vec)) l=mid1;
                else r=mid2;
            }
            for(auto j: vec) ans[j]=val[j].first+l*val[j].second;
        }
    }
    print1("YES");
    rep(n) print0(ans[i]);
    cout << "\n";
    return 0;
}