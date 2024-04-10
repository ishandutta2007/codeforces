#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
using namespace std;
#pragma warning(disable:4996)
int n, m, a[400000], u, v, r[400000]; vector<int>x[400000], G;
int main() {
	cin >> n; m = n - 1;
	for (int i = 1; i <= n; i++)scanf("%d", &a[i]), G.push_back(a[i]);
	sort(G.begin(), G.end()); G.erase(unique(G.begin(), G.end()), G.end());
	for (int i = 1; i <= n; i++)a[i] = lower_bound(G.begin(), G.end(), a[i]) - G.begin(), r[a[i]]++;
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &u, &v);
		x[u].push_back(v); x[v].push_back(u);
	}
	int minx = 2e9;
	for (int i = 1; i <= n; i++) {
		vector<int>E;
		int p1 = G[a[i]], p2 = -2e9, p3 = 2e9; r[a[i]]--;
		for (int j = 0; j < x[i].size(); j++) { E.push_back(G[a[x[i][j]]]); p2 = max(p2, E[E.size() - 1]); r[a[x[i][j]]]--; }
		if (r[G.size() - 1] >= 1)p3 = G[G.size() - 1]; else if (G.size() >= 2 && r[G.size() - 2] >= 1)p3 = G[G.size() - 2]; else p3 = -2e9;
		for (int j = 0; j < x[i].size(); j++)r[a[x[i][j]]]++; r[a[i]]++;
		minx = min(minx, max({ p1,p2 + 1,p3 + 2 }));
	}
	cout << minx << endl;
	return 0;
}