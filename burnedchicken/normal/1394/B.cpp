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
const int maxn=200005;
//i_am_noob
int n,m,k,u,v,w,ans=0,b[10];
unsigned int hs[maxn][10],a[10][10][10],x[10]={0},y[10]={0};
vector<int> vec[10];
vector<pii> adj[maxn];
bool flag;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n >> m >> k;
    rep(m){
        cin >> u >> v >> w;
        u--,v--;
        adj[u].pb({w,v});
    }
    rep(n) sort(all(adj[i]));
    rep(n){
        rep1(j,10) hs[i][j]=rng();
        rep1(j,10) x[j]^=hs[i][j];
    }
    rep(n) vec[sz(adj[i])].pb(i);
    rep2(i,1,k+1) rep1(j,i){
        rep1(ii,10) a[i][j][ii]=0;
        for(auto u: vec[i]) rep1(ii,10) a[i][j][ii]^=hs[adj[u][j].second][ii];
    }
    rep2(i,1,k+1) b[i]=0;
    while(1){
        rep(10) y[i]=0;
        rep2(i,1,k+1) rep1(j,10) y[j]^=a[i][b[i]][j];
        flag=true;
        rep(10) if(x[i]-y[i]) flag=false;
        if(flag) ans++;
        flag=false;
        rep3(i,k,1){
            if(b[i]<i-1){
                b[i]++;
                break;
            }else if(i>1){
                b[i]=0;
            }else{
                flag=true;
            }
        }
        if(flag) break;
    }
    print1(ans);
    return 0;
}