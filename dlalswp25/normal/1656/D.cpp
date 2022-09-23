#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		ll N; scanf("%lld", &N); N <<= 1;
		ll a = 1;
		while(N % 2 == 0) {
			a <<= 1; N >>= 1;
		}
		if(a > N) swap(a, N);
		if(a == 1) puts("-1");
		else printf("%lld\n", a);
	}
	return 0;
}