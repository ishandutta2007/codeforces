#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mp make_pair
#define pb push_back
#define pii pair <int, int>
#define vi vector<int>

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
 
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define endl "\n"
 
const int MOD = 1000000007;
double PI = 4*atan(1);

double val[100005];
int numc[100005], par[100005];
vi child[100005];

int dfs(int node) {
	for (int i: child[node]) numc[node] += dfs(i);
	numc[node] ++;
	return numc[node];
}

void dfs2(int node) {
	val[node] = val[par[node]];
	val[node] += double(numc[par[node]]-numc[node]+1)/2.0;
	for (int i: child[node]) dfs2(i);
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n; cin >> n;
	FOR(i,2,n+1) {
		int x; cin >> x;
		child[x].pb(i);
		par[i] = x;
	}
	dfs(1);
	val[1] = 1.0;
	for (int i: child[1]) dfs2(i);
	cout << fixed << setprecision(1);
	FOR(i,1,n+1) cout << val[i] << " ";
	return 0;
}