#include <bits/stdc++.h>
using namespace std;
int n, w, a[200010];
int main() {
	scanf("%d%d", &n, &w);
	for(int i = 0; i < 2 * n; ++i)
		scanf("%d", &a[i]);
	sort(a, a + 2 * n);
	printf("%f\n", min((double)w, min(a[0] / 1.0, a[n] / 2.0) * 3 * n));
	return 0;
}