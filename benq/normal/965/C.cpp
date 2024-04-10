
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

// x*ceil(floor(n/x)/k)
ll n,k,M,D,ans;

ll get(ll ti) {
    // receives candy exactly ti times
    // (ti+1)*x+ti*(k-1)*x > n;
    if (ti > INF/(k-1)) return 0;
    ll lo = n/(ti+1+ti*k)+1;
    ll hi = min(M,n/(ti+(ti-1)*(k-1)));
    // cout << ti << " " << lo << " " << hi << "\n";
    if (lo <= hi) return hi*ti;
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k >> M >> D;
    FOR(i,1,D+1) ans = max(ans,get(i));
    cout << ans;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?)