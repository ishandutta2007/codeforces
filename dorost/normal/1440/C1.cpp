/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 105;
vector <vector <pair <int, int>>> ans;
string s[N];
int a[4], x1, yy;

void handle(vector <pair <int, int>> v) {
	for (int i = 0; i < v.size(); i++) {
		a[(v[i].F - x1)+ (v[i].S - yy) * 2] = 1 - a[(v[i].F - x1) + (v[i].S - yy) * 2];
		s[v[i].F][v[i].S] = (s[v[i].F][v[i].S] == '0' ? '1' : '0');
	}
}

void go(int x, int y) {
	x1 = x;
	yy = y;
	a[0] = s[x][y] - '0';
	a[1] = s[x + 1][y] - '0';
	a[2] = s[x][y + 1] - '0';
	a[3] = s[x + 1][y + 1] - '0';
	pair <int, int> b[4] = {{x, y}, {x + 1, y}, {x, y + 1}, {x + 1, y + 1}};
	if (a[0] + a[1] + a[2] + a[3] == 0) {
		return;
	}
	if (a[0] + a[1] + a[2] + a[3] == 1) {
		vector <pair <int, int>> v1, v2, v3;
		for (int i = 0; i < 4; i++) {
			if (a[i]) {
				v1.push_back(b[i]);
			}
		}
		for (int i = 0; i < 4; i++) {
			if (!a[i] && v1.size() < 3) {
				v1.push_back(b[i]);
			}
		}
		handle(v1);
		for (int i = 0; i < 4; i++) {
			if (!a[i]) {
				v2.push_back(b[i]);
			}
		}
		for (int i = 0; i < 4; i++) {
			if (a[i] && v2.size() < 3) {
				v2.push_back(b[i]);
			}
		}
		handle(v2);
		for (int i = 0; i < 4; i++) {
			if (a[i]) {
				v3.push_back(b[i]);
			}
		}
		handle(v3);
		ans.push_back(v1);
		ans.push_back(v2);
		ans.push_back(v3);
		return;
	}
	if (a[0] + a[1] + a[2] + a[3] == 2) {
		vector <pair <int, int>> v2, v3;
		for (int i = 0; i < 4; i++) {
			if (!a[i]) {
				v2.push_back(b[i]);
			}
		}
		for (int i = 0; i < 4; i++) {
			if (a[i] && v2.size() < 3) {
				v2.push_back(b[i]);
			}
		}
		handle(v2);
		for (int i = 0; i < 4; i++) {
			if (a[i]) {
				v3.push_back(b[i]);
			}
		}
		handle(v3);
		ans.push_back(v2);
		ans.push_back(v3);
		return;
	}
	if (a[0] + a[1] + a[2] + a[3] == 3) {
		vector <pair <int, int>> v3;
		for (int i = 0; i < 4; i++) {
			if (a[i]) {
				v3.push_back(b[i]);
			}
		}
		ans.push_back(v3);
		handle(v3);
		return;
	}
	if (a[0] + a[1] + a[2] + a[3] == 4) {
		vector <pair <int, int>> v1, v2, v3, v4 = {b[0], b[1], b[2]};
		handle(v4);
		for (int i = 0; i < 4; i++) {
			if (a[i]) {
				v1.push_back(b[i]);
			}
		}
		for (int i = 0; i < 4; i++) {
			if (!a[i] && v1.size() < 3) {
				v1.push_back(b[i]);
			}
		}
		handle(v1);
		for (int i = 0; i < 4; i++) {
			if (!a[i]) {
				v2.push_back(b[i]);
			}
		}
		for (int i = 0; i < 4; i++) {
			if (a[i] && v2.size() < 3) {
				v2.push_back(b[i]);
			}
		}
		handle(v2);
		for (int i = 0; i < 4; i++) {
			if (a[i]) {
				v3.push_back(b[i]);
			}
		}
		handle(v3);
		ans.push_back(v1);
		ans.push_back(v2);
		ans.push_back(v3);
		ans.push_back(v4);
		return;
	}
}

void solve() {
	ans.clear();
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m - 1; j++) {
			go(i, j);
		}
	}
	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++) {
		assert(ans[i].size() == 3);
		cout << ans[i][0].F + 1 << ' ' << ans[i][0].S + 1 << ' ' << ans[i][1].F + 1 << ' ' << ans[i][1].S + 1 << ' ' << ans[i][2].F + 1 << ' ' << ans[i][2].S + 1 << '\n';
	}
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}