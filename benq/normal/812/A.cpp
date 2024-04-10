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

int bad[4], P[4];

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	F0R(i,4) {
	    int l,s,r,p; cin >> l >> s >> r >> p;
	    if (l) bad[i] = bad[(i+3)%4] = 1;
	    if (s) bad[i] = bad[(i+2)%4] = 1;
	    if (r) bad[i] = bad[(i+1)%4] = 1;
	    if (p) P[i] = 1;
	}
	F0R(i,4) if (bad[i]&P[i]) {
	    cout << "YES";
	    return 0;
	}
	cout << "NO";
}

// read!
// ll vs. int!