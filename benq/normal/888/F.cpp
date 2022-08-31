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

int n,adj[500][500];
ll dp[500][500][2];

void solve(int a, int b, int c) {
    //cout << a << " " << b << " " << c << "\n";
    if (c == 0) { // ends are not connected
        if (a == b) {
            dp[a][b][0] = 1;
            return;
        }
        FOR(i,a+1,b+1) if (adj[a][i]) {
            dp[a][b][0] += dp[a][i][1]*dp[i][b][0];
            dp[a][b][0] %= MOD;
        }
    } else {
        if (a == b) return;
        if (a+1 == b) {
            dp[a][b][1] = 1;
            return;
        }
        FOR(i,a+1,b) if (adj[a][i]) {
            dp[a][b][1] += dp[a][i][1]*dp[i][b][1];
            dp[a][b][1] %= MOD;
        }
        dp[a][b][1] += dp[a+1][b][0];
        dp[a][b][1] %= MOD;
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n;
	F0R(i,n) F0R(j,n) cin >> adj[i][j];
	F0R(len,n) F0R(i,n-len) F0Rd(j,2) {
	    solve(i,i+len,j);
	    //cout << dp[i][i+len][j] << "\n";
	}
	cout << dp[0][n-1][0];
}

// read!
// ll vs. int!