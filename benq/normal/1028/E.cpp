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
const int MX = 200001;

int n,numZero;
vl b, des;

void stuff() {
    FOR(i,1,n) if (b[i] != b[0]) return;
    if (b[0] != 0) {
        cout << "NO";
        exit(0);
    }
    cout << "YES\n";
    F0R(i,n) cout << "1 ";
    exit(0);
}

ll need(ll x, ll y) { return (x/y+1)*y; }

void dealWith(int x) {
    while (b[x] == 0 || b[(x+n-1)%n]%b[x] != des[(x+n-1)%n]) {
        // cout << "HI " << x << "\n";
        b[x] += need(b[(x+n-1)%n]-b[x],b[(x+1)%n]);
        x = (x+n-1)%n;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n; des.resize(n), b.resize(n);
    F0R(i,n) {
        cin >> b[i];
        des[i] = b[i];
    }
    stuff();
    F0R(i,n) if (b[i] < b[(i+1)%n]) {
        /*if (i > 0) {
            cout << i;
            exit(0);
        }*/
        dealWith(i);
        // F0R(j,n) cout << b[j] << " ";
    }
    cout << "YES\n";
    F0R(i,n) cout << b[i] << " ";
}

/* Look for:
* the exact constraints (multiple sets are too slow for n=10^6 :( ) 
* special cases (n=1?)
* overflow (ll vs int?)
* array bounds
* if you have no idea just guess the appropriate well-known algo instead of doing nothing :/
*/