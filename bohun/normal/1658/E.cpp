#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= int(b); i++)
#define per(i, a, b) for (int i = b; i >= int(a); i--)
#define cat(x) cerr << #x << ": " << x << endl
#define sz(x) int(x.size())
using namespace std;
using ll = long long;

const int N = 2048;
int n, k, res[N][N];

void solve() {
	vector<tuple<int, int, int>> v;
	deque<tuple<int, int, int>> a, b;
	cin >> n >> k;
	rep(i, 1, n) {
		rep(j, 1, n) {
			int x;
			cin >> x;
			a.push_back({i + j, i, j});
			b.push_back({i - j, i, j});
			v.push_back({x, i, j});
			res[i][j] = -1;
		}
	}
	sort(v.rbegin(), v.rend());
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	int L = 1, R = n;
	for (auto [_, x, y] : v) {
		if (res[x][y] != -1) continue;
		auto manhatan = [](int x, int y, int x1, int y1) {
			return abs(x - x1) + abs(y - y1);
		};
		auto update = [&](auto &q) {
			while (!q.empty()) {
				auto [_1, x1, y1] = q.front();
				if (res[x1][y1] >= 0) {
					q.pop_front();
					continue;
				}
				if (manhatan(x, y, x1, y1) > k) {
					res[x1][y1] = 1;
					q.pop_front();
				}
				else break;
			}
			while (!q.empty()) {
				auto [_1, x1, y1] = q.back();
				if (res[x1][y1] >= 0) {
					q.pop_back();
					continue;
				}
				if (manhatan(x, y, x1, y1) > k) {
					res[x1][y1] = 1;
					q.pop_back();
				}
				else break;
			}
		};
		update(a);
		update(b);
		res[x][y] = 0;
	}

	rep(i, 1, n) {
		rep(j, 1, n) 
			cout << (res[i][j] ? 'G' : 'M');
		cout << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T = 1;
	// cin >> T;
	while (T--) solve();
	return 0;
}