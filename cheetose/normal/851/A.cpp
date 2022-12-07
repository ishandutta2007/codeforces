#include<cstdio>
int main() {
	int n, k, t;
	scanf("%d%d%d", &n, &k, &t);
	if (t <= k) printf("%d", t);
	else if (t > n) printf("%d", n + k - t);
	else printf("%d", k);
}