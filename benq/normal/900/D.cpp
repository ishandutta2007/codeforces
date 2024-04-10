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

int x,y;
vi pri;
ll ans = 0;

ll po (ll b, ll p) {
    return !p?1:po(b*b%MOD,p/2)*(p&1?b:1)%MOD;
}
    
ll get(int x) {
    return po(2,x-1);
}

void solve() {
    int Y = y;
    for (int i = 2; i*i <= Y; ++i) {
        bool f = 0;
        while (Y % i == 0) Y /= i, f = 1;
        if (f) pri.pb(i);
    }
    if (Y > 1) pri.pb(Y);
    F0R(i,1<<sz(pri)) {
        int co = 0, prod = 1;
        F0R(j,sz(pri)) if (i&(1<<j)) prod *= pri[j], co++;
        if (co&1) ans -= get(y/prod);
        else ans += get(y/prod);
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> x >> y;
	if (y % x != 0) {
	    cout << 0;
	    return 0;
	}
	y /= x;
	solve();
	ans = (ans%MOD+MOD)%MOD;
	cout << ans;
}

// read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!
// ll vs. int!