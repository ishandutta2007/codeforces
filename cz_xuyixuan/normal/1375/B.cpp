#include<bits/stdc++.h>
using namespace std;
const int MAXN = 305;
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};
typedef long long ll;
template <typename T> void chkmax(T &x, T y) {x = max(x, y); }
template <typename T> void chkmin(T &x, T y) {x = min(x, y); } 
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
int n, m, a[MAXN][MAXN], d[MAXN][MAXN];
int main() {
	int T; read(T);
	while (T--) {
		read(n), read(m);
		for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			read(a[i][j]), d[i][j] = 0;
		for (int i = 1; i <= n - 1; i++)
		for (int j = 1; j <= m; j++)
			d[i][j]++, d[i + 1][j]++;
		for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m - 1; j++)
			d[i][j]++, d[i][j + 1]++;
		bool ans = true;
		for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (a[i][j] > d[i][j]) ans = false;
		if (ans) {
			puts("YES");
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= m; j++)
					printf("%d ", d[i][j]);
				printf("\n");
			}
		} else puts("NO");
	}
	return 0;
}