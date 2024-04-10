#include <bits/stdc++.h>
using namespace std;

int a[7];
int b[7][8];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios::sync_with_stdio(0);
	int ncase;
	for (cin >> ncase; ncase--; ) {
		int n; cin >> n;
		int sum = 0;
		for (int i = 0; i < 7; i++) cin >> a[i], sum += a[i];
		int ans = n * 7;
		for (int i = 0; i < 7; i++) {
			if (a[i] == 0) continue;
			int cnt = 0;
			for (int j = 1; j <= 7; j++) {
				if (a[(i + j - 1) % 7]) {
					cnt++;
					b[i][cnt] = j;
				}
			}
			int now = (n - 1) / sum;
			ans = min(ans, now * 7 + b[i][n - now * sum]);
		}
		printf("%d\n", ans);
	}
	return 0;
}