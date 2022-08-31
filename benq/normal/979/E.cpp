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
const int MX = 100001;

int n,p, tmp[2][2][2], dp[2][2][2]; // odd black, odd white

int i2 = (MOD+1)/2;

int mul(int a, int b) { return (ll)a*b%MOD; }
int ad(int a, int b) { return (a+b)%MOD; }

int ans = 0;

void solve(int a, int b) {
    F0R(i,2) F0R(j,2) F0R(k,2) {
        tmp[i][j][k] = dp[i][j][k];
        dp[i][j][k] = 0;
    }
    ll al = 1; F0R(i,a) al = al*2 % MOD;
    
    F0R(i,2) F0R(j,2) F0R(k,2) {
        if (b != 1) { // black
            if (j) {
                dp[i][j][k] = ad(dp[i][j][k],mul(mul(al,i2),tmp[i][j][k]));
                dp[i|1][j][k^1] = ad(dp[i|1][j][k^1],mul(mul(al,i2),tmp[i][j][k]));
            } else {
                dp[i|1][j][k^1] = ad(dp[i|1][j][k^1],mul(al,tmp[i][j][k]));
            }
        }
        if (b != 0) { // white
            if (i) {
                dp[i][j][k] = ad(dp[i][j][k],mul(mul(al,i2),tmp[i][j][k]));
                dp[i][j|1][k^1] = ad(dp[i][j|1][k^1],mul(mul(al,i2),tmp[i][j][k]));
            } else {
                dp[i][j|1][k^1] = ad(dp[i][j|1][k^1],mul(al,tmp[i][j][k]));
            }
        }
    }
    
    if (a == n-1) {
        F0R(i,2) F0R(j,2) ans = ad(ans,dp[i][j][p]);
        //F0R(i,2) F0R(j,2) cout << i << " " << j << " : " << dp[i][j][0] << " | " << dp[i][j][1] << "\n";
        cout << ans;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> p;
    dp[0][0][0] = 1;
    F0R(i,n) {
        int c; cin >> c;
        solve(i,c);
    }
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS