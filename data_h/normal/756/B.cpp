#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 2e5 + 7;
const int INF = 1e9 + 7;

int n;
int t[N], f[N];

int main() {
	scanf("%d", &n);
	f[0] = 0;
	t[0] = -INF;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &t[i]);
		f[i] = f[i - 1] + 20;
		int p0 = lower_bound(t, t + i, t[i] - 90 + 1) - t;
		f[i] = min(f[i], f[p0 - 1] + 50);
		int p1 = lower_bound(t, t + i, t[i] - 1440 + 1) - t;
		f[i] = min(f[i], f[p1 - 1] + 120);
		printf("%d\n", f[i] - f[i - 1]);
	}
	return 0;
}