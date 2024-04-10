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

int n,k;
bool in[MX];
vi adj[MX], ans;
int par[MX][20];

void dfs(int x) {
    FOR(i,1,20) par[x][i] = par[par[x][i-1]][i-1];
    for (int i: adj[x]) if (i != par[x][0]) {
        par[i][0] = x;
        dfs(i);
    }
}

void ins(int x) {
    while (x && !in[x]) {
        in[x] = 1;
        ans.pb(x);
        x = par[x][0];
    }
}

int getPar(int x, int y) {
    F0Rd(i,20) if (y&(1<<i)) x = par[x][i];
    return x;
}

bool ok(int x) {
    return in[getPar(x,n-k-sz(ans))];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    F0R(i,n-1) {
        int a,b; cin >> a >> b;
        adj[a].pb(b), adj[b].pb(a);
    }
    
    dfs(n);
    in[0] = 1;
    FORd(i,1,n+1) if (!in[i]) if (ok(i)) ins(i);
    sort(all(ans));
    vi res; FOR(i,1,n+1) if (!in[i]) res.pb(i);
    for (int i: res) cout << i << " ";
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?)