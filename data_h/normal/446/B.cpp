#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#include <iostream>
#include <queue>
using namespace std;

const int N = 1111;
const long long INF = (1LL << 60);

int a[N][N];
long long row[N], col[N];
int n, m, k, p;
long long f[N * N], g[N * N];

void solve(int n, long long v[N], long long f[N * N], int m) {
	priority_queue<long long> q;
	for(int i = 1; i <= n; i++) {
		q.push(v[i]);
	}
	f[0] = 0;
	for(int i = 1; i <= k; i++) {
		long long tmp = q.top();
		q.pop();
		f[i] = f[i - 1] + tmp;
		q.push(tmp - m * p);
	}
}
int main() {
	scanf("%d %d %d %d", &n, &m, &k, &p);
	for(int i = 1; i <= n; i++) {
		row[i] = 0;
		for(int j = 1; j <= m; j++) {
			scanf("%d", &a[i][j]);
			row[i] += a[i][j];
		}
	}
	solve(n, row, f, m);
	for(int i = 1; i <= m; i++) {
		col[i] = 0;
		for(int j = 1; j <= n; j++) {
			col[i] += a[j][i];
		}
	}
	solve(m, col, g, n);
	long long ans = -INF;
	for(int i = 0; i <= k; i++) {
		ans = max(ans, f[i] + g[k - i] - 1LL * (k - i) * i * p);
	}
	cout << ans << endl;
	return 0;
}