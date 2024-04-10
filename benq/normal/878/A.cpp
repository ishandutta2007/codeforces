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

int n, t[10];
// 2: original
// 3: not original
// 0: 0 
// 1: 1

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n;
	F0R(i,10) t[i] = 2;
	F0R(i,n) {
	    char c; int x; cin >> c >> x;
	    if (c == '|') {
	        F0R(j,10) if (x&(1<<j)) t[j] = 1;
	    } else if (c == '^') {
	        F0R(j,10) if (x&(1<<j)) {
	            if (t[j] >= 2) t[j] = 5-t[j];
	            else t[j] = 1-t[j];
	        }
	    } else if (c == '&') {
	        F0R(j,10) if (!(x&(1<<j))) t[j] = 0;
	    }
	}
	/*F0R(i,10) cout << t[i] << " ";
	cout << "\n";*/
	
	cout << "3\n";
	// which ones are 3 --> ^
	int i1 = 0;
	F0R(i,10) if (t[i] == 3) i1 ^= (1<<i);
	cout << "^ " << i1 << "\n";
	// which ones are 1 --> |
	i1 = 0;
	F0R(i,10) if (t[i] == 1) i1 ^= (1<<i);
	cout << "| " << i1 << "\n";
	// which ones are 0 --> &
	i1 = 0;
	F0R(i,10) if (t[i] == 0) i1 ^= (1<<i);
	cout << "& " << 1023-i1 << "\n";
}

// read!
// ll vs. int!