#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef unsigned int ll;
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
const int MX = 100001;

int n,A,B,C,D;
ll ans;
vi arr[40001];

ll get(int x, int p) {
    if (x == 0) return 0;
    return x/p+get(x/p,p);
}

ll eval(ll x) {
    return ((A*x+B)*x+C)*x+D;
}

bool prime(int x) {
    if (x == 1) return 0;
    for (int i = 2; i*i <= x; ++i) if (x % i == 0) return 0;
    return 1;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> A >> B >> C >> D;
    vi v;
    FOR(i,1,min(n,20000)+1) if (prime(i)) {
        ans += get(n,i)*eval(i);
        v.pb(i);
    }
    for (int i: v) {
        int t = 20001/i;
        if (t*i < 20001) t ++;
        arr[t*i-20001].pb(i);
    }
    
    int st = 0;
    FOR(i,20001,n+1) {
        if (st == 20000) {
            F0R(i,20000) swap(arr[i],arr[i+20000]);
            st = 0;
        }
        if (!sz(arr[st])) {
            ans += get(n,i)*eval(i);
        } else {
            for (int x: arr[st]) arr[st+x].pb(x);
            arr[st].clear();
        }
        st ++;
    }
    
    cout << ans;
}

/* Look for:
* the exact constraints (multiple sets are too slow for n=10^6 :( ) 
* special cases (n=1?)
* overflow (ll vs int?)
* array bounds
*/