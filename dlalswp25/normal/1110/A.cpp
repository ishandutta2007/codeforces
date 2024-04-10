#include <bits/stdc++.h>

using namespace std;

int main() {
	int b, n; scanf("%d%d", &b, &n);
	int a = 0;
	for(int i = 1; i < n; i++) {
		int x; scanf("%d", &x);
		a = (a + b * x) % 2;
	}
	int x; scanf("%d", &x);
	a = (a + x) % 2;
	puts((a & 1) ? "odd" : "even");
	return 0;
}