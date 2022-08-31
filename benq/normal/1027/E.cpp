#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

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

const int MOD = 998244353;
const ll INF = 1e18;
const int MX = 100001;

array<array<int,501>,501> dp, DP;
int n,k;

void plu(int& a, int b) { a = (a+b)%MOD; }

void clr(array<array<int,501>,501>& a) {
    F0R(i,501) a[i].fill(0);
}

void ad() {
    clr(DP);
    F0R(i,501) FOR(j,i,501) if (dp[i][j]) {
        plu(DP[i+1][max(i+1,j)],dp[i][j]);
        plu(DP[1][max(1,j)],dp[i][j]);
    }
    swap(dp,DP);
}
    
array<int,501> tmp;

void AD() {
    clr(DP);
    F0R(i,501) F0R(j,501) if (dp[i][j]) {
        if ((i+1)*j < k) plu(DP[i+1][j],dp[i][j]);
        plu(DP[1][j],dp[i][j]);
    }
    swap(dp,DP);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    dp[0][0] = 1;
    F0R(i,n) ad();
    F0R(i,501) F0R(j,501) plu(tmp[j],dp[i][j]);
    
    clr(dp);
    FOR(i,1,n+1) if (i < k) dp[1][i] = tmp[i];
    F0R(i,n-1) AD();
    
    int ans = 0;
    F0R(i,501) F0R(j,501) plu(ans,dp[i][j]);
    cout << ans;
}

/* Look for:
* the exact constraints (multiple sets are too slow for n=10^6 :( ) 
* special cases (n=1?)
* overflow (ll vs int?)
* array bounds
* if you have no idea just guess the appropriate well-known algo instead of doing nothing :/
*/