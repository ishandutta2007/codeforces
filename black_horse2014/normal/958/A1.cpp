#include <bits/stdc++.h>
using namespace std;

char s[22][22], t[22][22];
int n;

int ro(int i, int j, int k) {
	if (k == 0) return s[i][j];
	if (k == 1) return s[n + 1 - i][j];
	if (k == 2) return s[i][n + 1 - j];
	if (k == 3) return s[j][n + 1 - i];
	if (k == 4) return s[n + 1 - i][n + 1 - j];
	if (k == 5) return s[n + 1 - j][i];
}

int ro1(int i, int j, int k) {
	if (k == 0) return t[i][j];
	if (k == 1) return t[n + 1 - i][j];
	if (k == 2) return t[i][n + 1 - j];
	if (k == 3) return t[j][n + 1 - i];
	if (k == 4) return t[n + 1 - i][n + 1 - j];
	if (k == 5) return t[n + 1 - j][i];
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
	for (int i = 1; i <= n; i++) scanf("%s", t[i] + 1);
	bool ans = false;
	for (int k1 = 0; k1 < 6; k1++)
		for (int k2 = 0; k2 < 6; k2++) {
			bool can = true;
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= n; j++) can &= (ro(i, j, k1) == ro1(i, j, k2));
				ans |= can;
		}
	printf("%s\n", ans ? "Yes" : "No");
	return 0;
}