#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef set<int> si;
typedef map<int,int> mii;

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
#define FORd(i,a,b) for (int i = b-1; i >= a; i--)
#define F0Rd(i,a) for (int i = a-1; i >= 0; i--)
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
 
const int MOD = 1000000007;
double PI = 4*atan(1);

ll n, ple[200000], ans = -(ll)MOD*MOD;
vector<ll> best[200000], adj[200000];

void dfs(int node, int p) {
	for (int x: adj[node]) if (x != p) {
		dfs(x,node);
		ple[node] += ple[x];
		best[node].pb(best[x][0]);
	}
	sort(best[node].begin(),best[node].end());
	reverse(best[node].begin(),best[node].end());
	if (best[node].size()>1) ans = max(ans,best[node][0]+best[node][1]);
	for(int i = best[node].size()-1; i > 0; --i) best[node].erase(best[node].begin()+i);
	best[node].pb(ple[node]);
	sort(best[node].begin(),best[node].end());
	reverse(best[node].begin(),best[node].end());
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n;
	F0R(i,n) cin >> ple[i];
	F0R(i,n-1) {
		int x,y; cin >> x >> y;
		adj[x-1].pb(y-1);
		adj[y-1].pb(x-1);
	}
	dfs(0,0);
	if (ans == -(ll)MOD*MOD) cout << "Impossible";
	else cout << ans;
}