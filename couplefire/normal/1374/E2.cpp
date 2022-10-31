#include <bits/stdc++.h>

using namespace std;

const int INF = 2e9 + 1;

#define size(a) int((a).size())

void updateSt(set<pair<int, int>> &st, set<pair<int, int>> &fr, int &sum, int need) {
	need = max(need, 0);
	while (true) {
		bool useful = false;
		while (size(st) > need) {
			sum -= st.rbegin()->first;
			fr.insert(*st.rbegin());
			st.erase(prev(st.end()));
			useful = true;
		}
		while (size(st) < need && size(fr) > 0) {
			sum += fr.begin()->first;
			st.insert(*fr.begin());
			fr.erase(fr.begin());
			useful = true;
		}
		while (!st.empty() && !fr.empty() && fr.begin()->first < st.rbegin()->first) {
			sum -= st.rbegin()->first;
			sum += fr.begin()->first;
			fr.insert(*st.rbegin());
			st.erase(prev(st.end()));
			st.insert(*fr.begin());
			fr.erase(fr.begin());
			useful = true;
		}
		if (!useful) break;
	}
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int n, m, k;
	cin >> n >> m >> k;
	vector<pair<int, int>> times[4];
	vector<int> sums[4];
	for (int i = 0; i < n; ++i) {
		int t, a, b;
		cin >> t >> a >> b;
		times[a * 2 + b].push_back({t, i});
	}
	for (int i = 0; i < 4; ++i) {
		sort(times[i].begin(), times[i].end());
		sums[i].push_back(0);
		for (auto it : times[i]) {
			sums[i].push_back(sums[i].back() + it.first);
		}
	}
	
	int ans = INF;
	int pos = INF;
	set<pair<int, int>> st;
	set<pair<int, int>> fr;
	int sum = 0;
	vector<int> res;
	for (int iter = 0; iter < 2; ++iter) {
		st.clear();
		fr.clear();
		sum = 0;
		int start = 0;
		while (k - start >= size(sums[1]) || k - start >= size(sums[2]) || m - start - (k - start) * 2 < 0) {
			++start;
		}
		if (start >= size(sums[3])) {
			cout << -1 << endl;
			return 0;
		}
		int need = m - start - (k - start) * 2;
		for (int i = 0; i < 3; ++i) {
			for (int p = size(times[i]) - 1; p >= (i == 0 ? 0 : k - start); --p) {
				fr.insert(times[i][p]);
			}
		}
		updateSt(st, fr, sum, need);
		for (int cnt = start; cnt < (iter == 0 ? size(sums[3]) : pos); ++cnt) {
			if (k - cnt >= 0) {	
				if (cnt + (k - cnt) * 2 + size(st) == m) {
					if (ans > sums[3][cnt] + sums[1][k - cnt] + sums[2][k - cnt] + sum) {
						ans = sums[3][cnt] + sums[1][k - cnt] + sums[2][k - cnt] + sum;
						pos = cnt + 1;
					}
				}
			} else {
				if (cnt + size(st) == m) {
					if (ans > sums[3][cnt] + sum) {
						ans = sums[3][cnt] + sum;
						pos = cnt + 1;
					}
				}
			}
			if (iter == 1 && cnt + 1 == pos) break;
			need -= 1;
			if (k - cnt > 0) {
				need += 2;
				fr.insert(times[1][k - cnt - 1]);
				fr.insert(times[2][k - cnt - 1]);
			}
			updateSt(st, fr, sum, need);
		}
		if (iter == 1) {
			for (int i = 0; i + 1 < pos; ++i) res.push_back(times[3][i].second);
			for (int i = 0; i <= k - pos; ++i) {
				res.push_back(times[1][i].second);
				res.push_back(times[2][i].second);
			}
			for (auto [value, position] : st) res.push_back(position);
		}
	}
	
	cout << ans << endl;
	for (auto it : res) cout << it + 1 << " ";
	cout << endl;
	
	return 0;
}