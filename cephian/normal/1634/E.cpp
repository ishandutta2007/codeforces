#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;

vector<vector<pii>> bins;
map<int, vector<pii>> by_num;
vector<vector<bool>> used;
vector<string> ans;
vector<vector<int>> a;

void search_bin(int i, int j);

void search_val(int i, int j) {
	used[i][j] = true;
	ans[i][j] = 'R';
	while(by_num[a[i][j]].size()) {
		auto top = by_num[a[i][j]].back();
		if(used[top.first][top.second]) {
			by_num[a[i][j]].pop_back();
			continue;
		}
		search_bin(top.first, top.second);
		return;
	}
}

void search_bin(int i, int j) {
	used[i][j] = true;
	ans[i][j] = 'L';
	while(bins[i].size()) {
		auto top = bins[i].back();
		if(used[top.first][top.second]) {
			bins[i].pop_back();
			continue;
		}
		search_val(top.first, top.second);
		return;
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int m;
	cin >> m;
	bins.resize(m);
	a.resize(m);
	for (int i = 0; i < m; ++i) {
		int n;
		cin >> n;
		a[i].resize(n);
		for (size_t j = 0; j < n; ++j) {
			cin >> a[i][j];
			bins[i].emplace_back(i, j);
			by_num[a[i][j]].emplace_back(i, j);
		}
		ans.push_back(string(n, 'X'));
		used.push_back(vector<bool>(n));
	}

	for(const auto& x : by_num) {
		if(x.second.size()%2 == 1) {
			cout << "NO" << endl;
			return 0;
		}
	}

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < ans[i].size(); ++j) {
			if(used[i][j]) continue;
			search_val(i, j);
		}
	}

	cout << "YES" << endl;
	for (auto& s : ans)
		cout << s << '\n';
}