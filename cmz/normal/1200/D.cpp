#include <bits/stdc++.h>
#define P() (n - k + 1)
using namespace std;
const int N = 2e3 + 10;
int a[N][N], b[N][N], c1[N][N], d[N][N], e[N][N], f[N][N], g[N][N];
inline void work(int i, int j) {
	b[i][j] = b[i][j - 1] + a[i][j], c1[i][j] = c1[i - 1][j] + a[i][j];
}
inline int max(int x,int y){
	if (x>y) return x; else return y;
}
int main() {
	int ans = 0,  tmp = 0;
	int n,k;
	cin >> n >> k;
	char c;
	int aa,bb;
	aa=rand(),bb=rand();
	if (n == k) return printf("%d\n", n * 2), 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			cin >> c;
			a[i][j]=(c=='W');
		}
	int cc,dd;
	cc=rand(),dd=rand();
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) work(i, j);
	for (int i = 1; i <= n; i++)
		ans += (b[i][n] == n) + (c1[n][i] == n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= P(); j++)
			if (b[i][n] == n) d[i][j] = 0;
			else if (b[i][j - 1] + b[i][n] - b[i][j + k - 1] == n - k) d[i][j] = 1;
	for (int i = 1; i <= P(); i++)
		for (int j = 1; j <= n; j++)
			if (c1[n][j] == n)
				d[i][j] = 0;
			else if (c1[i - 1][j] + c1[n][j] - c1[i + k - 1][j] == n - k)
				e[i][j] = 1;
				
		int ee,ff;
		ee=rand(),ff=rand();		
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		
			f[i][j] = f[i][j - 1] + e[i][j], g[i][j] = g[i - 1][j] + d[i][j];
	for (int i = 1; i <= P(); i++)
		for (int j = 1; j <= P(); j++)
			tmp = max(tmp, f[i][j + k - 1] - f[i][j - 1] + g[i + k - 1][j] - g[i - 1][j]);
	printf("%d\n", ans + tmp);
	return 0;
}