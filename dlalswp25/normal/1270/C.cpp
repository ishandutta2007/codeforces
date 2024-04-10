#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		ll A = 0, B = 0;
		int N; scanf("%d", &N);
		for(int i = 1; i <= N; i++) {
			int x; scanf("%d", &x);
			A += x; B ^= x;
		}

		int al = (A & 1), bl = 0;
		ll ans = 0;
		for(int i = 0; i < 50; i++) {
			ll t = 0;
			if(al != bl) {
				t = (1LL << i);
				ans += t;
				A += t; B ^= t;
			}
			al = ((A & (1LL << (i + 1))) > 0);
			bl = ((B & (1LL << i)) > 0);

		}
		printf("1\n%lld\n", ans);
	}

	return 0;
}