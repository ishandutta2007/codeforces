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

int n;
set<int> cur;
ll cans = 1;
pi bound = {-MOD,MOD};
vi tmp;

void finish() {
    int t = 1;
    for (int i: tmp) if (i > bound.f && i < bound.s) t ++;
    cans = cans*t%MOD;
}

bool okBuy(int p) {
    pi BOUND = bound;
    for (int i: tmp) {
        if (i > p) {
            BOUND.s = min(BOUND.s,i);
        } else {
            BOUND.f = max(BOUND.f,i);
        }
        if (BOUND.f > BOUND.s) return 0;
    }
    return p == BOUND.f;
}

bool okSell(int p) {
    pi BOUND = bound;
    for (int i: tmp) {
        if (i >= p) {
            BOUND.s = min(BOUND.s,i);
        } else {
            BOUND.f = max(BOUND.f,i);
        }
        if (BOUND.f > BOUND.s) return 0;
    }
    return p == BOUND.s;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n; cur.insert(-MOD), cur.insert(MOD);
    
    F0R(i,n) {
        string s; int p; cin >> s >> p;
        if (s == "ADD") tmp.pb(p);
        else {
            int t = 0;
            if (okBuy(p)) t ++;
            if (okSell(p)) t ++;
            
            // cout << "HI " << okBuy(p) << " " << okSell(p) << "\n";
            if (t == 0) {
                cout << 0;
                exit(0);
            }
            
            cans = cans*t%MOD;
            for (int i: tmp) cur.insert(i);
            auto it = cur.find(p); 
            bound = {*prev(it),*next(it)};
            cur.erase(it);
            tmp.clear();
        }
    }
    finish();
    
    cout << cans;
}

/* Look for:
* the exact constraints (multiple sets are too slow for n=10^6 :( ) 
* special cases (n=1?)
* overflow (ll vs int?)
* array bounds
* if you have no idea just guess the appropriate well-known algo instead of doing nothing :/
*/