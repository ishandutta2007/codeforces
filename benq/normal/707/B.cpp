#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair <int, int> pii;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
 
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define endl "\n"
 
const int MOD = 1000000007;
double PI = 4*atan(1);

vector<pii> adj[100001];
bool bak[100001];
vi bk;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n,m,k; cin >> n >> m >> k;
	int ans = MOD;
	F0R(i,m) {
		int u,v,l; cin >> u >> v >> l;
		adj[u].pb(mp(v,l));
		adj[v].pb(mp(u,l));
	}
	F0R(i,k) {
		int x; cin >> x;
		bk.pb(x);
		bak[x] = 1;
	}
	for (int i: bk) for (auto j: adj[i]) {
		if (bak[j.f] == 0) ans = min(ans,j.s);
	}
	if (ans == MOD) cout << -1;
	else cout << ans;
}