#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; scanf("%d", &n);
	vector<int> a(n+2);
	for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	int m; scanf("%d", &m);
	while(m--) {
		int x, y; scanf("%d%d", &x, &y);
		a[x-1] += y - 1;
		a[x+1] += a[x] - y;
		a[x] = 0;
	}
	for(int i = 1; i <= n; ++i) printf("%d\n", a[i]);
	return 0;
}