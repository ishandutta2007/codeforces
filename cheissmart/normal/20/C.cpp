#include <bits/stdc++.h>
#define int long long

using namespace std;

vector<pair<int, int>> G[200005];

int d[200005], pre[200005];

int32_t main()
{

	memset(d, 0x3f, sizeof d);
	int n, m;
	cin >>  n >> m;
	for(int i=0;i<m;i++) {
		int u, v, w;
		cin >> u >> v >> w;
		G[u].emplace_back(v, w);
		G[v].emplace_back(u, w);
	}
	d[1] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push(make_pair(d[1], 1));
	while(pq.size()) {
		pair<int, int> u = pq.top(); pq.pop();
		if(d[u.second] != u.first) continue;
		for(pair<int, int> v:G[u.second]) {
			if(d[u.second] + v.second < d[v.first]) {
				d[v.first] = d[u.second] + v.second;
				pre[v.first] = u.second;
				pq.push(make_pair(d[v.first], v.first));
			}
		}
	}
	if(d[n] == 0x3f3f3f3f3f3f3f3f) cout << -1 << endl;
	else {
		vector<int> path;
		int u = n;
		while(u) {
			path.push_back(u);
			u = pre[u];
		}
		reverse(path.begin(), path.end());
		for(int v:path)
			cout << v << " ";
		cout << endl;
	}
}