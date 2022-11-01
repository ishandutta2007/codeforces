#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 2e5 + 7;

int p[N], vis[N], b[N];
int n;

int main() {
	scanf("%d", &n);
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &p[i]);
	}
	for (int i = 1; i <= n; i++) {
		if (vis[i]) continue;
		int x = i;
		cnt++;
		while (!vis[x]) {
			vis[x] = 1;
			x = p[x];
		}
	}
	int tot_b = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &b[i]);
		tot_b ^= b[i];
	}
	printf("%d\n", (cnt > 1 ? cnt : 0) + (tot_b == 0));
	return 0;
}