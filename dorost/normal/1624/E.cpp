/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 1012, M = 11;
bool dp[N];
int p[N];
string s[N];
pair <pair <int, int>, int> a[2][M * M * M];

void solve() {
	int n, m;
	string t;
	cin >> n >> m;
	for (int i = 0; i < M * M * M; i++) {
		a[0][i].F.F = 0;
		a[0][i].F.S = 0;
		a[0][i].S = 0;
		a[1][i].F.F = 0;
		a[1][i].F.S = 0;
		a[1][i].S = 0;
	}
	for (int i = 0; i < N; i++) {
		dp[i] = false;
		p[i] = -1;
		s[i] = "";
	}
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		for (int j = 0; j < m - 1; j++) {
			a[0][(s[i][j] - '0') * 10 + (s[i][j + 1] - '0')] = make_pair(make_pair(j + 1, j + 2), i + 1);
		}
		for (int j = 0; j < m - 2; j++) {
			a[1][(s[i][j] - '0') * 10 * 10 + (s[i][j + 1] - '0') * 10 + (s[i][j + 2] - '0')] = make_pair(make_pair(j + 1, j + 3), i + 1);
		}
	}
	cin >> t;
	dp[0] = true;
	dp[1] = false;
	for (int i = 2; i <= m; i++) {
		if (a[0][((t[i - 1] - '0') + (t[i - 2] - '0') * 10)].S != 0 && dp[i - 2]) {
			dp[i] = true;
			p[i] = i - 2;
		}
		if (i > 2) {
			if (a[1][((t[i - 1] - '0') + (t[i - 2] - '0') * 10) + (t[i - 3] - '0') * 10 * 10].S != 0 && dp[i - 3])  {
				dp[i] = true;
				p[i] = i - 3;
			}
		}
	}
	if (!dp[m]) {
		cout << -1 << '\n';
		return;
	}
	vector <pair <pair <int, int>, int>> v;
	int i = m;
	while (p[i] != -1) {
		if (i - p[i] == 2) {
			v.push_back(a[0][((t[i - 1] - '0') + (t[i - 2] - '0') * 10)]);
		} else {
			v.push_back(a[1][((t[i - 1] - '0') + (t[i - 2] - '0') * 10) + (t[i - 3] - '0') * 10 * 10]);
		}
		i = p[i];
	}
	reverse(v.begin(), v.end());
	cout << v.size() << '\n';
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].F.F << ' ' << v[i].F.S << ' ' << v[i].S << '\n';
		assert(v[i].S != 0);
	}
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