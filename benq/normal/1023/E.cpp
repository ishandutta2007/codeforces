#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

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

int n;

bool valid(pi x) {
    return 1 <= x.f && x.f <= n && 1 <= x.s && x.s <= n;
}

bool ok(pi a, pi b) {
    if (!valid(a) || !valid(b)) return 0;
    cout << "? " << a.f << " " << a.s << " " << b.f << " " << b.s << endl;
    string x; cin >> x;
    return x == "YES";
}

int main() {
    cin >> n;
    pi cur = {1,1};
    string a,b;
    
    while (cur.f+cur.s < n+1) {
        if (ok({cur.f,cur.s+1},{n,n})) {
            cur.s ++;
            a += 'R';
        } else {
            cur.f ++;
            a += 'D';
        }
    }
    
    pi CUR = {n,n};
    while (CUR.f+CUR.s > n+1) {
        if (ok({1,1},{CUR.f-1,CUR.s})) {
            CUR.f --;
            b += 'D';
        } else {
            CUR.s --;
            b += 'R';
        }
    }
    reverse(all(b));
    cout << "! " << a+b << endl;
}

/* Look for:
* the exact constraints (multiple sets are too slow for n=10^6 :( ) 
* special cases (n=1?)
* overflow (ll vs int?)
* array bounds
* if you have no idea just guess the appropriate well-known algo instead of doing nothing :/
*/