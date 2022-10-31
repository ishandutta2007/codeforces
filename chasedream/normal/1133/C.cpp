#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
int a[N], n, ans;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	
	int head = 1;
	for (int i = 1; i <= n; i++) {
		while (a[i] - a[head] > 5) head++;
		ans = max(ans, i - head + 1);
	}
	printf("%d\n", ans);
	return 0;
}