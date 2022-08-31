
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
char g[100][100];
int num[100][100];
pi bes = {0,0};

bool ok1(int a, int b) {
    if (a+k > n) return 0;
    F0R(z,k) if (g[a+z][b] == '#') return 0;
    return 1;
}
bool ok2(int a, int b) {
    if (b+k > n) return 0;
    F0R(z,k) if (g[a][b+z] == '#') return 0;
    return 1;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    F0R(i,n) F0R(j,n) cin >> g[i][j];
    F0R(i,n) F0R(j,n) {
        if (ok1(i,j)) {
            // cout << i << " " << j << "\n";
            F0R(z,k) num[i+z][j] ++;
        }
        if (ok2(i,j)) {
            F0R(z,k) num[i][j+z] ++;
        }
    }
    F0R(i,n) F0R(j,n) if (num[i][j] > num[bes.f][bes.s]) bes = {i,j};
    cout << bes.f+1 << " " << bes.s+1;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?)