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

int n,m;
vi ans, res;

void gen() {
    for (int i = 100000; i > 0; i -= 2) ans.pb(i);
    ans.pb(1);
    for (int i = 2; i <= 100000; i += 2) {
        ans.pb(i+1);
        ans.pb(i);
    }
}

int main() {
    gen();
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n;
	F0R(i,ans.size()) if (ans[i] <= n) res.pb(ans[i]);
	cout << res.size() << "\n";
	for (int i: res) cout << i << " ";
}

// read!
// ll vs. int!