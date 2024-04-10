#include <bits/stdc++.h>

using namespace std;

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		int A, B; scanf("%d%d", &A, &B);
		B++;
		int ans = -1;
		while(B) {
			ans++; B /= 10;
		}
		printf("%lld\n", (long long)A * ans);
	}
	return 0;
}