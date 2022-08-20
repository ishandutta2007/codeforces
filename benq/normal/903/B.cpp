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

int h1,a1,c1,h2,a2,co;
vector<string> v;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> h1 >> a1 >> c1 >> h2 >> a2;
	while (1) {
	    co ++;
	    if (h2 <= a1) {
	        v.pb("STRIKE\n");
	        break;
	    }
	    if (a2 >= h1) {
	        h1 += c1-a2;
	        v.pb("HEAL\n");
	    } else {
	        v.pb("STRIKE\n");
	        h1 -= a2;
	        h2 -= a1;
	    }
	}
	cout << co << "\n";
	for (auto a: v) cout << a;
}

// read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!
// ll vs. int!