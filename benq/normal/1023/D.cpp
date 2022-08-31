#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

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
const int MX = 200001;

/* template<class T, int SZ> struct BIT {
    T bit[SZ+1];
    
    BIT() { memset(bit,0,sizeof bit); }
    
    void upd(int k, T val) { // add val to index k
        for( ;k <= SZ; k += (k&-k)) bit[k] += val;
    }
    
    T query(int k) {
        T temp = 0;
        for (;k > 0;k -= (k&-k)) temp += bit[k];
        return temp;
    }
    T query(int l, int r) { return query(r)-query(l-1); } // range query [l,r]
};
*/

set<int> bad, zero;
int n,q,a[MX];
vi pos[MX];

void setRange(int x, int L, int R) {
    auto it = bad.lb(L);
    if (it != bad.end() && (*it) <= R) {
        cout << "NO";
        exit(0);
    }
    it = zero.lb(L);
    while (it != zero.end() && (*it) <= R) {
        a[*it] = x;
        it = next(it);
        zero.erase(prev(it));
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> q;
    FOR(i,1,n+1) {
        cin >> a[i];
        if (a[i]) {
            bad.insert(i);
            pos[a[i]].pb(i);
        } else zero.insert(i);
    }
    FORd(i,1,q+1) {
        sort(all(pos[i]));
        for (int x: pos[i]) bad.erase(x);
        if (i == 1) {
            setRange(i,1,n);
        } else if (sz(pos[i])) {
            setRange(i,pos[i][0],pos[i][sz(pos[i])-1]);
        } else if (i == q) {
            bool ok = 0;
            FOR(j,1,n+1) if (a[j] == 0) {
                setRange(i,j,j);
                ok = 1;
                break;
            }
            if (!ok) {
                cout << "NO";
                exit(0);
            }
        }
    }
    cout << "YES\n";
    FOR(i,1,n+1) cout << a[i] << " ";
}

/* Look for:
* the exact constraints (multiple sets are too slow for n=10^6 :( ) 
* special cases (n=1?)
* overflow (ll vs int?)
* array bounds
* if you have no idea just guess the appropriate well-known algo instead of doing nothing :/
*/