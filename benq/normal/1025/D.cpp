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
const int MX = 100001;

int n,a[700];
bitset<700> posi[700][700], ok[700];
bool done[700][700];
int l[700][700], r[700][700];

int getRight(int a, int b) {
    if (r[a][b] != 0) return (r[a][b]+1)/2;
    if ((ok[b+1]&posi[a][b]).count()) r[a][b] = 1;
    else r[a][b] = -1;
    return (r[a][b]+1)/2;
}

int getLeft(int a, int b) {
    if (l[a][b] != 0) return (l[a][b]+1)/2;
    if ((ok[a-1]&posi[a][b]).count()) l[a][b] = 1;
    else l[a][b] = -1;
    return (l[a][b]+1)/2;
}

void tri(int l, int r) {
    if (l > r) return;
    if (done[l][r]) return;
    done[l][r] = 1;
    FOR(i,l,r+1) {
        tri(l,i-1); tri(i+1,r);
        if (i == l || getRight(l,i-1))
            if (i == r || getLeft(i+1,r))
                posi[l][r][i] = 1;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    F0R(i,n) {
        cin >> a[i];
        // a[i] = 2;
    }
    F0R(i,n) F0R(j,n) if (__gcd(a[i],a[j]) > 1) ok[i][j] = 1;
    // cout << getRight(0,0) << " " << getLeft(1,1) << "\n";
    tri(0,n-1);
    if (posi[0][n-1].count()) cout << "Yes";
    else cout << "No";
}

/* Look for:
* the exact constraints (multiple sets are too slow for n=10^6 :( ) 
* special cases (n=1?)
* overflow (ll vs int?)
* array bounds
* if you have no idea just guess the appropriate well-known algo instead of doing nothing :/
*/