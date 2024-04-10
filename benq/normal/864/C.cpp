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

int a,b,f,k,cur,ans;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> a >> b >> f >> k;
	cur = b;
	F0R(i,k) {
	    if (i % 2 == 0) {
	        if (cur < f) {
	            cout << -1;
	            return 0;
	        }
	        cur -= f;
	        int need = 2*(a-f);
	        if (i == k-1) need = a-f;
	        if (cur < need) cur = b, ans ++;
	        if (cur < a-f) {
	            cout << -1;
	            return 0;
	        }
	        cur -= (a-f);
	    } else {
	        if (cur < a-f) {
	            cout << -1;
	            return 0;
	        }
	        cur -= (a-f);
	        int need = 2*f;
	        if (i == k-1) need = f;
	        if (cur < need) cur = b, ans ++;
	        if (cur < f) {
	            cout << -1;
	            return 0;
	        }
	        cur -= f;
	    }
	}
	cout << ans;
}

// read!
// ll vs. int!