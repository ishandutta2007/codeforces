#include <bits/stdc++.h>

using namespace std;

bool visit[200001];
int dp[200001], p[200001];
vector<int> t[200001];
set<pair<int, int>> s;


void dfs(int v, int depth) {
	if(visit[v])
		return;
	visit[v] = 1;
	if(depth > 2)
		s.insert({depth, v});
	dp[v] = depth;
	for(int ch:t[v]) {
		if(!visit[ch]) {
			p[ch] = v;
			dfs(ch, depth+1);
		}
	}
}

int main()
{
	int n;
	cin >> n;
	for(int i=0;i<n-1;i++) {
		int u, v;
		cin >> u >> v;
		t[u].push_back(v);
		t[v].push_back(u);
	}
	dfs(1, 0);
	int ans = 0;
	while(s.size()) {
		int v = prev(s.end()) -> second;
		int u = p[v];
		auto it = s.find({dp[u], u});
		if (it != s.end())
			s.erase(it);
		for (auto it2 : t[u]) {
			auto it = s.find({dp[it2], it2});
			if (it != s.end())
				s.erase(it);
		}
		ans++;
	}
	cout << ans << endl;
}