#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2,fma,tune=native")

#define ll long long
#define int ll
#define ull unsigned ll
#define ld long double
#define rep(a) rep1(i,a)
#define rep1(i,a) rep2(i,0,a)
#define rep2(i,b,a) for(int i=(b); i<((int)(a)); i++)
#define rep3(i,b,a) for(int i=(b); i>=((int)(a)); i--)
#define all(a) a.begin(),a.end()
#define pii pair<int,int>
#define pb push_back
#define inf 1010000000
//#define inf 4000000000000000000
#define eps 1e-9
#define sz(a) ((int)a.size())
#define pow2(x) (1ll<<(x))
#define ceiling(a,b) (((a)+(b)-1)/(b))
#define print0(a) cout << (a) << ' '
#define ykh mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
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
const int maxn=2005;
//i_am_noob
//#define wiwihorz  
int dp[2][1<<22],good[1<<22];

void hhhhauraorz(){
    int n,x,y;
    cin >> n >> x >> y;
    if(x>y) swap(x,y);
    rep(1<<22) dp[0][i]=-inf;
    dp[0][0]=0;
    rep(1<<y){
        if(!((i|i>>y-x)&1)) good[i]=0;
        else good[i]=-1;
    }
    rep(x+y){
        rep1(mask,1<<y-1) dp[1][mask]=max(dp[0][mask<<1],dp[0][mask<<1|1]);
        rep2(mask,1<<y-1,1<<y) dp[1][mask]=-inf;
        rep1(mask,1<<y) dp[1][mask>>1|1<<y-1]=max(dp[1][mask>>1|1<<y-1],(dp[0][mask]+1)|good[mask]);
        rep1(mask,1<<y) dp[0][mask]=dp[1][mask];
    }
    rep(1<<y) dp[0][i]*=n/(x+y);
    rep(n%(x+y)){
        rep1(mask,1<<y-1) dp[1][mask]=max(dp[0][mask<<1],dp[0][mask<<1|1]);
        rep2(mask,1<<y-1,1<<y) dp[1][mask]=-inf;
        rep1(mask,1<<y) dp[1][mask>>1|1<<y-1]=max(dp[1][mask>>1|1<<y-1],(dp[0][mask]+1)|good[mask]);
        rep1(mask,1<<y) dp[0][mask]=dp[1][mask];
    }
    print(*max_element(dp[0],dp[0]+(1<<y)));
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    #ifdef i_am_noob
    freopen("input1.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    freopen("output2.txt","w",stderr);
    #endif
    int t;
    #ifdef wiwihorz
    cin >> t;
    #else
    t=1;
    #endif
    while(t--) hhhhauraorz();
    return 0;
}