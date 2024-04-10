#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> k;
vector<pair<int, int>> q(200001);

bool can(int day) {
	vector<int> lst(n, -1);
	for (int i = 0; i < m; ++i) {
		if (q[i].first <= day) {
			lst[q[i].second] = max(lst[q[i].second], q[i].first);
		}
	}
	vector<vector<int>> off(200001);
	for (int i = 0; i < n; ++i) {
		if (lst[i] != -1) {
			off[lst[i]].push_back(i);
		}
	}
	vector<int> need = k;
	int cur_money = 0;
	for (int i = 0; i <= day; ++i) {
		++cur_money;
		if (i > 200000) continue;
		for (auto it : off[i]) {
			if (cur_money >= need[it]) {
				cur_money -= need[it];
				need[it] = 0;
			} else {
				need[it] -= cur_money;
				cur_money = 0;
				break;
			}
		}
	}
	return accumulate(need.begin(), need.end(), 0) * 2 <= cur_money;
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	cin >> n >> m;
	k = vector<int>(n);
	for (int i = 0; i < n; ++i) {
		cin >> k[i];
	}
	for (int i = 0; i < m; ++i) {
		cin >> q[i].first >> q[i].second;
		--q[i].first;
		--q[i].second;
	}
	
	int l = 0, r = 400000;
	while (r - l > 1) {
		int mid = (l + r) >> 1;
		if (can(mid)) r = mid;
		else l = mid;
	}
	
	for (int i = l; i <= r; ++i) {
		if (can(i)) {
			cout << i + 1 << endl;
			return 0;
		}
	}
	
	assert(false);
	
	return 0;
}