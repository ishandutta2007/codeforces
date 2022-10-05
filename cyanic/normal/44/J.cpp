#include<bits/stdc++.h>
using namespace std;

const int maxn = 1009;
int ans[maxn][maxn], vis[10], n, m, now;
char s[maxn][maxn];

int main() {
	scanf("%d%d", &n, &m);
	for (int i=1; i<=n; i++) scanf("%s", s[i]+1);
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++)
			if (s[i][j] != '.' && !ans[i][j]) {
				// printf("%d %d\n", i, j);
				if (s[i][j] == 'b') { puts("NO"); return 0; }
				if (j+2 <= m && !ans[i][j+1] && s[i][j+1] == 'b' && !ans[i][j+2] && s[i][j+2] == 'w') {
					memset(vis, 0, sizeof vis);
					vis[ans[i][j-1]] = 1; vis[ans[i-1][j]] = 1;
					vis[ans[i-1][j+1]] = 1; vis[ans[i-1][j+2]] = 1;
					vis[ans[i][j+3]] = 1;
					now = 1; while (vis[now]) now++;
					ans[i][j] = now; ans[i][j+1] = now; ans[i][j+2] = now;
				}
				else if (i+2 <= n && !ans[i+1][j] && s[i+1][j] == 'b' && !ans[i+2][j] && s[i+2][j] == 'w') {
					memset(vis, 0, sizeof vis);
					vis[ans[i-1][j]] = 1; vis[ans[i][j-1]] = 1;
					vis[ans[i+1][j-1]] = 1; vis[ans[i+2][j-1]] = 1;
					vis[ans[i][j+1]] = 1; vis[ans[i][j+2]] = 1;
					now = 1; while (vis[now]) now++;
					ans[i][j] = now; ans[i+1][j] = now; ans[i+2][j] = now;
				}
				else { puts("NO"); return 0; }
			}
	puts("YES");
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++)
			if (!ans[i][j]) putchar('.');
			else putchar('a'+ans[i][j]-1);
		puts("");
	}
	return 0;
}