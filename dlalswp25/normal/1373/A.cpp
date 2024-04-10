#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		ll a, b, c;
		scanf("%lld%lld%lld", &a, &b, &c);
		if(a < c) {
			if(a * b > c) printf("%d %d\n", 1, b);
			else printf("1 -1\n");
		}
		else {
			printf("-1 %d\n", b);
		}
	}
	return 0;
}