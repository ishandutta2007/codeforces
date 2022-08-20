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
vpi x, y;
map<pi,vpi> X, Y;
set<int> al;
bool ok = 1;

int com(pi a, pi b) {
    if (a == b) return -MOD;
    if (mp(a.s,a.f) == b) return -MOD;
    if (a.f == b.f || a.f == b.s) return a.f;
    if (a.s == b.f || a.s == b.s) return a.s;
    return -MOD;
}

void test(pi a, pi b) {
    int t = com(a,b); al.insert(t);
    set<int> tmp;
    for (auto z : X[a]) tmp.insert(com(a,z));
    if (sz(tmp) > 1) ok = 0;
    tmp.clear();
    for (auto z : Y[b]) tmp.insert(com(b,z));
    if (sz(tmp) > 1) ok = 0;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    F0R(i,n) {
        int a,b; cin >> a >> b;
        x.pb({a,b});
    }
    F0R(i,m) {
        int a,b; cin >> a >> b;
        y.pb({a,b});
    }
    for (auto a: x) for (auto b: y) if (com(a,b) > 0) {
        // cout << a.f << " " << a.s << " " << b.f << " " << b.s << "\n";
        X[a].pb(b);
        Y[b].pb(a);
    }
    for (auto a: x) for (auto b: X[a]) test(a,b);
    
    if (sz(al) == 1) cout << *al.begin();
    else if (ok) cout << 0;
    else cout << -1;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS