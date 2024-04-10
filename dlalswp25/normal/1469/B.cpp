#include <bits/stdc++.h>

using namespace std;

int N, M;
int A[105];
int B[105];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		scanf("%d", &M);
		for(int i = 1; i <= M; i++) scanf("%d", &B[i]);

		int sa = 0, ma = 0;
		int sb = 0, mb = 0;
		for(int i = 1; i <= N; i++) {
			sa += A[i]; ma = max(ma, sa);
		}
		for(int i = 1; i <= M; i++) {
			sb += B[i]; mb = max(mb, sb);
		}
		printf("%d\n", ma + mb);
	}
	return 0;
}