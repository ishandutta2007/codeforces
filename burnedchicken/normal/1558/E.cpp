#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2,fma,tune=native")

#define ll long long
#define int ll
#define ull unsigned ll
#define ld long double
#define rep(a) rep1(i,a)
#define rep1(i,a) rep2(i,0,a)
#define rep2(i,b,a) for(int i=(b); i<((int)(a)); i++)
#define rep3(i,b,a) for(int i=(b); i>=((int)(a)); i--)
#define chkmin(a,b) (a=min(a,b))
#define chkmax(a,b) (a=max(a,b))
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
#ifdef i_am_noob
#define bug(...) cerr << "#" << __LINE__ << ' ' << #__VA_ARGS__ << "- ", _do(__VA_ARGS__)
template<typename T> void _do(vector<T> x){for(auto i: x) cerr << i << ' ';cerr << "\n";}
template<typename T> void _do(set<T> x){for(auto i: x) cerr << i << ' ';cerr << "\n";}
template<typename T> void _do(unordered_set<T> x){for(auto i: x) cerr << i << ' ';cerr << "\n";}
template<typename T> void _do(T && x) {cerr << x << endl;}
template<typename T, typename ...S> void _do(T && x, S&&...y) {cerr << x << ", "; _do(y...);}
#else
#define bug(...) 826
#endif
template<typename T> void print(T && x) {cout << x << "\n";}
template<typename T, typename... S> void print(T && x, S&&... y) {cout << x << ' ';print(y...);}

const int Mod=1000000007,Mod2=998244353;
const int MOD=Mod2;
const int maxn=1005;

//i_am_noob
#define wiwihorz  

int n,m,a[maxn],b[maxn],c[maxn];
vector<int> adj[maxn];
bool vis[maxn];

void orzck(){
    cin >> n >> m;
    //assert(n==m||(n==5&&m==7));
    rep(n-1) cin >> a[i+1];
    rep(n-1) cin >> b[i+1];
    rep(n-1) a[i+1]++;
    rep(n) adj[i].clear();
    rep(m){
        int u,v;
        cin >> u >> v;
        u--,v--;
        adj[u].pb(v),adj[v].pb(u);
    }
    rep(n-1) c[i+1]=i+1;
    sort(c+1,c+n,[](int i, int j){return a[i]>a[j];});
    rep1(_,n){
        rep(n-1){
            int u=c[i+1];
            int cnt=0;
            for(auto v: adj[u]) if(a[v]<=a[u]+b[u]) cnt++;
            if(cnt==1){
                int minn=inf;
                for(auto v: adj[u]) if(a[v]>a[u]+b[u]) chkmin(minn,a[v]);
                a[u]=minn-b[u];
            }
            if(cnt==0){
                int minn=inf;
                for(auto v: adj[u]) if(a[v]>a[u]) chkmin(minn,a[v]);
                a[u]=minn;
            }
        }
    }
    rep(n-1) bug(i+1,a[i+1]);
    int l=0,r=7777714490;
    while(l<r){
        int mid=l+r>>1;
        int cur=mid;
        memset(vis,0,sizeof vis);
        vis[0]=1;
        int u=0;
        bug(mid);
        rep1(_,n){
            int flag=0;
            for(auto v: adj[u]) if(vis[v]) flag++;
            cur+=b[u];
            vis[u]=1;
            bug(u);
            if(flag>=2){
                bool ok=0;
                rep(n) if(cur>=a[i]&&!vis[i]){
                    bool flag2=0;
                    for(auto j: adj[i]) if(vis[j]) flag2=1;
                    if(flag2){
                        u=i;
                        ok=1;
                        break;
                    }
                }
                if(!ok) break;
            }
            else{
                bool ok=0;
                for(auto v: adj[u]) if(cur>=a[v]&&!vis[v]){
                    u=v;
                    ok=1;
                    break;
                }
                if(!ok) break;
            }
        }
        bool flag=1;
        rep(n) if(!vis[i]) flag=0;
        if(flag) r=mid;
        else l=mid+1;
    }
    print(l);
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    #ifdef i_am_noob
    freopen("input1.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    freopen("output2.txt","w",stderr);
    #endif
    cout << fixed << setprecision(15);
    int t;
    #ifdef wiwihorz
    cin >> t;
    #else
    t=1;
    #endif
    while(t--) orzck();
    return 0;
}