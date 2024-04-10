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

int n,m, r[100001];
int par[200000];
vi adj[100001];

int getpar(int a) {
    if (par[par[a]] != par[a]) par[a] = getpar(par[a]);
    return par[a];
}

void unite(int a, int b) {
    a = getpar(a), b = getpar(b);
    if (a == b) return;
    if (rand()&1) swap(a,b);
    par[b] = a;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> m;
	F0R(i,2*m) par[i] = i;
	FOR(i,1,n+1) cin >> r[i]; // 1 is unlocked, 0 is locked
	F0R(i,m) {
	    int x; cin >> x;
	    F0R(j,x) {
	        int z; cin >> z;
	        adj[z].pb(i);
	    }
	}
	FOR(i,1,n+1) if (r[i]) {
	    unite(adj[i][0],adj[i][1]);
	    unite(adj[i][0]+m,adj[i][1]+m);
	} else {
	    unite(adj[i][0],adj[i][1]+m);
	    unite(adj[i][0]+m,adj[i][1]);
	}
	F0R(i,m) if (getpar(i) == getpar(i+m)) {
	    cout << "NO";
	    return 0;
	}
	cout << "YES";
}

// read!
// ll vs. int!