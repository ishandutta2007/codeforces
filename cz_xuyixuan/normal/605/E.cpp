#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1005;
const double eps = 1e-15;
const double INF = 1e100;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
template <typename T> void chkmax(T &x, T y) {x = max(x, y); }
template <typename T> void chkmin(T &x, T y) {x = min(x, y); } 
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
int n, m; bool vis[MAXN]; 
double p[MAXN][MAXN], lft[MAXN], sum[MAXN], ans[MAXN];
int main() {
	read(n);
	for (int i = 1; i <= n - 1; i++)
		ans[i] = INF, sum[i] = 1, lft[i] = 1;
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= n; j++) {
		int x; read(x);
		p[i][j] = 0.01 * x;
	}
	for (int t = 1; t <= n; t++) {
		int pos = 0;
		for (int i = 1; i <= n; i++)
			if (!vis[i] && (pos == 0 || ans[i] < ans[pos])) pos = i;
		vis[pos] = true;
		for (int i = 1; i <= n; i++)
			if (!vis[i]) {
				sum[i] += lft[i] * p[i][pos] * ans[pos];
				lft[i] *= (1 - p[i][pos]);
				double tres = INF;
				if (1 - lft[i] > eps) tres = sum[i] / (1 - lft[i]);
				chkmin(ans[i], tres);
			}
	}
	printf("%.10lf\n", ans[1]);
	return 0;
}