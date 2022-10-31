#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios::sync_with_stdio(0);
	int n; cin >> n;
	vector<pair<int, int> > ans;
	for (int i = 0; i < 6; i++) {
		if (~i & 1) {
			for (int j = 0; j < 8; j++) {
				ans.emplace_back(j, i);
			}
		} else {
			for (int j = 7; j >= 0; j--) {
				ans.emplace_back(j, i);
			}
		}
	}
	for (int i = 0; i < 6; i++) {
		if (~i & 1) {
			ans.emplace_back(i, 6);
			ans.emplace_back(i, 7);
		} else {
			ans.emplace_back(i, 7);
			ans.emplace_back(i, 6);
		}
	}
	ans.emplace_back(7, 6);
	ans.emplace_back(6, 6);
	ans.emplace_back(6, 7);
	ans.emplace_back(7, 7);
	bool vis[8][8] = {0};
	auto solve = [&](int n) {
		if (n == 63) return ans;
		if (n == 62) {
			ans.pop_back();
			ans.pop_back();
			ans.pop_back();
			ans.pop_back();
			ans.emplace_back(6, 6);
			ans.emplace_back(6, 7);
			ans.emplace_back(7, 7);
			return ans;
		}
		ans.resize(n - 1);
		for (auto t : ans) vis[t.first][t.second] = 1;
		int x = ans.back().first, y = ans.back().second;
		if (x != 7 && y != 7) {
			if (!vis[x][7]) {
				ans.emplace_back(x, 7);
				ans.emplace_back(7, 7);
				return ans;
			}
			if (!vis[7][y]) {
				ans.emplace_back(7, y);
				ans.emplace_back(7, 7);
				return ans;
			}
			assert(0);
		}
		if (x != 7) {
			assert(x < 6);
			assert(!vis[x+1][7]);
			ans.emplace_back(x+1, 7);
			ans.emplace_back(7, 7);
			return ans;
		}
		if (y != 7) {
			assert(y < 6);
			assert(!vis[7][y+1]);
			ans.emplace_back(7, y+1);
			ans.emplace_back(7, 7);
			return ans;
		}
	};
	auto print = [&](vector<pair<int, int> > &ans) {
		for (auto t : ans) {
			putchar(t.first + 'a');
			putchar(t.second + '1');
			putchar(' ');
		}
		puts("");
	};
	auto ret = solve(n);
	print(ret);
	return 0;
}