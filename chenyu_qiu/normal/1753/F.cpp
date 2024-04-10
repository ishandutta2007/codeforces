#include <bits/stdc++.h>
using namespace std;

struct block {
	int mn, cnt[210];
	void init(int len) {
		mn = 0;
		memset(cnt, 0, (len + 5) * 4), cnt[0] = 1000;
	}
	void modify(int x, int y) {
		--cnt[x], ++cnt[y];
		while (!cnt[mn]) ++mn;
	}
};

struct my_ds {
	int a[1000010];
	block x[1010];
	void init(int sum, int len) {
		memset(a, 0, (sum + 5) * 4);
		for (int i = 1; i <= sum / 1000 + 5; ++i) x[i].init(len);
	}
	void modify(int pos, int val) {
		if (a[pos] < val) {
			int id = (pos - 1) / 1000 + 1;
			x[id].modify(a[pos], val), a[pos] = val;
		}
	}
	int query(int val) {
		int pos = 1;
		while (x[pos].mn >= val) ++pos;
		for (int i = (pos - 1) * 1000 + 1; ; ++i) if (a[i] < val) return i - 1;
	}
} t1, t2;

inline void update(int pos, int val) {
	if (pos > 0) t1.modify(pos, val);
	else t2.modify(-pos, val);
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);

	int n, m, k, t;
	cin >> n >> m >> k >> t, --t;
	vector<vector<vector<int>>> a(n, vector<vector<int>>(m));
	while (k--) {
		int x, y, w; cin >> x >> y >> w, --x, --y;
		if (abs(w) <= t) a[x][y].push_back(w);
	}

	int ans = 0;
	for (int s = -(m - 1); s <= (n - 1); ++s) {
		int x1 = (s < 0) ? 0 : s, y1 = (s < 0) ? -s : 0;
		int x = x1, y = y1, val = 0;
		int len = 0, sum = 0; 
		while (x + len < n && y + len < m) ++len;
		for (int i = 0; i < len; ++i)
			for (int j = 0; j < len; ++j)
				sum += a[x + i][y + j].size();
		t1.init(sum, len), t2.init(sum, len);
		for (int l = 0; x < n && y < m; ++x, ++y, ++l) {
			for (int i = 0; i <= l; ++i) {
				for (auto p : a[x - i][y]) if (abs(p) <= sum) update(p, l - i + 1);
				if (i) for (auto p : a[x][y - i]) if (abs(p) <= sum) update(p, l - i + 1);
			}
			while (val <= l && t1.query(val + 1) + t2.query(val + 1) >= t) ++val;
			ans += val;
		}
	}
	cout << ans << "\n";

	return 0;
}