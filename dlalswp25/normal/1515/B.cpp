#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int N; scanf("%d", &N);
		if(N & 1) { puts("NO"); continue; }
		N /= 2;
		ll l = 1, r = 1000000000;
		while(l <= r) {
			ll m = l + r >> 1;
			if(m * m > N) r = m - 1;
			else l = m + 1;
		}
		if(r * r == N) { puts("YES"); continue; }
		if(N & 1) { puts("NO"); continue; }
		N /= 2;
		l = 1, r = 1000000000;
		while(l <= r) {
			ll m = l + r >> 1;
			if(m * m > N) r = m - 1;
			else l = m + 1;
		}
		if(r * r == N) { puts("YES"); continue; }
		puts("NO");
	}
	return 0;
}