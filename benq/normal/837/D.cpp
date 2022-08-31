#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
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

const int MOD = 1000000007;

int N, K, dp[201][6000];
pii fac[201];

pii get(ll x) {
    int a=0,b=0;
    while(x%2 == 0) x /= 2, a++;
    while (x%5 == 0) x /= 5, b++;
    return {b,a};
}

void solve() {
	F0R(i,201) F0R(j,6000) dp[i][j] = -MOD;
    dp[0][0] = 0;
    F0R(i,N) 
    	F0Rd(j,i+1) F0Rd(k,30*i+1) if (dp[j][k] > -MOD) 
    		dp[j+1][k+fac[i].f] = max(dp[j+1][k+fac[i].f],dp[j][k]+fac[i].s);
	int ans = 0;
	F0R(i,6000) ans = max(ans,min(i,dp[K][i]));
	cout << ans;
}

int main() {
    cin >> N >> K;
    F0R(i,N) {
        ll x; cin >> x;
        fac[i] = get(x);
    }
    solve();
}

// read!
// ll vs int!