#include <stdio.h>

int n, p[1001], vis[1001];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &p[i]);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) vis[j] = 0;
		int t = i;
		while (!vis[t]) {
			vis[t] = 1;
			t = p[t];
		}
		printf("%d%c", t, " \n"[i == n]);
	}
	return 0;
}