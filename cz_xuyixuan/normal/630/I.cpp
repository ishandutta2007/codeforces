#include<bits/stdc++.h>
using namespace std;
#define MAXN	5005
int main() {
	ios::sync_with_stdio(false);
	long long n, m, ans = 0;
	cin >> n; m = 2 * n - 2;
	for (int i = n; i <= m; i++) {
		int cnt = m - n;
		long long now = 4;
		if (i != n) {
			now *= 3;
			cnt--;
		}
		if (i != m) {
			now *= 3;
			cnt--;
		}
		for (int j = 1; j <= cnt; j++)
			now *= 4;
		ans += now;
	}
	cout << ans << endl;
	return 0;
}