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

vi k;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	F0R(i,3) {
	    int x; cin >> x;
	    k.pb(x);
	}
	sort(all(k));
	
	if (k[0] == 1) {
	    cout << "YES";
	    exit(0);
	}
	if (k[0] == 3 && k[1] == 3 && k[2] == 3) { 
	    cout << "YES"; 
	    exit(0); 
	}
	if (k[0] >= 3) { 
	    cout << "NO"; 
	    exit(0); 
	}
	
	if (k[1] == 2) {
	    cout << "YES";
	    exit(0);
	} else if (k[1] == 3) {
	    cout << "NO";
	    exit(0);
	} else if (k[1] == 4) {
	    if (k[2] == 4) {
	        cout << "YES";
	        exit(0);
	    } else {
	        cout << "NO";
	        exit(0);
	    }
	} else {
	    cout << "NO";
	    exit(0);
	}
}

// read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!
// ll vs. int!