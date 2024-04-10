#include <bits/stdc++.h>

using namespace std;
//using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

const int MOD = 1000000007;
double PI = 4*atan(1);

vi adj[200001];
int food[200001];

void dfs(int node, int fo) {
	if (food[node]) return;
	food[node] = fo;
	for (int i: adj[node]) dfs(i,(fo%2)+1);
}

int main() {
	int n; cin >> n;
	F0R(i,n) adj[2*i+1].pb(2*i+2), adj[2*i+2].pb(2*i+1);
	vector<pii> p;
	F0R(i,n) {
		int x,y; cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
		p.pb(mp(x,y));
	}
	FOR(i,1,2*n+1) dfs(i,1);
	F0R(i,n) cout << food[p[i].f] << " " << food[p[i].s] << "\n";
}