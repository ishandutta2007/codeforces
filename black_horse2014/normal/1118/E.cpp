#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k; cin >> n >> k;
	if (n > k * 1LL * (k - 1)) return puts("NO"), 0;
	puts("YES");
	int a = 1, b = 2;
	while (n > 0) {
		printf("%d %d\n", a, b);
		n--;
		if (n > 0) {
			printf("%d %d\n", b, a);
			n--;
		}
		b++;
		if (b > k) a++, b = a + 1;
	}
	return 0;
}