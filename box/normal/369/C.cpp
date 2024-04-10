
// Problem : C. Valera and Elections
// Contest : Codeforces Round #216 (Div. 2)
// URL : https://codeforces.com/problemset/problem/369/C
// Memory Limit : 256.000000 MB 
// Time Limit : 1000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

// writer: w33z8kqrqk8zzzx33
#include <bits/stdc++.h>
using namespace std;
 
#define iter(i, a, b) for(int i=(a); i<(b); i++)
#define rep(i, a) iter(i, 0, a)
#define rep1(i, a) iter(i, 1, (a)+1)
#define log(a) cerr<<"\033[32m[DEBUG] "<<#a<<'='<<(a)<<" @ line "<<__LINE__<<"\033[0m"<<endl
#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair
 
using ll=long long;
using pii=pair<int, int>;
//#define int ll
const int MOD = 1000000007;

vector<pii> elist[100005];
vector<int> sol;

int dfs(int node, int fa, int prob) {
	int mx = 1;
	for(pii& v:elist[node]) if(v.fi != fa) mx = max(mx, dfs(v.fi, node, v.se));
	if(mx == 1 && prob == 2) sol.pb(node);
	return max(mx, prob);
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
	rep(i, n-1) {
		int u, v, f; cin >> u >> v >> f;
		elist[u].pb({v, f}); elist[v].pb({u, f});
	}
	dfs(1, -1, 1);
	cout << sol.size() << endl;
	for(int& i:sol) cout << i << ' ';
	cout << endl;
}