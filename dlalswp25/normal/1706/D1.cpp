#include <bits/stdc++.h>

using namespace std;

const int INF = 1010101010;
const int MX = 3000;

int N, K;
int A[3030];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &K);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		int ans = INF;
		for(int i = 0; i <= MX; i++) {
			int k = 1;
			int mx = 0;
			bool ok = true;
			for(int j = 1; j <= N; j++) {
				while(k < K && A[j] / (k + 1) >= i) k++;
				if(A[j] / k < i) ok = false;
				mx = max(mx, A[j] / k);
			}
			if(ok) ans = min(ans, mx - i);
		}
		printf("%d\n", ans);
	}
	return 0;
}