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

int m,n, visit[1000];
ll dp[1001][1001], tmp[1001];
ll ans = 1;
string t[1000];

bool equiv (int a, int b) {
    F0R(i,n) if (t[i][a] != t[i][b]) return 0;
    return 1;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	dp[1][1] = 1;
	FOR(i,1,1000) FOR(j,1,1000) {
	    dp[i+1][j] += j*dp[i][j];
	    dp[i+1][j] %= MOD;
	    dp[i+1][j+1] += dp[i][j];
	}
	FOR(i,1,1001) FOR(j,1,1001) tmp[i] = (tmp[i]+dp[i][j])%MOD;
	
	cin >> m >> n;
	F0R(i,n) cin >> t[i];
	F0R(i,m) if (!visit[i]) {
	    int t = 1;
	    FOR(j,i+1,m) if (equiv(i,j)) {
	        visit[j] = 1;
	        t ++;
	    }
	    ans = ans*tmp[t]%MOD;
	}
	cout << ans;
}

// read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!
// ll vs. int!