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

map<ll,ll> m;

void process(ll x) {
    if (m.count(x)) return;
    if (x == 1) {
        m[1] = 1;
        return;
    }
    if (x == 0) {
        m[0] = 0;
        return;
    }
    process(x/2);
    m[x] = 2*m[x/2]+1;
}

ll solve(ll n, ll r) {
    if (n == 0) return 0;
    if (r <= m[n/2]) return solve(n/2,r);
    return n/2+(n&1)+solve(n/2,r-m[n/2]-1);
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
    ll n,l,r; cin >> n >> l >> r;
    process(n);
	cout << solve(n,r)-solve(n,l-1);
}

// read!
// ll vs. int!