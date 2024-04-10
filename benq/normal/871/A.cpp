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

int get(int x) {
    if (x % 4 == 0) return x/4;
    if (x % 4 == 1) {
        if (x == 5) return -1;
        return (x-9)/4+1;
    }
    if (x % 4 == 2) {
        if (x == 2) return -1;
        return (x-6)/4+1;
    }
    if (x % 4 == 3) {
        if (x < 15) return -1;
        return (x-15)/4+2;
    }
}
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int q; cin >> q;
	F0R(i,q) {
	    int x; cin >> x;
	    cout << get(x) << "\n";
	}
}

// read!
// ll vs. int!