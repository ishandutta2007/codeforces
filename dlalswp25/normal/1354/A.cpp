#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		ll A, B, C, D; scanf("%lld%lld%lld%lld", &A, &B, &C, &D);
		if(A <= B) {
			printf("%lld\n", B);
			continue;
		}
		if(C <= D) { puts("-1"); continue; }

		ll t = (A - B - 1) / (C - D) + 1;
		printf("%lld\n", B + t * C);
	}
	return 0;
}