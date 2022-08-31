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
const int MX = 200005;

void setIn(string s) { freopen(s.c_str(),"r",stdin); }
void setOut(string s) { freopen(s.c_str(),"w",stdout); }

void io(string s = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (sz(s)) {
    	setIn(s+".in");
    	setOut(s+".out");
    }
}

ll n,t,a[MX],x[MX];

int main() {
    io();
    cin >> n >> t;
    F0R(i,n) cin >> a[i];
    F0R(i,n) {
        cin >> x[i];
        x[i] --;
    }
    if (x[n-1] != n-1) {
        cout << "No";
        exit(0);
    }
    vi bad(n+1);
    F0R(i,n) if (x[i] == i) {
        bad[i+1] = 1;
        for (int j = i-1; j >= 0; --j) {
            if (x[j] == j) break;
            if (x[j] != i) {
                cout << "No";
                exit(0);
            }
        }
    }
    vl b;
    FOR(i,1,n) {
        if (!bad[i]) b.pb(a[i]+t);
        else b.pb(a[i]+t-1);
    }
    b.pb(3e18);
    FOR(i,1,n) if (b[i] == b[i-1]) {
        cout << "No";
        exit(0);
    }
    cout << "Yes\n";
    for (auto z: b) cout << z << " ";
    // if possible: b_1 >= a_2+t
    // if not possible: b_1 < a_2+t 
}

/* 
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/