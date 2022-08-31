#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<ll, ll> pll;
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

ll n,k;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> k;
	if ((n-1)*n/2 < k) {
	    cout << "Impossible";
	    return 0;
	} else if ((n-1)*n/2 == k) {
	    F0R(i,n) cout << '(';
	    F0R(i,n) cout << ')';
	    return 0;
	}
	ll cur;
	for (ll i = 1; i <= n; ++i) if (i*(i-1)/2 <= k) cur = i;
	F0R(i,n-1-cur) cout << "()";
	ll tmp = k-cur*(cur-1)/2;
	F0R(i,cur) {
	    if (i == tmp) cout << "()";
	    cout << "(";
	}
	F0R(i,cur) cout << ")";
}

// read!
// ll vs. int!