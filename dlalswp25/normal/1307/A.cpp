#include <bits/stdc++.h>

using namespace std;

int N, D;
int A[105];

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &N, &D);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);

		int ans = A[1];
		int p = 2;
		while(1) {
			if(p > N) break;
			while(A[p]) {
				if((p - 1) > D) break;
				D -= (p - 1); A[p]--; ans++;
			}
			if(A[p]) break;
			p++;
		}
		printf("%d\n", ans);
	}
	return 0;
}