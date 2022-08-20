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

int n,q, A[100000], mult = 1;
vpi Q[100000];
ll ans[100000];
set<int> cur;

int query(int x) {
    for (auto it = cur.rbegin(); it != cur.rend(); it ++) if ((x^(*it)) < x) x ^= (*it);
    if (x == 0) return mult;
    return 0;
}

void ad(int x) {
    for (auto it = cur.rbegin(); it != cur.rend(); it ++) if ((x^(*it)) < x) x ^= (*it);
    if (x == 0) mult = 2*mult % MOD;
    else cur.insert(x);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> q;
    F0R(i,n) cin >> A[i];
    F0R(i,q) {
        int a,b; cin >> a >> b;
        Q[a-1].pb({b,i});
    }
    F0R(i,n) {
        ad(A[i]);
        for (auto x: Q[i]) ans[x.s] = query(x.f);
    }
    F0R(i,q) cout << ans[i] << "\n";
}

// read the question correctly (is y a vowel?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?)