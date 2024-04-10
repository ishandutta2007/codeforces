#include<bits/stdc++.h>
using namespace std;

const int maxn = 4009;
int f[maxn][maxn], NextA[maxn][26], NextB[maxn][26];
int n, m, ti, td, tr, te;
char a[maxn], b[maxn];

void update(int &a, int b) {
	if (b < a) a = b;
}

int main() {
	scanf("%d%d%d%d", &ti, &td, &tr, &te);
	scanf("%s%s", a + 1, b + 1);
	n = strlen(a + 1); m = strlen(b + 1);
	for (int i=0; i<=25; i++) {
		NextA[n+2][i] = n+2;
		NextB[m+2][i] = m+2;
	}
	for (int i=n+1; i>=1; i--) {
		for (int j=0; j<=25; j++)
			NextA[i][j] = NextA[i+1][j];
		if (i <= n) NextA[i][a[i]-'a'] = i;
	}
	for (int i=m+1; i>=1; i--) {
		for (int j=0; j<=25; j++)
			NextB[i][j] = NextB[i+1][j];
		if (i <= m) NextB[i][b[i]-'a'] = i;
	}
	memset(f, 0x3f, sizeof f); f[0][0] = 0;
	for (int i=0; i<=n; i++) 
		for (int j=0; j<=m; j++) {
			if (a[i+1] == b[j+1]) update(f[i+1][j+1], f[i][j]);
			update(f[i+1][j], f[i][j] + td);
			update(f[i][j+1], f[i][j] + ti);
			update(f[i+1][j+1], f[i][j] + tr);
			if (NextA[i+2][b[j+1]-'a'] <= n && NextB[j+2][a[i+1]-'a'] <= m)
				update(f[NextA[i+2][b[j+1]-'a']][NextB[j+2][a[i+1]-'a']], 
				f[i][j] + te + td * (NextA[i+2][b[j+1]-'a'] - i - 2) + ti * (NextB[j+2][a[i+1]-'a'] - j - 2));
		}
	printf("%d\n", f[n][m]);
	return 0;
}