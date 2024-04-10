#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) { while(b) { a %= b; swap(a, b); } return a; }

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int k; scanf("%d", &k);
		int x = 100 - k;
		int g = gcd(k, x);
		k /= g; x /= g;
		printf("%d\n", k + x);
	}
	return 0;
}