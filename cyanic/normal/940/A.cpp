#include<bits/stdc++.h>
using namespace std;

const int maxn = 105;
int x[maxn], n, d, ans = maxn, r;

int main() {
	scanf("%d%d", &n, &d);
	for (int i=1; i<=n; i++) scanf("%d", &x[i]);
	sort(x+1, x+n+1);
	for (int i=1; i<=n; i++) {
		r = i;
		while (r < n && x[r+1] - x[i] <= d) r++;
		ans = min(ans, n - (r - i + 1));
	}
	printf("%d\n", ans);
	return 0;
}