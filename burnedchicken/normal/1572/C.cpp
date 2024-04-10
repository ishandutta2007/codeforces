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
const int MOD=Mod;
const int maxn=3005;

//i_am_noob
#define wiwihorz  

int n,dp[maxn][maxn],nxt[maxn],pre[maxn];
vector<int> vec,vec1[maxn];
bool vis[maxn][maxn];

int solve(int l, int r){
    bug(l,r);
    if(l>=r) return 0;
    if(vis[l][r]) return dp[l][r];
    vis[l][r]=1;
    dp[l][r]=max(solve(l+1,r),solve(l,r-1));
    for(int i=l; nxt[i]<=r; i=nxt[i]) chkmax(dp[l][r],dp[l+1][nxt[i]-1]+dp[nxt[i]][r]+1);
    for(int i=r; pre[i]>=l; i=pre[i]) chkmax(dp[l][r],dp[pre[i]+1][r-1]+dp[l][pre[i]]+1);
    return dp[l][r];
}

void orzck(){
    cin >> n;
    vec.clear();
    rep(n) vec1[i].clear();
    rep(n){
        int x;
        cin >> x;
        x--;
        if(vec.empty()||vec.back()!=x){
            vec1[x].pb(sz(vec));
            vec.pb(x);
        }
    }
    int m=n;
    rep(n) rep1(j,n) vis[i][j]=0;
    n=sz(vec);
    bug(n);
    rep(n) nxt[i]=n,pre[i]=-1;
    rep(m) if(sz(vec1[i])){
        rep1(j,sz(vec1[i])-1){
            nxt[vec1[i][j]]=vec1[i][j+1];
            pre[vec1[i][j+1]]=vec1[i][j];
        }
    }
    print(n-1-solve(0,n-1));
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