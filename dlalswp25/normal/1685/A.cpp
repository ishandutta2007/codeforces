#include <bits/stdc++.h>

using namespace std;

int N;
int A[101010];
int C[101010];
int ans[101010];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		if(N & 1) { puts("NO"); continue; }
		sort(A + 1, A + N + 1);
		C[1] = 1;
		int mx = 1, mxi = 1;
		for(int i = 2; i <= N; i++) {
			if(A[i] == A[i - 1]) C[i] = C[i - 1] + 1;
			else C[i] = 1;
			if(mx < C[i]) { mx = C[i]; mxi = i; }
		}
		if(mx > N / 2) { puts("NO"); continue; }
		else if(mx == N / 2 && (A[mxi] != A[1] && A[mxi] != A[N])) puts("NO");
		else {
			puts("YES");
			for(int i = 1; i <= N / 2; i++) printf("%d %d ", A[i], A[i + N / 2]); puts("");
		}
	}
	return 0;
}