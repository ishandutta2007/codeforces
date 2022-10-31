#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios::sync_with_stdio(0);
	int n; cin >> n;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			int j = n / i;
			if (__gcd(i, j) == 1) {
				puts("YES\n2");
				for (int k = 1; k < i; k++) {
					if ((n - 1 - k * j) % i == 0) {
						printf("%d %d\n", k, i);
						printf("%d %d\n", (n - 1 - k * j) / i, j);
						return 0;
					}
				}
			}
		}
	}
	puts("NO");
	return 0;
}