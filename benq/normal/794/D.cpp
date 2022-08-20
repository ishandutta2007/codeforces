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

int n,m;
vi adj[300001];
set<int> adj1[300001];
ll hsh[300001], tmp[300001];
int key[300001],nex=1;
map<ll,int> M;

void dfs(int x) {
    key[x] = nex++;
    for (int i: adj1[x]) if (key[i] > 0 && key[i] != key[x]-1) {
        cout << "NO";
        exit(0);
    }
    for (int i: adj1[x]) if (key[i] == 0) dfs(i);
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> m;
	srand(time(0));
	FOR(i,1,n+1) hsh[i] = tmp[i] = (ll)rand()+((ll)rand()<<15)+((ll)rand()<<30)+((ll)rand()<<45);
	F0R(i,m) {
	    int u,v; cin >> u >> v;
	    adj[u].pb(v), adj[v].pb(u);
	    hsh[u] ^= tmp[v], hsh[v] ^= tmp[u];
	}
	FOR(i,1,n+1) M[hsh[i]] = 1;
	int co = 0;
	for (auto& a: M) a.s = ++co;
	FOR(i,1,n+1) for (int j: adj[i]) if (hsh[i] != hsh[j]) adj1[M[hsh[i]]].insert(M[hsh[j]]);
	FOR(i,1,co+1) if (adj1[i].size() > 2) {
	    cout << "NO";
	    return 0;
	}
	FOR(i,1,co+1) if (adj1[i].size() <= 1 && !key[i]) {
	    dfs(i);
	    nex++;
	}
	FOR(i,1,co+1) if (key[i] == 0) {
	    cout << "NO";
	    return 0;
	}
	cout << "YES\n";
	FOR(i,1,n+1) cout << key[M[hsh[i]]] << " ";
}

// read!
// ll vs. int!