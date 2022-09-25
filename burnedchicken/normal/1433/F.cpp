#include <bits/stdc++.h>
#include <bits/extc++.h>

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
#define inf 4000000000000000000
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
const int MOD=Mod;
const int maxn=72;
//i_am_noob
int n,m,k,a[maxn][maxn],dp[maxn][maxn][maxn][maxn],val[maxn][maxn],dp2[maxn][maxn];

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n >> m >> k;
    rep(n) rep1(j,m) cin >> a[i][j];
    rep(n){
        rep1(ii,m+1) rep1(jj,k) dp[i][0][ii][jj]=-inf;
        dp[i][0][0][0]=0;
        rep2(j,1,m+1) rep1(ii,m+1) rep1(jj,k){
            dp[i][j][ii][jj]=-inf;
            if(ii*2>m||ii>j) continue;
            if(ii) dp[i][j][ii][jj]=max(dp[i][j-1][ii][jj],dp[i][j-1][ii-1][(jj-a[i][j-1]+k*826)%k]+a[i][j-1]);
            else dp[i][j][ii][jj]=dp[i][j-1][ii][jj];
        }
    }
    rep(n) rep1(jj,k) val[i][jj]=-inf;
    rep(n) rep1(jj,k) rep1(j,m+1) rep1(ii,m+1) val[i][jj]=max(val[i][jj],dp[i][j][ii][jj]);
    rep1(j,k) dp2[0][j]=-inf;
    dp2[0][0]=0;
    rep2(i,1,n+1) rep1(j,k){
        dp2[i][j]=-inf;
        rep1(ii,k) dp2[i][j]=max(dp2[i][j],dp2[i-1][(j-ii+k*826)%k]+val[i-1][ii]);
    }
    print1(dp2[n][0]);
    //rep1(j,m+1) rep1(ii,m+1) rep1(jj,k) print4(j,ii,jj,dp[0][j][ii][jj]);
    return 0;
}