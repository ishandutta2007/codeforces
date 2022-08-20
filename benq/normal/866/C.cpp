#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef double ld;
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

int N, R, F[51], S[51], P[51];
ld dp[51][5101];

bool test(ld mid) {
	dp[0][0] = mid;
    F0Rd(i,N) F0R(j,R) {
    	ld prob = P[i]*min(dp[i+1][j+F[i]],dp[0][0]+j+F[i]);
    	prob += (100-P[i])*min(dp[i+1][j+S[i]],dp[0][0]+j+S[i]);
    	
    	if (i == 0 && j == 0) return min(dp[0][0]+j,prob/100) >= dp[0][0];
        dp[i][j] = min(dp[0][0]+j,prob/100);
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> N >> R;
	F0R(i,N+1) F0R(j,5101) dp[i][j] = 1e19;
	F0R(j,R+1)  dp[N][j] = j;
	ld lo = 0, hi = 1e18;
	F0R(i,N) {
		cin >> F[i] >> S[i] >> P[i];
		lo += F[i];
	}
	
	F0R(i,110) {
		ld mid = (lo+hi)/2;
		if (test(mid)) lo = mid;
		else hi = mid;
	}
	cout << fixed << setprecision(15) << lo;
}

// read!
// ll vs. int!