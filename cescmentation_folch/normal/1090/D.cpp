#include <bits/stdc++.h>

using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector <vector <int> >v(n);
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	if (n == 1) {
		cout << "NO" << endl;
		return 0;
	}
	vector <int>p(n);
	p[0] = p[1] = -1;
	for (int i = 0; i < n; ++i) {
		if (v[i].size() < n-1) {
			p[0] = i;
			vector <bool>bb(n, false);
			bb[i] = true;
			for (int j = 0; j < v[i].size(); ++j) {
				bb[v[i][j]] = true;
			}
			for (int j = 0; j < n; ++j) {
				if (!bb[j]) {
					p[1] = j;
					break;
				}
			}
			break;
		}
	}
	if (p[0] == -1) {
		cout << "NO" << endl;
		return 0;
	}
	int cnt = 0;
	for (int i = 2; i < n; ++i) {
		if (cnt == p[0] || cnt == p[1]) ++cnt;
		if (cnt == p[0] || cnt == p[1]) ++cnt;
		p[i] = cnt++;
	}
	vector <int>ind(n);
	for (int i = 0; i < n; ++i) {
		ind[p[i]] = i;
	}
	vector <int>ans(n, 1);
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < v[p[i]].size(); ++j) {
			if (i > ind[v[p[i]][j]]) {
				ans[p[i]] = max(ans[p[i]], ans[v[p[i]][j]]+1);
			}
		}
	}
	
	cout << "YES" << endl;
	for (int i = 0; i < n; ++i) {
		cout << ind[i]+1 << " ";
	}
	cout << endl;
	for (int i = 0; i < n; ++i) {
		cout << ans[i] << " ";
	}
	cout << endl;
	return 0;
}