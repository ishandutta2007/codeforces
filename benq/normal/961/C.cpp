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

int n, ans=MOD;
char g[4][100][100], ret[200][200];

void solve() {
    int cur = 0;
    F0R(i,2*n) F0R(j,2*n) if (ret[i][j] != char('0'+int((i+j)%2))) cur ++;
    ans = min(ans,cur);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    F0R(i,4) F0R(j,n) F0R(k,n) cin >> g[i][j][k];
    vi z = {0,1,2,3};
    do {
        F0R(i,n) F0R(j,n) ret[i][j] = g[z[0]][i][j];
        F0R(i,n) F0R(j,n) ret[i][j+n] = g[z[1]][i][j];
        F0R(i,n) F0R(j,n) ret[i+n][j] = g[z[2]][i][j];
        F0R(i,n) F0R(j,n) ret[i+n][j+n] = g[z[3]][i][j];
        solve();
    } while (next_permutation(all(z)));
    cout << ans;
}

// read the question correctly (is y a vowel?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?)