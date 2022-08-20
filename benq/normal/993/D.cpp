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
vi a;
map<int,vi> m;
vector<pair<int,vi>> todo;
ld dp[51][51];

bool ok(ld mid) {
    F0R(i,sz(todo)+1) F0R(j,n+1) dp[i][j] = -INF;
    dp[0][0] = 0;
    F0R(i,sz(todo)) F0R(j,n+1) if (dp[i][j] != -INF) {
        ld cost = 0;
        F0Rd(k,sz(todo[i].s)+1) {
            if (k <= j) dp[i+1][j-k+sz(todo[i].s)-k] = max(dp[i+1][j-k+sz(todo[i].s)-k],dp[i][j]+cost);
            if (k > 0) cost += mid*todo[i].s[k-1]-todo[i].f;
        }
    }
    ld mx = -INF;
    F0R(j,n+1) mx = max(mx,dp[sz(todo)][j]);
    return mx >= 0;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n; a.resize(n);
    
    F0R(i,n) cin >> a[i];
    F0R(i,n) {
        int t; cin >> t;
        m[a[i]].pb(t);
    }
    for (auto z: m) todo.pb(z);
    sort(todo.rbegin(),todo.rend());
    for (auto& z: todo) sort(z.s.begin(),z.s.end());
    
    ld lo = 0, hi = 1e9;
    F0R(i,60) {
        ld mid = (lo+hi)/2;
        if (ok(mid)) hi = mid;
        else lo = mid;
    }
    
    cout << (ll)ceil(1000*lo);
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS