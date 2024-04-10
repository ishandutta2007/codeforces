#include <bits/stdc++.h>
using namespace std;

const int N = 1100;

int deg[N];

int main() {
	int n; scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int u, v; scanf("%d%d", &u, &v);
		deg[u]++, deg[v]++;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) if (deg[i] == 1) ans++;
	printf("%d\n", ans);
	return 0;
}