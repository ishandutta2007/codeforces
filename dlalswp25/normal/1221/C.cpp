#include <bits/stdc++.h>

using namespace std;

int main() {
	int Q; scanf("%d", &Q);
	while(Q--) {
		int c, d, x; scanf("%d%d%d", &c, &d, &x);
		printf("%d\n", min(min(c, d), (c + d + x) / 3));
	}
	return 0;
}