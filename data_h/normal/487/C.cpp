#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;


int n;

int power(int a, int b) {
	if (b == 0) {
		return 1;
	}
	int temp = power(a, b >> 1);
	if (b & 1) {
		return 1LL * temp * temp % n * a % n;
	} else {
		return 1LL * temp * temp % n;
	}
}

int main() {
	scanf("%d", &n);
	bool flag = true;
	for(int i = 2; i < n; i++) {
		if (n % i == 0) {
			flag = false;
			break;
		}
	}
	if (!flag && n != 4) {
		printf("NO\n");
		return 0;
	}

	puts("YES");
	if (n == 4) {
		printf("1\n3\n2\n4\n");
		return 0;
	}
	int now = 1;
	for(int i = 1; i <= n; i++) {
		if (i == n || i == 1) {
			printf("%d\n", i);
		} else {
			printf("%d\n", (int)(1LL * power(now, n - 2) * i % n));
			now = i;
		}
	}
	return 0;
}