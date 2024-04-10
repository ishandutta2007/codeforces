#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<short> vi;
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

const int MOD = 30000;

int n,m,q;
bool reach[3001][3001];
short nex[3001][3001][13];
vi adj[3001];

void dfs(int ori, int cur) {
    reach[ori][cur] = 1;
    for (int i: adj[cur]) if (!reach[ori][i]) dfs(ori,i);
}

void init() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> m >> q;
	F0R(i,m) {
	    int a,b; cin >> a >> b;
	    adj[a].pb(b);
	}
	FOR(i,1,n+1) dfs(i,i);
	FOR(i,1,n+1) {
	    FOR(j,1,n+1) nex[i][j][0] = MOD;
	    for (short j: adj[i]) FOR(k,1,n+1) if (reach[j][k]) nex[i][k][0] = min(nex[i][k][0],j);
	    nex[i][i][0] = MOD;
	}
	F0R(k,12) FOR(i,1,n+1) FOR(j,1,n+1) {
	    if (nex[i][j][k] == MOD) nex[i][j][k+1] = MOD;
	    else nex[i][j][k+1] = nex[nex[i][j][k]][j][k];
	}
}

int query(int s, int t, int k) {
    if (nex[s][t][12] != MOD) return -1;
    if (nex[s][t][0] == MOD) return -1;
    k--;
    F0Rd(i,12) if (k&(1<<i)) {
        s = nex[s][t][i];
        if (s == MOD) return -1;
    }
    return s;
}

int main() {
    init();
    F0R(i,q) {
        int s,t,k; cin >> s >> t >> k;
        cout << query(s,t,k) << "\n";
    }
}

// read!
// ll vs. int!