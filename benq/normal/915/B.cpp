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

int n,pos,l,r,ans, ANS, POS;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> pos >> l >> r;
	if (pos < l) ans += l-pos, pos = l;
	if (pos > r) ans += pos-r, pos = r;
	if (l == 1) {
	    if (r == n) {
	    } else {
	        while (pos < r) {
	            pos ++; ans ++;
	        }
	            ans ++;
	    }
	} else {
	    if (r == n) {
	        while (pos > l) {
	            pos --; ans ++;
	        }
	        ans ++;
	    } else {
	        POS = pos; ANS = ans;
	        while (pos > l) pos --, ans ++;
	        ans ++;
	        while (pos < r) pos ++, ans ++; 
	        ans ++;
	        
	        while (POS < r) POS ++, ANS ++; 
	        ANS ++;
	        while (POS > l) POS --, ANS ++;
	        ANS ++;
	        cout << min(ans,ANS);
	        return 0;
	    }
	}
	cout << ans;
}

// read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!
// ll vs. int!