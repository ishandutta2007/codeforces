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

int n;
ll ans = 0;
vector<ll> b, r, g;

void process(bool f = 0) {
    if (f == 0) {
        if (sz(g) == 1) {
            if (sz(r)) ans += g[0]-r[0];
            if (sz(b)) ans += g[0]-b[0];
        } else {
            ll a1 = 2*(g.back()-g[sz(g)-2]);
            ll a2 = g.back()-g[sz(g)-2];
            
            if (sz(r)) {
                ll mx = max(g.back()-r.back(),r.front()-g[sz(g)-2]);
                F0R(i,sz(r)-1) mx = max(mx,r[i+1]-r[i]);
                a2 += g.back()-g[sz(g)-2]-mx;
            }
            if (sz(b)) {
                ll mx = max(g.back()-b.back(),b.front()-g[sz(g)-2]);
                F0R(i,sz(b)-1) mx = max(mx,b[i+1]-b[i]);
                a2 += g.back()-g[sz(g)-2]-mx;
            }
            ans += min(a1,a2);
        }
    } else {
        if (sz(g) == 0) {
            if (sz(r)) ans += r.back()-r.front();
            if (sz(b)) ans += b.back()-b.front();
        } else {
            if (sz(r)) ans += r.back()-g.back();
            if (sz(b)) ans += b.back()-g.back();
        }
    }
    b.clear(), r.clear();
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n;
	F0R(i,n) {
	    int p; char c; cin >> p >> c;
	    if (c == 'P') {
	        g.pb(p);
	        process();
	    } else if (c == 'R') r.pb(p);
	    else b.pb(p);
	}
	process(1);
	cout << ans;
}

// read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!
// ll vs. int!