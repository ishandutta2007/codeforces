#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N, M;
char A[202020];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		scanf("%s", A + 1);
		M = strlen(A + 1);

		ll ans = 0;
		int x = 1, y = 1;
		int i = 1;
		for(; i <= M; i++) {
			if(A[i] != A[1]) break;
			ans++;
			if(A[i] == 'D') x++;
			else y++;
		}
		if(i > M) {
			printf("%d\n", N); continue;
		}

		ans += (ll)(N - x + 1) * (N - y + 1);
		int tx = x, ty = y, ti = i;
		for(; i <= M; i++) {
			if(A[i] == 'D') x++;
			else y++;
		}
		swap(tx, x); swap(ty, y); swap(ti, i);

		for(; i <= M; i++) {
			if(A[i] == 'D') {
				ans -= ty - y;
				x++;
			}
			else {
				ans -= tx - x;
				y++;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}