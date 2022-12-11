#include <stdio.h>

int n, x, k, vis[110], ans;
int main() {
	scanf("%d%d", &n, &x);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &k);
		if (k < x) vis[k] = 1;
		if (k == x) ans++;
	}
	for (int i = 0; i < x; i++)
		if (!vis[i]) ans++;
	printf("%d\n", ans);
	return 0;
}