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
#define all(x) x.begin(), x.end()

const int MOD = 1000000007;

string n;
int k, need[1001];
ll dp[2][1001][1001];

void gen() {
    FOR(i,2,1001) need[i] = need[__builtin_popcount(i)]+1;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	gen();
	cin >> n >> k;
	if (k == 0) {
	    cout << 1;
	    return 0;
	}
	string t = ""; F0R(i,1000-sz(n)) t += '0';
	n = t+n;
	dp[1][0][0] = 1;
	F0R(i,1000) F0R(j,i+1) F0R(k,2) {
	    dp[k][i][j] %= MOD;
	    if (k == 0) {
	        dp[k][i+1][j+1] += dp[k][i][j];
	        dp[k][i+1][j] += dp[k][i][j];
	    } else {
	        if (n[i] == '0') {
	            dp[k][i+1][j] += dp[k][i][j];
	        } else {
	            dp[0][i+1][j] += dp[k][i][j];
	            dp[k][i+1][j+1] += dp[k][i][j];
	        }
	    }
	}
	F0R(i,1001) dp[0][1000][i] = (dp[0][1000][i]+dp[1][1000][i]) % MOD;
	dp[0][1000][1] += MOD-1;
	dp[0][1000][1] %= MOD;
	
	ll ans = 0;
	FOR(i,1,1001) if (need[i] == k-1) ans = (ans+dp[0][1000][i]) % MOD;
	cout << ans;
}

// read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!
// ll vs. int!