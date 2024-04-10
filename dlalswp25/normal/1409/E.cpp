#include <bits/stdc++.h>

using namespace std;

int N, K;
vector<int> v;
int A[202020];
int L[202020];
int R[202020];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		v.clear();
		scanf("%d%d", &N, &K);
		R[N + 1] = 0;
		for(int i = 1; i <= N; i++) {
			scanf("%d", &A[i]);
			v.push_back(A[i]);
		}
		for(int i = 1; i <= N; i++) scanf("%*d");

		sort(A + 1, A + N + 1);
		sort(v.begin(), v.end());

		for(int i = 1; i <= N; i++) {
			int t = lower_bound(v.begin(), v.end(), A[i] - K) - v.begin() + 1;
			L[i] = max(L[i - 1], i - t + 1);
		}

		for(int i = N; i >= 1; i--) {
			int t = upper_bound(v.begin(), v.end(), A[i] + K) - v.begin();
			R[i] = max(R[i + 1], t - i + 1);
		}

		// for(int i = 1; i <= N; i++) printf("%d ", L[i]); puts("");
		// for(int i = 1; i <= N; i++) printf("%d ", R[i]); puts("");

		int ans = 1;
		for(int i = 1; i < N; i++) ans = max(ans, L[i] + R[i + 1]);
		printf("%d\n", ans);
	}
	return 0;
}