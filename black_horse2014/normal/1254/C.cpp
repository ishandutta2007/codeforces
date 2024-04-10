#include <bits/stdc++.h>
using namespace std;

long long query(int t, int i, int j, int k) {
	cout << t << " " << i + 1 << " " << j + 1 << " " << k + 1 << "\n";
	cout.flush();
	long long x; cin >> x;
	return x;
}

int main() {
	int n; cin >> n;
	vector<pair<long long, int>> a[2], b[2];
	for (int i = 2; i < n; i++) {
		pair<long long, int> p;
		p.first = query(1, 0, 1, i);
		p.second = i;
		a[query(2, 0, 1, i) == 1].push_back(p);
	}
	vector<int> ans;
	for (int z : {0, 1}) {
		ans.push_back(z);
		if (a[z].empty()) continue;
		int maxv = max_element(a[z].begin(), a[z].end())->second;
		for (auto t : a[z]) {
			if (t.second == maxv) continue;
			b[query(2, z, maxv, t.second) == 1].push_back(t);
		}
		for (int k : {0, 1}) {
			sort(b[k].begin(), b[k].end());
			if (k) reverse(b[k].begin(), b[k].end());
			for (auto x : b[k]) ans.push_back(x.second);
			if (!k) ans.push_back(maxv);
		}
		for (int i : {0, 1}) b[i].clear();
	}
	cout << "0";
	for (auto x : ans) cout << " " << x + 1;
	cout << "\n";
	cout.flush();
	return 0;
}