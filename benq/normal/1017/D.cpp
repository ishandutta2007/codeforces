
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

int n,m,q,w[13], L;
int tmp[1<<6][1<<6][101];

int con(string s) {
    int ret = 0;
    F0R(i,sz(s)) if (s[i] == '1') ret ^= 1<<i;
    return ret;
}

void ad(string s) {
    int x = con(s.substr(0,n/2));
    int y = con(s.substr(n/2,L));
    
    F0R(i,1<<L) {
        int ans = 0;
        F0R(j,L) if ((i&(1<<j)) == (y&(1<<j))) ans += w[n/2+j];
        if (ans <= 100) tmp[x][i][ans] ++;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> q;
    L = n-n/2;
    F0R(i,n) cin >> w[i];
    F0R(i,m) {
        string s; cin >> s;
        ad(s);
    }
    F0R(i,1<<(n/2)) F0R(j,1<<L) FOR(k,1,101) tmp[i][j][k] += tmp[i][j][k-1];
    F0R(i,q) {
        string t; int k; cin >> t >> k;
        int x = con(t.substr(0,n/2));
        int y = con(t.substr(n/2,L));
        // cout << "HA " << x << " " << y << "\n";
        int ret = 0;
        F0R(i,1<<(n/2)) {
            int z = 0;
            F0R(j,n/2) if ((i&(1<<j)) == (x&(1<<j))) z += w[j];
            if (z <= k) ret += tmp[i][y][k-z];
        }
        cout << ret << "\n";
    }
}

/* Look for:
* the exact constraints (multiple sets are too slow for n=10^6 :( ) 
* special cases (n=1?)
* overflow (ll vs int?)
* array bounds
*/