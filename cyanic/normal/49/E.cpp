#include<bits/stdc++.h>
using namespace std;

const int maxn = 55;
char a[maxn], b[maxn], c[maxn], s1[maxn], s2[maxn];
int g1[maxn][maxn][26], g2[maxn][maxn][26], f[maxn][maxn];
int n, m, K;

void solve(char s[], int g[maxn][maxn][26]) {
	int n = strlen(s + 1);
	for (int i=1; i<=n; i++)
		g[i][i][s[i]-'a'] = 1;
	for (int l=n; l>=1; l--)
		for (int r=l+1; r<=n; r++) 
			for (int k=l; k<=r-1; k++)
				for (int i=1; i<=K; i++)
					g[l][r][a[i]] |= g[l][k][b[i]] & g[k+1][r][c[i]];
}

int main() {
	scanf("%s%s%d", s1+1, s2+1, &K);
	n = strlen(s1+1); m = strlen(s2+1);
	for (int i=1; i<=K; i++) {
		scanf("\n%c->%c%c", &a[i], &b[i], &c[i]);
		a[i] -= 'a'; b[i] -= 'a'; c[i] -= 'a';
	}
	solve(s1, g1); solve(s2, g2);
	memset(f, 0x3f, sizeof f); f[0][0] = 0;
	for (int i=0; i<=n; i++)
		for (int j=0; j<=m; j++) {
			for (int a=i+1; a<=n; a++)
				for (int b=j+1; b<=m; b++)
					for (int k=0; k<=25; k++)
						if (g1[i+1][a][k] && g2[j+1][b][k])
							f[a][b] = min(f[a][b], f[i][j] + 1);
		}
	if (f[n][m] < 1e9) printf("%d\n", f[n][m]);
	else puts("-1");
	return 0;
}