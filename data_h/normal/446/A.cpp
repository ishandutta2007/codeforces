#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 111111;

int f[N], g[N], a[N], n;
int ans = 0;
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		f[i] = 1;
		if (i > 1 && a[i] > a[i - 1])
			f[i] = f[i - 1] + 1;
	}
	for(int i = n; i >= 1; i--) {
		g[i] = 1;
		if (i < n && a[i + 1] > a[i])
			g[i] = g[i + 1] + 1;
	}
	for(int i = 1; i <= n; i++) {
		ans = max(ans, g[i]);
		ans = max(ans, f[i]);
		if (i > 1 && i < n && a[i + 1] - 1 > a[i - 1]) {
			ans = max(ans, f[i - 1] + g[i + 1] + 1);
		}
		if (i > 1) {
			ans = max(ans, f[i - 1] + 1);
		}
		if (i < n) {
			ans = max(ans, g[i + 1] + 1);
		}
	}
	printf("%d\n", ans);
	return 0;
}