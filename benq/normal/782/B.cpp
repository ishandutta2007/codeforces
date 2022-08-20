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

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n; cin >> n;
	vector<pii> p(n);
	F0R(i,n) cin >> p[i].f;
	F0R(i,n) cin >> p[i].s;
	double low = 0, high = 1000000000, ans = 1000000000;
	F0R(i,1000) {
		double mid = (low+high)/2;
		double c1 = 0, c2 = 0;
		F0R(i,n) if (p[i].f > mid) c2 = max(c2,(p[i].f-mid)/p[i].s);
		else c1 = max(c1,(mid-p[i].f)/p[i].s);
		ans = min(ans,max(c1,c2));
		if (c1>c2) high = mid;
		else low = mid;
	}
	cout << fixed << setprecision(9) << ans;
}

// read!
// ll vs. int!