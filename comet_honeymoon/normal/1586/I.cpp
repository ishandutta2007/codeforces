#include<bits/stdc++.h>
using namespace std;
 
int n;
int s[1005];
char ans[2005][2005];
 
void check(int i, int x, int y, int d) {
	if (ans[x][y] == '.') return;
	int c = (ans[x][y] == 'S') ^ d;
	// printf("%d %d %d : %d\n", x, y, i, c);
	if (s[i] == -1) s[i] = c;
	else if (s[i] != c) { printf("NONE\n"); exit(0); }
}
 
int main() {
	srand(time(NULL));
	scanf("%d", &n);
	if (n & 1) { printf("NONE\n"); return 0; }
	n /= 2;
	for (int i = 1; i <= n; i++) s[i] = -1;
	for (int i = 1; i <= n + n; i++)
		scanf("%s", ans[i] + 1);
 
	for (int i = 1; i <= n; i++) {
		for (int x = 1, d = 0; 2 * (n - i + 1) - x >= 1; x++, d ^= 1)
			check(i, x, 2 * (n - i + 1) - x, d);
		for (int x = 2 * i, d = 0; x <= n + n; x++, d ^= 1)
			check(i, x, 2 * (n + i) - x, d);
		for (int x = 1, d = 0; x + 2 * (n - i) + 1 <= n + n; x++, d ^= 1)
			check(i, x, x + 2 * (n - i) + 1, d);
		for (int x = 2 * (n - i + 1), d = 0; x <= n + n; x++, d ^= 1)
			check(i, x, x - 2 * (n - i) - 1, d);
	}
 
	for (int i = 1; i <= n; i++) if (s[i] == -1) { printf("MULTIPLE\n"); return 0; }
	for (int i = 1; i <= n; i++) {
		for (int x = 1, d = 0; 2 * (n - i + 1) - x >= 1; x++, d ^= 1)
			ans[x][2 * (n - i + 1) - x] = s[i] ^ d;
		for (int x = 2 * i, d = 0; x <= n + n; x++, d ^= 1)
			ans[x][2 * (n + i) - x] = s[i] ^ d;
		for (int x = 1, d = 0; x + 2 * (n - i) + 1 <= n + n; x++, d ^= 1)
			ans[x][x + 2 * (n - i) + 1] = s[i] ^ d;
		for (int x = 2 * (n - i + 1), d = 0; x <= n + n; x++, d ^= 1)
			ans[x][x - 2 * (n - i) - 1] = s[i] ^ d;
	}
 
	printf("UNIQUE\n");
	for (int i = 1; i <= n + n; i++) {
		for (int j = 1; j <= n + n; j++)
			printf("%c", ans[i][j] ? 'S' : 'G');
		printf("\n");
	}
}