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

int n,m,c;
vi beg, en;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> m >> c;
	F0R(i,MOD) {
	    int p; cin >> p;
	    if (p >= c/2+1) { 
	        if (en.size() == 0 || p <= en.back()) {
	            cout << n-en.size() << endl;
	            en.pb(p);
	        } else if (p > en.back()) {
	            // modify last one which is < than it
	            bool f = 0;
	            F0Rd(j,en.size()) {
	                if (en[j] >= p) {
	                    en[j+1] = p;
	                    cout << n-j-1 << endl;
	                    f = 1;
	                    break;
	                } 
	            }
	            if (!f) {
	                en[0] = p;
	                cout << n << endl;
	            }
	        }
	    } else {
	        if (beg.size() == 0 || p >= beg.back()) {
	            beg.pb(p);
	            cout << beg.size() << endl;
	        } else if (p < beg.back()) {
	            bool f = 0;
	            F0Rd(j,beg.size()) {
	                if (beg[j] <= p) {
	                    beg[j+1] = p;
	                    cout << j+2 << endl;
	                    f = 1;
	                    break;
	                } 
	            }
	            if (!f) {
	                beg[0] = p;
	                cout << 1 << endl;
	            }
	        }
	    }
	    if (en.size()+beg.size() == n) return 0;
	}
}

// read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!
// ll vs. int!