#include <bits/stdc++.h>

using namespace std;

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		int a, b, n; scanf("%d%d%d", &a, &b, &n);
		n %= 3;
		if(n == 0) printf("%d\n", a);
		else if(n == 1) printf("%d\n", b);
		else printf("%d\n", a ^ b);
	}
	return 0;
}