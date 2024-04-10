#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<ll, ll> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;

typedef vector<ll> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define FOR(i, a, b) for (ll i=a; i<(b); i++)
#define F0R(i, a) for (ll i=0; i<(a); i++)
#define FORd(i,a,b) for (ll i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (ll i = (a)-1; i >= 0; i--)

#define sz(x) (ll)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()

const ll MOD = 1000000007;
const ll INF = 1e18;
const ll MX = 100001;

int n;
vi a;
set<int> z;
ll ans = 0;
map<int,int> fst;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n; a.resize(n);
    F0R(i,n) cin >> a[i];
    F0Rd(i,n) fst[a[i]] = i;
    F0Rd(i,n) {
        if (fst[a[i]] == i) ans += sz(z);
        z.insert(a[i]);
    }
    cout << ans;
}

// read the question correctly (is y a vowel? what are the exact constralls?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs ll?) ARRAY OUT OF BOUNDSS