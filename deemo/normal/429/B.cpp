#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

const int max_n = 1e3 + 10;

int n, m;
int a[max_n][max_n];
int d1[max_n][max_n];
int d2[max_n][max_n];
int d3[max_n][max_n];
int d4[max_n][max_n];

int main(){
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &a[i][j]);

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			d1[i][j] = max(d1[i - 1][j], d1[i][j - 1]) + a[i][j];
	for (int i = n; i > 0; i--)
		for (int j = 1; j <= m; j++)
			d2[i][j] = max(d2[i + 1][j], d2[i][j - 1]) + a[i][j];
	for (int i = 1; i <= n; i++)
		for (int j = m; j > 0; j--)
			d3[i][j] = max(d3[i - 1][j], d3[i][j + 1]) + a[i][j];
	for (int i = n; i > 0; i--)
		for (int j = m; j > 0; j--)
			d4[i][j] = max(d4[i + 1][j], d4[i][j + 1]) + a[i][j];

	int ans = 0;
	for (int i = 2; i < n; i++)
		for (int j = 2; j < m; j++){
			ans = max(ans, d1[i][j - 1] + d2[i + 1][j] + d3[i - 1][j] + d4[i][j + 1]);
			ans = max(ans, d1[i - 1][j] + d2[i][j - 1] + d3[i][j + 1] + d4[i + 1][j]);
		}
	printf("%d\n", ans);
	return 0;
}