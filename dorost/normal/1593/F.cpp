/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 41;
int dp[N][N][N][N];
vector <int> v[N], v2[N];
int n, a, b;
string s;
pair <pair <pair <int, int>, pair <int, int>>, bool> p[N][N][N][N];

bool ans(int i, int x, int y, int j) {
	if (dp[i][x][y][j]) {
		return (bool)((int)dp[i][x][y][j] - 1);
	}
	if (j > i)
		return false;
	int c = s[i - 1] - '0';
	if (i == 1) {
		if (j == 0) {
			if ((s[i - 1] - '0') % b == y && x == 0) {
				p[i][x][y][j].S = false;
				return 1;
			} else 
				return 0;
		} else {
			if ((s[i - 1] - '0') % a == x && y == 0) {
				p[i][x][y][j].S = true;
				return 1;
			} else 
				return 0;
		}
	}
	bool f = false;
	int x2 = x - c, y2 = y - c;
	while (x2 < 0)
		x2 += a;
	while (y2 < 0)
		y2 += b;
	if (j != 0) {
		for (auto u : v[x2]) {
			f |= ans(i - 1, u, y, j - 1);
			if (ans(i - 1, u, y, j - 1)) {
				p[i][x][y][j] = {{{i - 1, u}, {y, j - 1}}, 1};
			}
		}
	}
	for (auto u : v2[y2]) {
		f |= ans(i - 1, x, u, j);
		if (ans(i - 1, x, u, j)) {
			p[i][x][y][j] = {{{i - 1, x}, {u, j}}, 0};
		}
	}
	if (i == 1 && x == 0 && y == 0 && j == 0) {
		cout << f << '\n';
	}
	dp[i][x][y][j] = (int)f + 1;
	return f;
}

void solve() {
	cin >> n >> a >> b >> s;
	for (int i = 0; i < N; i++) {
		v[i].clear();
		v2[i].clear();
	}
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= a; j++) {
			for (int k = 0; k <= b; k++) {
				for (int l = 0; l <= n; l++) {
					dp[i][j][k][l] = 0;
					p[i][j][k][l] = {{{-1, -1}, {-1, -1}}, -1};
				}
			}
		}
	}
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < a; j++) {
			if (j * 10 % a == i)
				v[i].push_back(j);
		}
	}
	for (int i = 0; i < b; i++) {
		for (int j = 0; j < b; j++) {
			if (j * 10 % b == i)
				v2[i].push_back(j);
		}
	}
//	cout << ":|";
//	for (int i = 0; i < v2[8].size(); i++)
//		cout << v2[8][i] << ' ';
//	cout << '\n';
	int ans2 = -1, mn = INT_MAX;
	for (int i = 1; i < n; i++) {
		if (ans(n, 0, 0, i)) {
			int x = abs(i - (n - i));
			if (x < mn) {
				mn = x;
				ans2 = i;
			}
		}
	}
	if (ans2 == -1) {
		cout << -1 << ' ';
		return;
	}
	string t;
	int x = 0, y = 0;
	for (int i = n; i >= 1; i--) {
//		cout << i << ' ' << x << ' ' << y << ' ' << ans2 << ' ' << p[i][x][y][ans2].S << endl;
		assert(ans(i, x, y, ans2));
		t += (p[i][x][y][ans2].S == 1 ? 'R' : 'B');
		pair <pair <pair <int, int>, pair <int, int>>, bool> o = p[i][x][y][ans2];
		x = o.F.F.S;
		y = o.F.S.F;
		ans2 = o.F.S.S;
	}
	reverse(t.begin(), t.end());
	cout << t << ' ';
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}