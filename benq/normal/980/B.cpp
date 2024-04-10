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

int n,k;
bool g[4][100];
vpi a, b;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n-1-i; ++i) {
        if (i == n-1-i) a.pb({1,i}), a.pb({2,i});
        else b.pb({1,i}), b.pb({2,i});
    }
    while (sz(b) && k >= 2) {
        g[b.back().f][b.back().s] = g[b.back().f][n-1-b.back().s] = 1;
        b.pop_back();
        k -= 2;
    }
    while (sz(a) && k) {
        g[a.back().f][a.back().s] = g[a.back().f][n-1-a.back().s] = 1;
        a.pop_back();
        k --;
    }
    cout << "YES\n";
    F0R(i,4) {
        F0R(j,n) {
            if (g[i][j] == 0) cout << '.';
            else cout << '#';
        }
        cout << "\n";
    }
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?)