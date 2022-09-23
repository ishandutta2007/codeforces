#include <bits/stdc++.h>

using namespace std;

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		int a, b, c; scanf("%d%d%d", &a, &b, &c);
		int t = min(b, c / 2);
		b -= t; c -= 2 * t;
		printf("%d\n", 3 * (t + min(a, b / 2)));
	}
	return 0;
}