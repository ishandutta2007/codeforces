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

int n,k, co[16];

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> k;
	F0R(i,n) {
	    int tmp = 0;
	    F0R(j,k) {
	        int z; cin >> z;
	        if (z) tmp ^= (1<<j);
	    }
	    co[tmp] ++;
	}
	if (co[0]) {
	    cout << "YES";
	    return 0;
	}
	F0R(j,k) {
	    bool bad = 1;
	    F0R(i,1<<k) if (co[i] > 0 && !(i&(1<<j))) bad = 0;
	    if (bad) {
	        cout << "NO";
	        return 0;
	    }
	}
	F0R(i,k) if (co[1<<i]) {
	    cout << "YES";
	    return 0;
	}
	F0R(i,1<<k) if (co[i] && co[(1<<k)-1-i]) {
	    cout << "YES";
	    return 0;
	}
	cout << "NO";
	// all 
}

// read!
// ll vs. int!