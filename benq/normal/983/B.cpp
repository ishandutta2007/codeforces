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

int n,mx[5000][5000], val[5000][5000];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    
    F0R(i,n) {
        cin >> val[0][i];
        mx[0][i] = val[0][i];
    }
    FOR(i,1,n) F0R(j,n-i) {
        val[i][j] = val[i-1][j]^val[i-1][j+1];
        mx[i][j] = max(val[i][j],max(mx[i-1][j],mx[i-1][j+1]));
    }
    
    int q; cin >> q;
    F0R(i,q) {
        int l,r; cin >> l >> r; 
        cout << mx[r-l][l-1] << "\n";
    }
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?)