#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<ll,ll> pi;
typedef pair<ll,ll> pl;
typedef pair<double,double> pd;

typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vpi;

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
const double PI = 4*atan(1);
const ll INF = 1e18;
const int MX = 100001;

int n;
vpi p;

ll cross(pi a, pi b, pi c) {
    b.f -= a.f, b.s -= a.s;
    c.f -= a.f, c.s -= a.s;
    return b.f*c.s-b.s*c.f;
}

void tri(pi a, pi b) {
    vpi z;
    for (auto x: p) if (cross(a,b,x) != 0) z.pb(x);
    FOR(i,2,sz(z)) if (cross(z[0],z[1],z[i]) != 0) return;
    cout << "YES";
    exit(0);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n; p.resize(n);
    F0R(i,n) cin >> p[i].f >> p[i].s;
    if (n < 3) {
        cout << "YES";
        return 0;
    }
    tri(p[0],p[1]);
    tri(p[0],p[2]);
    tri(p[1],p[2]);
    cout << "NO";
}

// read the question correctly (is y a vowel?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?)