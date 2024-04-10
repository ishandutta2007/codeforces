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

int n,T;
pii dat[200001];
vi ans;

bool test (int mid) {
    vector<pii> cur;
    FOR(i,1,n+1) if (mid <= dat[i].f) cur.pb({dat[i].s,i});
    sort(all(cur));
    if (sz(cur) < mid) return 0;
    ans.clear();
    int sum = 0;
    F0R(i,mid) {
        sum += cur[i].f;
        ans.pb(cur[i].s);
    }
    return sum <= T;
}
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> T;
	FOR(i,1,n+1) cin >> dat[i].f >> dat[i].s;
	int lo = 0, hi = n;
	while (lo < hi) {
	    int mid = (lo+hi+1)/2;
	    if (test(mid)) lo = mid;
	    else hi = mid-1;
	}
	test(lo);
	cout << sz(ans) << "\n" << sz(ans) << "\n";
	for (int i: ans) cout << i << " ";
}

// read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!
// ll vs. int!