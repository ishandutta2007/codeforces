#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2,tune=native")

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
template<typename T> void _do(T && x) {cerr << x << endl;}
template<typename T, typename ...S> void _do(T && x, S&&...y) {cerr << x << ", "; _do(y...);}
#else
#define bug(...) 826
#endif
template<typename T> void print(T && x) {cout << x << "\n";}
template<typename T, typename... S> void print(T && x, S&&... y) {cout << x << ' ';print(y...);}

const int Mod=1000000007,Mod2=998244353;
const int MOD=Mod2;
const int maxn=1000005;
//i_am_noob
//#define wiwihorz
int n,f[6],q,dp[3][maxn],pow10[6]={1,10,100,1000,10000,100000};

void hhhhauraorz(){
    cin >> n;
    rep(6) cin >> f[i];
    dp[2][0]=0;
    rep2(i,1,maxn) dp[2][i]=-inf;
    rep1(j,6){
        rep(maxn) dp[0][i]=dp[1][i]=dp[2][i];
        if(n>1) rep1(_,2){
            rep(pow10[j]) dp[1][i]=dp[0][i];
            rep2(i,pow10[j],maxn) dp[1][i]=max(dp[0][i],dp[0][i-pow10[j]]);
            rep(maxn) dp[0][i]=dp[1][i];
        }
        int cnt=(n-1)*3;
        rep1(k,21){
            if(pow2(k)>cnt||3*pow10[j]*pow2(k)>=maxn) break;
            rep(3*pow10[j]*pow2(k)) dp[1][i]=dp[0][i];
            rep2(i,3*pow10[j]*pow2(k),maxn) dp[1][i]=max(dp[0][i],dp[0][i-3*pow10[j]*pow2(k)]+f[j]*pow2(k));
            rep(maxn) dp[0][i]=dp[1][i];
            cnt-=pow2(k);
        }
        if(3*pow10[j]*cnt<maxn){
            rep(3*pow10[j]*cnt) dp[1][i]=dp[0][i];
            rep2(i,3*pow10[j]*cnt,maxn) dp[1][i]=max(dp[0][i],dp[0][i-3*pow10[j]*cnt]+f[j]*cnt);
            rep(maxn) dp[0][i]=dp[1][i];
        }
        rep1(k,10) if((9*(n-1)+k)*pow10[j]<maxn){
            rep2(i,(9*(n-1)+k)*pow10[j],maxn) dp[1][i]=max(dp[1][i],dp[2][i-(9*(n-1)+k)*pow10[j]]+f[j]*(3*(n-1))+(k%3?0:f[j]*k/3));
        }
        rep(maxn) dp[2][i]=dp[1][i];
    }
    cin >> q;
    while(q--){
        int x;
        cin >> x;
        print(dp[1][x]);
    }
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    int t;
    #ifdef wiwihorz
    cin >> t;
    #else
    t=1;
    #endif
    while(t--) hhhhauraorz();
    return 0;
}