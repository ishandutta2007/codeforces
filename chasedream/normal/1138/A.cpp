#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
int a[N], cnt[N], n, len;
int ans;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		if (a[i] != a[i - 1]) cnt[++len] = 1;
		else cnt[len]++;
	}
	for (int i = 1; i < len; i++)
		ans = max(ans, 2 * min(cnt[i], cnt[i + 1]));
	printf("%d\n", ans);
	return 0;
}