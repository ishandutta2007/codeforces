#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		ll N; scanf("%lld", &N);
		while(~N & 1) N >>= 1;
		puts(N > 1 ? "YES" : "NO");
	}
	return 0;
}