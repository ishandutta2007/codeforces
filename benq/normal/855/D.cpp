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

int n, type[100001], depth[100001];
int parK[17][100001];
bool ok[17][100001][2];

bool query1(int u, int v) {
    // is u a parent of v only traversing edges labelled with 0?
    if (depth[v] < depth[u]) return 0;
    bool f = 1;
    F0Rd(i,17) if (depth[v]-depth[u] >= (1<<i)) {
        f &= ok[i][v][0];
        v = parK[i][v];
    }
    if (u != v) return 0;
    return f;
}

bool query2(int u, int v) {
    // u goes up using only zero edges
    // v goes up using only one edges
    int v1 = v;
    bool fu = 1, fv = 1;
    F0Rd(k,17) if (depth[u] >= depth[v]+(1<<k)) {
        fu &= ok[k][u][0];
        u = parK[k][u];
    }
    F0Rd(k,17) if (depth[v] >= depth[u]+(1<<k)) {
        fv &= ok[k][v][1];
        v = parK[k][v];
    }
    F0Rd(k,17) if(parK[k][u] != parK[k][v]) {
        fu &= ok[k][u][0], fv &= ok[k][v][1];
        u = parK[k][u], v = parK[k][v];
    }
    if (u != v) {
        fu &= ok[0][u][0], fv &= ok[0][v][1];
        u = parK[0][u], v = parK[0][v];
    }
    if (u != v || u == 0) return 0;
    if (v == v1) return 0;
    if (!fu || !fv) return 0;
    return 1;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n;
	FOR(i,1,n+1) {
	    cin >> parK[0][i] >> type[i];
	    if (parK[0][i] == -1) parK[0][i] = 0;
	    depth[i] = depth[parK[0][i]]+1;
	    if (type[i] != -1) ok[0][i][type[i]] = 1;
	}
	F0R(j,16) {
	    FOR(i,1,n+1) {
	        parK[j+1][i] = parK[j][parK[j][i]];
	        ok[j+1][i][0] = ok[j][i][0] & ok[j][parK[j][i]][0];
	        ok[j+1][i][1] = ok[j][i][1] & ok[j][parK[j][i]][1];
	    }
	}
	int q; cin >> q;
	F0R(i,q) {
	    int t,u,v; cin >> t >> u >> v;
	    if (u == v) {
	        cout << "NO\n";
	        continue;
	    }
	    bool ans = 0;
	    if (t == 1) ans = query1(u,v);
	    else ans = query2(u,v);
	    
	    if (ans) cout << "YES\n";
	    else cout << "NO\n";
	}
}

// read!
// ll vs. int!