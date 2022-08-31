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

vi sub[100001];
int prep[100001], temp[100001],n,m;

bool posi(int x) {
	memset(temp, 0, sizeof temp);
	vector<pii> todo;
	F0R(i,m) {
		auto k = ub(sub[i].begin(),sub[i].end(),x);
		if (k == sub[i].begin()) return 0;
		int z = *prev(k);
		temp[z] = 1;
		todo.pb(mp(z,prep[i]));
	}
	sort(todo.begin(),todo.end());
	int c1 = 0, c2 = 0;
	FOR(i,1,x+1) {
		if (temp[i]) {
			c2++;
			if (c2>c1) return 0;
		} else if (todo[c1].s>0) {
			todo[c1].s--;
			if (todo[c1].s == 0) c1++;
		}
		if (c1 == m) break;
	}
	return 1;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> m;
	int low = m, up = n;
	FOR(i,1,n+1) {
		int x; cin >> x;
		if (x != 0) sub[x-1].pb(i);
	}
	F0R(i,m) {
		if (sub[i].size() == 0) {
			cout << -1;
			return 0;
		}
		low = max(low,sub[i][0]);
	}
	F0R(i,m) cin >> prep[i];
	if (!posi(n)) {
		cout << -1;
		return 0;
	}
	while (low<up) {
		int mid = (low+up)/2;
		if (posi(mid)) up = mid;
		else low = mid+1;
	}
	cout << low;
}

// read!
// ll vs. int!