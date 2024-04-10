#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/rope>

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
 
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

const ld PI = 4*atan((ld)1);
int n;
ll ans = 0;
vcd p;

ll tri(ll x) {
    ll y = n-2-x;
    // cout << "AH " << x << " " << y << "\n";
    return x*(x-1)/2*y*(y-1)/2; 
}

void test(int x) {
    vector<ld> v;
    F0R(i,sz(p)) if (i != x) v.pb(arg(p[i]-p[x]));
    sort(all(v));
    F0R(i,n-1) v.pb(v[i]+2*PI);
    
    int ind = 0;
    F0R(i,n-1) {
        while (ind < sz(v) && v[ind]-v[i] < PI) ind ++;
        ans += tri(ind-i-1);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    F0R(i,n) {
        int x,y; cin >> x >> y;
        p.pb(cd(x,y));
    }
    // cout << fixed << setprecision(15) << PI << "\n";
    // cout << fixed << setprecision(15) << atan2(2*MOD,2*MOD-1)-atan2(2*MOD-1,2*MOD) << "\n";
    F0R(i,n) test(i);
    cout << ans/2;
}

/* Look for:
* the exact constraints (multiple sets are too slow for n=10^6 :( ) 
* special cases (n=1?)
* overflow (ll vs int?)
* array bounds
* if you have no idea just guess the appropriate well-known algo instead of doing nothing :/
*/