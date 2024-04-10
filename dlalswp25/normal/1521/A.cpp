#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		ll A, B; scanf("%lld%lld", &A, &B);
		if(B == 1) { puts("NO"); continue; }
		puts("YES");
		if(B == 2) printf("%lld %lld %lld\n", A, 3 * A, 4 * A);
		else printf("%lld %lld %lld\n", A, A * (B - 1), A * B);
	}
	return 0;
}