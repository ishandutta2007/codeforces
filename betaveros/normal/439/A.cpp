#include <cstdio>
using namespace std;

int n, d;
int main() {
	scanf("%d%d", &n, &d);
	int ttl = 0;
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		ttl += x;
	}
	int res = (d - ttl) / 5;
	if (d >= ttl && res >= 2*(n - 1)) {
		printf("%d\n", res);
	} else {
		printf("-1\n");
	}
}