#include <bits/stdc++.h>

using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int a, b, c, m; scanf("%d%d%d%d", &a, &b, &c, &m);
		int mn = max({0, a - b - c - 1, b - c - a - 1, c - a - b - 1});
		int mx = a + b + c - 3;
		puts(mn <= m && m <= mx ? "YES" : "NO");
	}
	return 0;
}