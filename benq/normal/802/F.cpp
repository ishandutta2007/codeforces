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
const int MX = 3005;

int V;
ld prob0[1001][MX], prob1[1001][MX];

void gen(int mean) {
    ld a = 1;
    int divi = mean;
    F0R(i,MX) {
        prob0[mean][i] = a*exp(-divi);
        a *= mean; a /= i+1;
        while (divi && a/exp(1) >= 1) divi --, a /= exp(1);
    }
    F0R(i,MX) {
        if (prob0[mean][i] == 0) prob0[mean][i] = -INF;
        else prob0[mean][i] = log(prob0[mean][i]);
    }
    F0R(i,MX) prob1[mean][i] = -INF;
    F0R(i,2*mean+1) prob1[mean][i] = log((ld)1/(2*mean+1));
}

vi v;
ld a,b;

void test(int mean) {
    ld A = 0, B = 0;
    for (int i: v) {
        if (i+mean < 0) A = B = -INF;
        else if (i+mean >= MX) continue;
        else {
            A += prob0[mean][mean+i];
            B += prob1[mean][mean+i];
        }
    }
    a = max(a,A), b = max(b,B);
}

void solve() {
    v = {};
    F0R(i,250) { 
        // int x = rand() % 1501-750;
        int x; cin >> x;
        if (x > -MX && x < MX) v.pb(x); 
    }
    a = b = -INF;
    FOR(mean,1,1001) test(mean);
    if (a < b) cout << "uniform";
    else cout << "poisson";
    // cout << a << " " << b << "\n";
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    FOR(i,1,1001) gen(i);
    /*F0R(i,MX) cout << prob0[1000][i] << "\n";
    exit(0);*/
    cin >> V;
    F0R(i,V) solve();
}

/* Look for:
* the exact constraints (multiple sets are too slow for n=10^6 :( ) 
* special cases (n=1?)
* overflow (ll vs int?)
* array bounds
* if you have no idea just guess the appropriate well-known algo instead of doing nothing :/
*/