
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

ll n;
array<ll,3> p[2];
ll a = 34130491, b = 13424, num = 0;

/*ll decide(ll x, ll y) {
    num ++;
    vl v;
    if (x < a) v.pb(1);
    if (y < b) v.pb(2);
    if (x > a || y > b) v.pb(3);
    if (sz(v) == 0) return 0;
    random_shuffle(all(v));
    return v[0];
}*/

int query(ll x, ll y) {
    cout << x << " " << y << endl;
    // ll ans = decide(x,y); 
    int ans; cin >> ans;
    if (ans == 0) exit(0); 
    return ans;
}

int main() {
    cin >> n;
    F0R(i,1) {
        p[0] = p[1] = {1,n,n};
        while (p[0][0] < p[0][2] || p[1][0] < p[1][2]) {
            ll m0,m1;
            m0 = (p[0][0]+p[0][1])/2;
            m1 = (p[1][0]+p[1][1])/2;
            if (p[0][1] != p[0][2]) {
                if ((p[0][1] - p[0][0] + 1) * double(p[1][2] - p[1][0] + 1) 
                    > (p[1][1] - p[1][0] + 1) * double(p[0][2] - p[0][0] + 1)) {
                    m1 = p[1][1];
                } else {
                    m0 = p[0][1];
                }
            }
            int x = query(m0,m1);
            if (x == 1) {
                p[0][0] = m0+1;
            } else if (x == 2) {
                p[1][0] = m1+1;
            } else if (x == 3) {
                p[0][1] = m0-1;
                p[1][1] = m1-1;
            }
            if (p[0][1] < p[0][0]) {
                p[0][1] = p[0][2];
                p[1][2] = p[1][1];
            } else if (p[1][1] < p[1][0]) {
                p[1][1] = p[1][2];
                p[0][2] = p[0][1];
            }
        }
        query(p[0][0],p[1][0]);
    }
}

/* Look for:
* the exact constraints (multiple sets are too slow for n=10^6 :( ) 
* special cases (n=1?)
* overflow (ll vs int?)
* array bounds
*/