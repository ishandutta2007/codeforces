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

int n,x,k;
vi a;
ll ans = 0;
map<int,int> tmp;

void solve() {
    map<int,int> co;
    F0R(i,n) {
        co[(a[i]-1)/x] ++;
        ans += co[a[i]/x-k];
    }
}

bool ok(int z) {
    if (z % x == 0 && k == 1) return 1;
    if (z % x != 0 && k == 0) return 1;
    return 0;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> x >> k; a.resize(n);
	F0R(i,n) {
	    cin >> a[i];
	    tmp[a[i]] ++;
	}
	sort(a.begin(),a.end());
	for (auto& a: tmp) if (ok(a.f)) {
	    ans += (ll)a.s*(a.s-1)/2;
	}
	solve();
	cout << ans;
}

// read!
// ll vs. int!