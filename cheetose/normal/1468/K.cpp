#include <bits/stdc++.h>

using namespace std;

char s[5005];
void solve() {
	int n;
	scanf("%s", s);
	n = strlen(s);
	int x = 0, y = 0;
	for (int k = 0; k < n; k++) {
		int nx, ny;
		if (s[k] == 'L') {
			nx = x - 1, ny = y;
		}
		else if (s[k] == 'R') {
			nx = x + 1, ny = y;
		}
		else if (s[k] == 'U') {
			nx = x, ny = y + 1;
		}
		else if (s[k] == 'D') {
			nx = x, ny = y - 1;
		}
		int xx = 0, yy = 0;
		int nxx, nyy;
		for (int i = 0; i < n; i++) {
			if (s[i] == 'L') {
				nxx = xx - 1, nyy = yy;
			}
			else if (s[i] == 'R') {
				nxx = xx + 1, nyy = yy;
			}
			else if (s[i] == 'U') {
				nxx = xx, nyy = yy + 1;
			}
			else if (s[i] == 'D') {
				nxx = xx, nyy = yy - 1;
			}
			if (nxx == nx && nyy == ny)continue;
			xx = nxx, yy = nyy;
		}
		if (xx == 0 && yy == 0) {
			printf("%d %d\n", nx, ny);
			return;
		}
		x = nx, y = ny;
	}
	puts("0 0");
}
int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--)solve();
}