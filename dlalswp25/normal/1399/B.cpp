#include <bits/stdc++.h>

using namespace std;

int N;
int A[55];
int B[55];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		int mna = 1010101010, mnb = 1010101010;
		for(int i = 1; i <= N; i++) {
			scanf("%d", &A[i]);
			mna = min(mna, A[i]);
		}
		for(int i = 1; i <= N; i++) {
			scanf("%d", &B[i]);
			mnb = min(mnb, B[i]);
		}

		long long ans = 0;
		for(int i = 1; i <= N; i++) {
			int da = A[i] - mna, db = B[i] - mnb;
			ans += max(da, db);
		}
		printf("%lld\n", ans);
	}
	return 0;
}