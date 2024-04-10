#include <bits/stdc++.h>

using namespace std;

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		int a, b; scanf("%d%d", &a, &b);
		if(a < b) swap(a, b);
		int x = max(2 * b, a);
		printf("%d\n", x * x);
	}
	return 0;
}