/*#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>*/
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

vi child[10001];
ll dp[1001][2][2];
pair<ll,pair<ll,ll>> dance[1001];
int n, par[1001]; 

ll sqdist(pair<ll,ll> a, pair<ll,ll> b) {
	a.f -= b.f, a.s -= b.s;
	return a.f*a.f+a.s*a.s;
}

void dfs(int p, int node) {
	for (int i: child[node]) dfs(node,i);
	F0R(i,2) F0R(j,2) {
		ll ans1 = dance[node].f*dance[node].f;
		if (i) ans1 = -ans1;
		for (int c: child[node]) ans1 += dp[c][i^1][j];
		
		ll ans2 = dance[node].f*dance[node].f;
		if (j) ans2 = -ans2;
		for (int c: child[node]) ans2 += dp[c][i][j^1];
		dp[node][i][j] = max(ans1,ans2);
	}
}

int main() {
	cin >> n;
	FOR(i,1,n+1) cin >> dance[i].s.f >> dance[i].s.s >> dance[i].f;
	sort(dance+1,dance+n+1);
	
	FOR(i,1,n+1) FOR(j,1,i) if (par[j] == 0) 
		if (sqdist(dance[i].s,dance[j].s) < dance[i].f*dance[i].f) {
			child[i].pb(j);
			par[j] = i;
			// cout << i << " " << " " << j << "\n";
		}
	
	ll ans = 0;
	FOR(i,1,n+1) if (par[i] == 0) {
		dfs(i,i);
		ans += dp[i][0][0];
	}
	cout << fixed << setprecision(9) << PI*ans;
}