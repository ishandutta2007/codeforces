#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll A[101010];

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		int N; scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%lld", &A[i]);
		ll sum = 0, mn = 1;
		for(int i = 1; i <= N; i++) {
			sum += A[i]; mn = min(mn, sum);
		}
		sum = 0;
		for(int i = N; i >= 1; i--) {
			sum += A[i]; mn = min(mn, sum);
		}
		if(mn <= 0) puts("NO");
		else puts("YES");
	}
	return 0;
}