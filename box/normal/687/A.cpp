// writer: w33z8kqrqk8zzzx33
#include <bits/stdc++.h>
using namespace std;

#define iter(i, a, b) for(int i=(a); i<(b); i++)
#define rep(i, a) iter(i, 0, a)
#define rep1(i, a) iter(i, 1, (a)+1)
#define fi first
#define se second
#define pb push_back
 
#define ll long long
#define pii pair<int, int>
//#define int ll
const int MOD = 1000000007;

int part[100005];
vector<int> elist[100005];
vector<int> nn[3];

void dfs(int u, int mark) {
	if(part[u] == mark) return;
	if(part[u]) {
		cout << -1 << endl;
		exit(0);
	}
	part[u] = mark;
	nn[mark].pb(u);
	for(int& v:elist[u]) dfs(v, 3-mark);
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    rep1(i, m) {
    	int u, v; cin >> u >> v;
    	elist[u].pb(v);
    	elist[v].pb(u);
    }
    rep1(i, n) if(!part[i]) dfs(i, 1);
    rep1(i, 2) {
    	cout << nn[i].size() << endl;
    	for(int&k:nn[i]) cout << k << ' ';
    	cout << endl;
    }
}