#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5+5;
vector<pair<int,int>> better[N];
vector<pair<int,int>> worse[N];

inline ll calc(int v) {
	return better[v].size() * worse[v].size();
}

int main() {	
	ios::sync_with_stdio(0), cin.tie(0);
	int n, m, q;
	cin >> n >> m;
	for(int i = 1; i <= m; ++i) {
		int a, b;
		cin >> a >> b;
		if(b < a) swap(a,b);
		worse[b].emplace_back(a, better[a].size());
		better[a].emplace_back(b, worse[b].size()-1);
	}
	// initial count
	ll bad = 0;
	for(int v = 1; v <= n; ++v)
		bad += calc(v);
	cout << bad << '\n';

	cin >> q;
	for(int i = 0; i < q; ++i) {
		int v;
		cin >> v;
		bad -= calc(v);
		for(const pair<int,int> p : better[v]) {
			const int u = p.first;
			const int idx = p.second;
			bad -= calc(u);

			// erase old link
			worse[u][idx] = worse[u].back();
			worse[u].pop_back();
			better[worse[u][idx].first][worse[u][idx].second].second = idx;

			// add new link
			worse[v].emplace_back(u, better[u].size());
			better[u].emplace_back(v, worse[v].size()-1);

			bad += calc(u);
		}
		better[v].resize(0);
		cout << bad << '\n';
	}
}