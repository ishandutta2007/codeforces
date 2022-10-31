#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
pair<long long,int> net[N] = {};

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		net[i].second = i;
	for(int i = 0; i < m; ++i) {
		int u, v, d;
		cin >> u >> v >> d;
		net[u].first -= d;
		net[v].first += d;
	}

	sort(net+1, net+n+1);
	vector<tuple<int,int,long long>> ans;

	int ii = 1, jj = n;
	while(ii < jj) {
		if(net[ii].first == 0) ++ii;
		else if(net[jj].first == 0) --jj;
		else {
			long long give = min(net[jj].first, -net[ii].first);
			net[jj].first -= give;
			net[ii].first += give;
			ans.emplace_back(net[ii].second, net[jj].second, give);
		}
	}
	cout << ans.size() << '\n';
	for(const auto& t : ans) {
		int a, b;
		long long c;
		tie(a,b,c) = t;
		cout << a << ' ' << b << ' ' << c << '\n';
	}
}