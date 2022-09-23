#include <bits/stdc++.h>

using namespace std;

int N, K;
int A[105];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &K);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		int c = 0;
		for(int i = 2; i <= N; i++) c += (A[i - 1] != A[i]);
		if(K == 1) {
			puts(c == 0 ? "1" : "-1");
			continue;
		}
		if(c == 0) { puts("1"); continue; }
		printf("%d\n", (c - 1) / (K - 1) + 1);
	}
	return 0;
}