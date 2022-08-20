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

bool pri[100002];
int n;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	FOR(i,2,100002) pri[i] = 1;
	FOR(i,2,100002) if (pri[i]) {
	    for (int j = 2*i; j < 100002; j += i) pri[j] = 0;
	}
	cin >> n;
	if (n == 1) {
	    cout << "1\n";
	    cout << 1;
	} else if (n == 2) {
	    cout << "1\n";
	    cout << "1 1";
	} else {
	    cout << "2\n";
	    FOR(i,2,n+2) {
	        if (pri[i]) cout << "1 ";
	        else cout << "2 ";
	    }
	}
}

// read!
// ll vs. int!