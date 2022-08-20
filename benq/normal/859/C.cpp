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

int N, pie[50];
pii dp[51][2]; // Alice has on current step, Bob has on current step

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> N;
	F0R(i,N) cin >> pie[i];
	F0Rd(i,N) {
	    dp[i][0] = max(mp(dp[i+1][1].f+pie[i],dp[i+1][1].s),mp(dp[i+1][0].f,dp[i+1][0].s+pie[i]));
	    dp[i][1] = min(mp(dp[i+1][0].f,dp[i+1][0].s+pie[i]),mp(dp[i+1][1].f+pie[i],dp[i+1][1].s));
	}
	cout << dp[0][1].f << " " << dp[0][1].s;
}

// read!
// ll vs. int!