#include <bits/stdc++.h>
using namespace std;
#define int long long

#define sz(x) (int)(x).size()

vector<vector<int>> adj;
vector<map<int, int>> score;
vector<int> s;

int dfs(int node, int k) {
	// score assuming k paths travel through node.
	if(adj[node].empty()) return k * s[node];
	if(score[node].find(k) != score[node].end()) return score[node][k];
	vector<pair<int, int>> v;
	int c = sz(adj[node]);
	for(auto next : adj[node]) {
		pair<int, int> p;
		p.first = dfs(next, floor(k*1.0/c));
		p.second = dfs(next, ceil(k*1.0/c));
		v.push_back(p);
	}
	int rem = k % c; // ceil needed this many times.
	int ans = 0;
	sort(v.begin(), v.end(), [&](pair<int, int> a, pair<int, int> b) {
		return (a.second - a.first) > (b.second - b.first);
	});
	for(int i = 0; i < sz(v); i++) {
		if(i < rem) ans += v[i].second;
		else ans += v[i].first;
	}
	score[node][k] = ans + (s[node] * k);
	return score[node][k];
}

int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int t = 1;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		adj.clear(); adj.resize(n);
		score.clear(); score.resize(n);
		s.clear(); s.resize(n);
		for(int i = 1; i < n; i++) {
			int p; cin >> p;
			adj[p - 1].push_back(i);
		}
		for(int i = 0; i < n; i++) {
			cin >> s[i];
		}
		cout << dfs(0, k) << '\n';
	}
	
	return 0;
}