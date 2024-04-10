/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 502;
string s[N];
int nx[N][N], l[N][N];

void solve() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> s[i];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (s[i][j] != '*')
				l[i][j] = 0;
			if (j == 0)
				l[i][j] = (s[i][j] == '*');
			else {
				if (s[i][j - 1] == '*')
					l[i][j] = l[i][j - 1] + 1;
				else
					l[i][j] = 1;
			}
		}
	}
	for (int i = n - 1; i >= 0; i--) {
		for (int j = m - 1; j >= 0; j--) {
			if (s[i][j] != '*')
				nx[i][j] = 0;
			else if (j == m - 1)
				nx[i][j] = (s[i][j] == '*');
			else {
				if (s[i][j + 1] == '*')
					nx[i][j] = nx[i][j + 1] + 1;
				else
					nx[i][j] = 1;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int x = 0;
			for (int k = 0; k < n - i; k++) {
				if (nx[i + k][j] >= k + 1 && l[i + k][j] >= k + 1) {
					x++;
				} else {
					break;
				}
			}
			ans += x;
		}
	}
	cout << ans << '\n';
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}