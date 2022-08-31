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

ll x,k;

ll sub(ll a, ll b) {
    a %= MOD, b %= MOD;
    return (a-b+MOD)%MOD;
}

ll mul(ll a, ll b) {
    a %= MOD, b %= MOD;
    return a*b%MOD;
}

ll po (ll a, ll b) {
    if (b == 0) return 1; 
    return mul(po(a*a%MOD,b/2),b&1?a:1);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> x >> k; 
    if (x == 0) {
        cout << 0;
        exit(0);
    }
    cout << sub(mul(po(2,k+1),x),sub(po(2,k),1));
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS