#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int A[101010];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int N, M, K; scanf("%d%d%d", &N, &M, &K);
		for(int i = 1; i <= K; i++) scanf("%d", &A[i]);
		sort(A + 1, A + K + 1);
		reverse(A + 1, A + K + 1);
		bool ok = false;
		for(int z = 0; z < 2; swap(N, M), z++) {
			ll x = 0;
			if(A[1] / N <= 2 && (M & 1)) continue;
			for(int i = 1; i <= K; i++) {
				if(A[i] < 2 * N) continue;
				x += A[i] / N;
			}
			if(x >= M) ok = true;
		}
		puts(ok ? "Yes" : "No");
	}
	return 0;
}