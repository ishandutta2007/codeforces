#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
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

const int MOD = 1000000007;

int n,m,k,q, parK[17][100001], loc[100001], depth[100001], sz[100001];
vi child[100001];

void init() {
    ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> m >> k >> q;
	F0R(i,k) {
	    int a,b; cin >> a >> b;
	    if (loc[b]) {
	        child[loc[b]].pb(a);
	        parK[0][a] = loc[b];
	    }
	    loc[b] = a;
	}
}

void dfs(int x) {
    sz[x] = 1;
    for (int i: child[x]) {
        depth[i] = depth[x]+1;
        dfs(i);
        sz[x] += sz[i];
    }
}

bool isanc(int x, int y) { // x is an ancestor of the y
    if (depth[y] < depth[x]) return 0;
    F0Rd(i,17) if (depth[y]-depth[x] >= (1<<i)) y = parK[i][y];
    return x == y;
}

int main() {
	init();
	F0R(k,16) FOR(i,1,n+1) parK[k+1][i] = parK[k][parK[k][i]];
	FOR(i,1,n+1) if (parK[0][i] == 0) dfs(i);
	F0R(i,q) {
	    int x,y; cin >> x >> y;
	    y = loc[y];
	    if (isanc(x,y)) cout << sz[x] << "\n";
	    else cout << "0\n";
	}
}
// read!
// ll vs. int!