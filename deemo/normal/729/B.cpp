#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e3 + 5;

int n, m, a[MAXN][MAXN], ans, p[MAXN][MAXN];

int main(){
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &a[i][j]), p[i + 1][j + 1] = p[i + 1][j] + p[i][j + 1] - p[i][j] + a[i][j];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (!a[i][j]){
				ans += bool(p[i + 1][j + 1] - p[i][j + 1]);
				ans += bool(p[i + 1][m] - p[i][m] -(p[i + 1][j + 1] - p[i][j + 1]));
				ans += bool(p[i + 1][j + 1] - p[i + 1][j]);
				ans += bool(p[n][j + 1] - p[n][j] -(p[i + 1][j + 1] - p[i + 1][j]));
			}

	printf("%d\n", ans);
	return 0;
}