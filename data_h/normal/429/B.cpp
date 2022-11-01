#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int N = 1111;

long long ans = 0;
long long f[4][N][N];
int n, m, a[N][N];

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++)
			scanf("%d", &a[i][j]);
	}
	
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++) {
			f[0][i][j] = max(f[0][i][j - 1], f[0][i - 1][j]) + a[i][j];
		}
	for(int i = n; i >= 1; i--)
		for(int j = 1; j <= m; j++) {
			f[1][i][j] = max(f[1][i + 1][j], f[1][i][j - 1]) + a[i][j];
		}
	for(int i = 1; i <= n; i++)	
		for(int j = m; j >= 1; j--) {
			f[2][i][j] = max(f[2][i - 1][j], f[2][i][j + 1]) + a[i][j];
		}
	for(int i = n; i >= 1; i--)
		for(int j = m; j >= 1; j--) {
			f[3][i][j] = max(f[3][i + 1][j], f[3][i][j + 1]) + a[i][j];
		}
	for(int i = 2; i < n; i++)
		for(int j = 2; j < m; j++) {
			ans = max(ans, f[0][i][j - 1] + f[1][i + 1][j] + f[2][i - 1][j] + f[3][i][j + 1]);
			ans = max(ans, f[0][i - 1][j] + f[1][i][j - 1] + f[2][i][j + 1] + f[3][i + 1][j]);
		}
	printf("%I64d\n", ans);
		
	return 0;
}