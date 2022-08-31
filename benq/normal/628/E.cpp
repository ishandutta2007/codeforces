#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/rope>

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
 
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
const int MX = 3001;

int n,m, lef[MX][MX], ri[MX][MX];
char s[MX][MX];
ll ans = 0;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    F0Rd(j,n) F0R(i,m) cin >> s[i][j];
    F0Rd(j,n) {
        F0R(i,m) if (s[i][j] == 'z') {
            if (i && s[i-1][j] == 'z') lef[i][j] = lef[i-1][j];
            else lef[i][j] = i;
        }
        F0Rd(i,m) if (s[i][j] == 'z') {
            if (i < m-1 && s[i+1][j] == 'z') ri[i][j] = ri[i+1][j];
            else ri[i][j] = i;
        }
    }
    for (int dif = n-1; dif >= -(m-1); dif --) {
        // 0 <= i < m 
        // 0 <= i+dif < n 
        int l = max(0,-dif), r = min(m,n-dif)-1;
        Tree<int> T; priority_queue<pi> t;
        for (int i = r; i >= l; --i) {
            if (s[i][i+dif] == 'z') {
                T.insert(i);
                t.push({lef[i][i+dif],i});
                ans += T.order_of_key(ri[i][i+dif]+1);
            } else {
                T.clear();
                while (sz(t)) t.pop();
            }
            while (sz(t) && t.top().f == i) {
                T.erase(t.top().s);
                t.pop();
            }
        }
    }
    cout << ans;
}

/* Look for:
* the exact constraints (multiple sets are too slow for n=10^6 :( ) 
* special cases (n=1?)
* overflow (ll vs int?)
* array bounds
* if you have no idea just guess the appropriate well-known algo instead of doing nothing :/
*/