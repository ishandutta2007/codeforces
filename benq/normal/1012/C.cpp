
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()

const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 5001;

int n, a[MX], dp[MX][2501][3];

int to (int x, int y) {
    return max(x-y,0);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n; FOR(i,1,n+1) cin >> a[i];
    F0R(j,2501) F0R(k,3) dp[0][j][k] = MOD;
    dp[0][0][2] = 0;
    FOR(i,1,n+1) F0R(j,2501) {
        dp[i][j][2] = min(dp[i-1][j][1],dp[i-1][j][2]);
        dp[i][j][1] = min(MOD,dp[i-1][j][0]+to(a[i],a[i-1]-1));
        if (j) {
            dp[i][j][0] = min(MOD,dp[i-1][j-1][2]+to(a[i-1],a[i]-1));
            if (i > 1) {
                dp[i][j][0] = min(dp[i][j][0],dp[i-1][j-1][1]+to(min(a[i-1],a[i-2]-1),a[i]-1));
            }
        }
    }
    // cout << dp[1][1][0] << " " << dp[2][1][1] << " " << dp[3][2][0] << " " << dp[4][2][1] << " " << dp[5][3][0] << "\n";
    FOR(j,1,(n+1)/2+1) {
        int t = MOD; F0R(k,3) t = min(t,dp[n][j][k]);
        cout << t << " ";
    }
}

/* Look for:
* the exact constraints (multiple sets are too slow for n=10^6 :( ) 
* special cases (n=1?)
* overflow (ll vs int?)
* array bounds
*/