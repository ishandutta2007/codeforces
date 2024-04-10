#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2,tune=native")

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
#define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
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
const int maxn=100005;
//i_am_noob
template<int maxn>
struct dsu{
    int par[maxn],siz[maxn],val[maxn];
    dsu(){rep(maxn) par[i]=i,siz[i]=1,val[i]=0;}
    void init(int n){rep(n) par[i]=i,siz[i]=1;}
    int Find(int x){return x==par[x]?x:par[x]=Find(par[x]);}
    int Union(int x, int y){
        x=Find(x),y=Find(y);
        if(x==y) return -1;
        if(siz[x]<siz[y]) swap(x,y);
        par[y]=x;
        siz[x]+=siz[y];
        val[x]+=val[y];
        return val[x];
    }
};
int n,m,k,a[maxn],ans;
dsu<maxn> d;

struct edge{
    int u,v,w;
}e[maxn];

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    #ifdef i_am_noob
    freopen("input1.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    #endif
    cin >> n >> m >> k;
    rep(k) cin >> a[i];
    rep(k) a[i]--;
    rep(m){
        cin >> e[i].u >> e[i].v >> e[i].w;
        e[i].u--,e[i].v--;
    }
    sort(e,e+m,[](edge& i, edge& j){return i.w<j.w;});
    rep(k) d.val[a[i]]=1;
    rep(m) if(d.Union(e[i].u,e[i].v)==k){
        ans=e[i].w;
        break;
    }
    rep(k) print0(ans);
    cout << "\n";
    return 0;
}