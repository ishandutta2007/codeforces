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

int n,m,q;
ll a[100001], b[100001], sum = 0, cum[100001];
set<ll> posi;

void gen() {
	FOR(i,1,n+1) {
		if (i % 2 == 0) a[i] *= -1;
		sum += a[i];
	}
	FOR(i,1,m+1) {
		if (i % 2 == 0) b[i] *= -1;
		cum[i] = cum[i-1]+b[i];
	}
	F0R(i,m-n+1) {
		if (i % 2 == 0) posi.insert(cum[i+n]-cum[i]);
		else posi.insert(cum[i]-cum[i+n]);
	}
}

ll query(ll su) {
	auto it = posi.lb(su);
	ll ans = 1e18;
	if (it != posi.end()) ans = min(ans,*it-su);
	if (it != posi.begin()) ans = min(ans,su-*prev(it));
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> m >> q;
	FOR(i,1,n+1) cin >> a[i];
	FOR(i,1,m+1) cin >> b[i];
	gen();
	
	cout << query(sum) << "\n";
 	F0R(i,q) {
		int l,r,x; cin >> l >> r >> x;
		if ((l&1) == (r&1)) {
			if (l&1) sum += x;
			else sum -= x;
		}
		cout << query(sum) << "\n";
	}
}

// read!
// ll vs. int!