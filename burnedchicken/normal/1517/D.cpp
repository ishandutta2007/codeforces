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
template<typename T> void _do(T && x) {cerr << x << endl;}
template<typename T, typename ...S> void _do(T && x, S&&...y) {cerr << x << ", "; _do(y...);}
#else
#define bug(...) 826
#endif
template<typename T> void print(T && x) {cout << x << "\n";}
template<typename T, typename... S> void print(T && x, S&&... y) {cout << x << ' ';print(y...);}

const int Mod=1000000007,Mod2=998244353;
const int MOD=666013;
const int maxn=505;

//i_am_noob
//#define wiwihorz  
int n,m,t,w1[maxn][maxn],w2[maxn][maxn],dp[maxn][maxn][12];
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};

bool ingrid(int x, int y){return x>=0&&x<n&&y>=0&&y<m;}

void orzck(){
    cin >> n >> m >> t;
    rep(n) rep1(j,m-1) cin >> w1[i][j];
    rep(n-1) rep1(j,m) cin >> w2[i][j];
    if(t&1){
        rep(n){
            rep1(j,m) print0(-1);
            cout << "\n";
        }
        return;
    }
    t>>=1;
    rep(n) rep1(j,m) dp[i][j][0]=0;
    rep2(k,1,11) rep(n) rep1(j,m){
        dp[i][j][k]=inf;
        rep1(ii,4){
            int newx=i+dx[ii],newy=j+dy[ii];
            if(ingrid(newx,newy)){
                dp[i][j][k]=min(dp[i][j][k],dp[newx][newy][k-1]+(newx==i?w1[i][min(newy,j)]:w2[min(newx,i)][j]));
            }
        }
    }
    rep(n){
        rep1(j,m) print0(dp[i][j][t]*2);
        cout << "\n";
    }
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