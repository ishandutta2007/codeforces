#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
	ios::sync_with_stdio(0);

	int n, m;
	cin >> n >> m;
	int price[n];
	for (int i = 0; i < n; ++i)
		cin >> price[i];
	vector<set<int> > adj(n, set<int>());
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a;
		--b;
		adj[min(a, b)].insert(max(a, b));
	}
	int mn = 0x7fffffff;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (adj[i].find(j) == adj[i].end())
				continue;
			for (int k = j + 1; k < n; ++k) {
				if (adj[i].find(k) == adj[i].end() || adj[j].find(k) == adj[j].end())
					continue;
				mn = min(mn, price[i] + price[j] + price[k]);
			}
		}
	}
	if (mn == 0x7fffffff)
		cout << "-1\n";
	else
		cout << mn << "\n";

	return 0;
}