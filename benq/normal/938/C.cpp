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

int t;

void solve(int x) {
    if (x == 0) {
        cout << "1 1\n";
        return;
    }
    
    int t = sqrt(x);
    FOR(i,t,100000) {
        ll a = (ll)i*i-x;
        if (a <= 0) continue;
        ll b = sqrt(a);
        if (b*b == a) {
            ll m = i/b;
            if (i/m == b) {
                cout << i << " " << m << "\n";
                return;
            }
        }
    }
    cout << "-1\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> t;
	F0R(i,t) {
	    int x; cin >> x;
	    solve(x);
	}
}

// read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!
// ll vs. int!