
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
const int MX = 1000001;

int n;
int val[MX];
bool bad[MX];
string s[MX];
vi child[MX];

void addEdge(int x, int y) {
    child[x].pb(y);
}

void dfs1(int x) {
    for (int i: child[x]) dfs1(i);
    if (s[x] == "IN") return;
    if (s[x] == "AND") val[x] = val[child[x][0]]&val[child[x][1]];
    if (s[x] == "XOR") val[x] = val[child[x][0]]^val[child[x][1]];
    if (s[x] == "OR") val[x] = val[child[x][0]]|val[child[x][1]];
    if (s[x] == "NOT") val[x] = !val[child[x][0]];
}

void dfs2(int x) {
    if (!bad[x]) return;
    if (s[x] == "IN") return;
    if (s[x] == "AND") {
        int t = (val[child[x][0]]^1)&(val[child[x][1]]);
        if (t != val[x]) bad[child[x][0]] = 1;
        t = (val[child[x][0]])&(val[child[x][1]]^1);
        if (t != val[x]) bad[child[x][1]] = 1;
    }
    if (s[x] == "XOR") {
        bad[child[x][0]] = 1;
        bad[child[x][1]] = 1;
    }
    if (s[x] == "OR") {
        int t = (val[child[x][0]]^1)|(val[child[x][1]]);
        if (t != val[x]) bad[child[x][0]] = 1;
        t = (val[child[x][0]])|(val[child[x][1]]^1);
        if (t != val[x]) bad[child[x][1]] = 1;
    }
    if (s[x] == "NOT") {
        bad[child[x][0]] = 1;
    }
    for (int i: child[x]) dfs2(i);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    FOR(i,1,n+1) {
        cin >> s[i];
        if (s[i] == "NOT") {
            int x; cin >> x;
            addEdge(i,x);
        } else if (s[i] == "IN") {
            int x; cin >> x;
            val[i] = x;
        } else {
            int x,y; cin >> x >> y;
            addEdge(i,x), addEdge(i,y);
        }
    }
    dfs1(1); 
    bad[1] = 1; dfs2(1);
    FOR(i,1,n+1) if (s[i] == "IN") {
        cout << (val[1]^bad[i]);
    }
}

/* Look for:
* the exact constraints (multiple sets are too slow for n=10^6 :( ) 
* special cases (n=1?)
* overflow (ll vs int?)
* array bounds
*/