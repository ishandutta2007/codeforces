#include <bits/stdc++.h>
using namespace std;

int cnt[1100];
int a[22][22];

int main() {
	int n; cin >> n;
	for (int i = 0; i < n*n; i++) {
		int x; cin >> x; cnt[x]++;
	}
	if (~n & 1) {
		for (int i = 1; i <= 1000; i++) if (cnt[i] % 4 != 0) return puts("NO"), 0;
		int cur = 1;
		for (int i = 1; i <= n/2; i++) {
			for (int j = 1; j <= n/2; j++) {
				while (!cnt[cur]) cur++;
				a[i][j] = cur;
				a[i][n+1-j] = cur;
				a[n+1-i][n+1-j] = cur;
				a[n+1-i][j] = cur;
				cnt[cur] -= 4;
			}
		}
	} else {
		int c0 = 0, c1 = 0;
		for (int i = 1; i <= 1000; i++) {
			if (cnt[i] & 1) c0++;
			if (cnt[i] % 4 >= 2) c1++;
		}
		if (c0 > 1 || c1 > n/2*2) return puts("NO"), 0;
		for (int i = 1; i <= 1000; i++) {
			if (cnt[i] & 1) {
				a[n/2+1][n/2+1] = i;
				cnt[i]--;
			}
		}
		int r = 1, c = 1;
		for (int i = 1; i <= 1000; i++) {
			if (cnt[i] % 4 == 2) {
				if (r <= n/2) {
					a[r][n/2+1] = a[n+1-r][n/2+1] = i;
					cnt[i] -= 2;
					r++;
				} else {
					a[n/2+1][c] = a[n/2+1][n+1-c] = i;
					cnt[i] -= 2;
					c++;
				}
			}
		}
		for (int i = 1; i <= 1000; i++) {
			while (cnt[i] && (r <= n/2 || c <= n/2)) {
				if (r <= n/2) {
					a[r][n/2+1] = a[n+1-r][n/2+1] = i;
					cnt[i] -= 2;
					r++;
				} else {
					a[n/2+1][c] = a[n/2+1][n+1-c] = i;
					cnt[i] -= 2;
					c++;
				}
			}
		}
		int cur = 1;
		for (int i = 1; i <= n/2; i++) {
			for (int j = 1; j <= n/2; j++) {
				while (!cnt[cur]) cur++;
				a[i][j] = cur;
				a[i][n+1-j] = cur;
				a[n+1-i][n+1-j] = cur;
				a[n+1-i][j] = cur;
				cnt[cur] -= 4;
			}
		}
	}
	puts("YES");
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) printf("%d%c", a[i][j], j < n ? ' ' : '\n');
	}
	return 0;
}