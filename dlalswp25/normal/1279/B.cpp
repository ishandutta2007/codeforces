#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll A[101010];

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		int N; ll s; scanf("%d%lld", &N, &s);
		for(int i = 1; i <= N; i++) scanf("%lld", &A[i]);

		ll sum = 0, mx = 0, mxi, i;
		int ans = 0;
		for(i = 1; i <= N; i++) {
			sum += A[i];
			if(mx < A[i]) { mx = A[i]; mxi = i; }
			if(sum > s) break;
		}
		if(i > N) { puts("0"); continue; }
		if(sum - mx <= s) printf("%d\n", mxi);
		else puts("0");
	}
}