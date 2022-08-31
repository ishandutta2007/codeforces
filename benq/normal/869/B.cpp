#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define FOR(i, a, b) for (ll i=a; i<(b); i++)
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

ll a,b, m2 = 1, m5 = 1;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> a >> b;
	// mod 2 
	FOR(i,a+1,b+1) {
	    m2 = (m2*i) % 2;
	    if (m2 == 0) break;
	}
	// mod 5
	FOR(i,a+1,b+1) {
	    m5 = (m5*i) % 5;
	    if (m5 == 0) break;
	}
	int ans = m5;
	if (m2 != (m5%2)) ans += 5;
	cout << ans;
}

// read!
// ll vs. int!