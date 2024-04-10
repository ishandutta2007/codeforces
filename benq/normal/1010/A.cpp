
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;

typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;

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
const ll INF = 1e18;
const int MX = 100001;

int n,m;
vi a,b;

bool posi(ld mid) {
    ld res = m+mid;
    F0R(i,n) {
        res -= res/a[i];
        if (res < m) return 0;
        res -= res/b[i];
        if (res < m) return 0;
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m; a.resize(n), b.resize(n);
    F0R(i,n) cin >> a[i];
    F0R(i,n) cin >> b[i];
    ld lo = 0, hi = 2e9;
    F0R(i,100) {
        ld mid = (lo+hi)/2;
        if (posi(mid)) hi = mid;
        else lo = mid;
    }
    if (lo > 1.5e9) {
        cout << -1;
        exit(0);
    }
    cout << fixed << setprecision(9) << (lo+hi)/2;
}

/* Look for:
* the exact constraints (multiple sets are too slow for n=10^6 :( ) 
* special cases (n=1?)
* overflow (ll vs int?)
* array bounds
*/