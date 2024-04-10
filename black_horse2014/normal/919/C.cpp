#include <bits/stdc++.h>
using namespace std;

char s[2200][2200];

int main() {
	int n, m, c; cin >> n >> m >> c;
	for (int i = 0; i < n; i++) scanf("%s", s[i]);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0, k; j < m; j = k) {
			for (k = j; k < m && s[i][j] == s[i][k]; k++);
			if (s[i][j] == '.') {
				if (k - j >= c) ans += k - j - c + 1;
			}
		}
	}
	if (c > 1) {
		for (int i = 0; i < m; i++) {
			for (int j = 0, k; j < n; j = k) {
				for (k = j; k < n && s[j][i] == s[k][i]; k++);
				if (s[j][i] == '.') {
					if (k - j >= c) ans += k - j - c + 1;
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}