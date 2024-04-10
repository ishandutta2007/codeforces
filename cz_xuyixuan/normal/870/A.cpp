#include<bits/stdc++.h>
using namespace std;
#define MAXN	15
int a[MAXN], b[MAXN], c[MAXN];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		c[a[i]]++;
	}
	for (int i = 1; i <= m; i++) {
		cin >> b[i];
		c[b[i]]++;
	}
	for (int i = 1; i <= 9; i++)
		if (c[i] >= 2) {
			printf("%d\n", i);
			return 0;
		}
	sort(a + 1, a + n + 1);
	sort(b + 1, b + m + 1);
	printf("%d%d\n", min(a[1], b[1]), max(a[1], b[1]));
	return 0;
}