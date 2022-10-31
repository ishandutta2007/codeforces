#include <bits/stdc++.h>
using namespace std;

int n, k, p;

const int inf = 1e8;

inline void chkmin(int &a, int b) {
	if (a > b) a = b;
}

int d[110][110], all[110], b[110];
int a[510000];

void update(int id, int u, int x) {
	for (u++; u <= p; u += u & -u) chkmin(d[id][u], x);
}

int query(int id, int u) {
	int ret = inf;
	for (u++; u; u -= u & -u) chkmin(ret, d[id][u]);
	return ret;
}

int main() {
	scanf("%d%d%d", &n, &k, &p);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]), a[i] %= p, a[i] = (a[i-1] + a[i]) % p;
	for (int j = 1; j <= k; j++) for (int i = 0; i <= p; i++) d[j][i] = inf;
	for (int j = 1; j <= k; j++) all[j] = inf;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i && j <= k; j++) b[j] = min(all[j-1] + p, query(j-1, a[i]));
		for (int j = 1; j <= i && j <= k; j++) {
			update(j, a[i], b[j]);
			all[j] = min(all[j], b[j]);
		}
	}
	cout << b[k] + a[n] << endl;
	return 0;
}