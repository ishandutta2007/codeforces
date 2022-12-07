#include<bits/stdc++.h>
using namespace std;
int main() {
	int tests;
	scanf("%d", &tests);
	for(int qq(1); qq <= tests; qq++) {
		int x, y, p, q;
		scanf("%d%d%d%d", &x, &y, &p, &q);
		int d(__gcd(p, q));
		p /= d; q /= d;
		int k((y + q - 1) / q);
		if(p == 0) {
			if(x == 0) {
				printf("0\n");
				continue;
			}else {
				printf("-1\n");
				continue;
			}
		}
		if(p == q) {
			if(x == y) {
				printf("0\n");
				continue;
			}else {
				printf("-1\n");
				continue;
			}
		}
		k = max(k, (x + p - 1) / p);
		k = max(k, (y - x + q - p - 1) / (q - p));
		printf("%lld\n", (long long)k * q - y);
	}
}