#include <bits/stdc++.h>

using namespace std;

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		int A, B; scanf("%d%d", &A, &B);
		B = min(B, 2 * A);
		A = min(A, 2 * B);
		printf("%d\n", (A + B) / 3);
	}
	return 0;
}