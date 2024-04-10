#include <bits/stdc++.h>

using namespace std;

int N;
int A[202020];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		puts(A[N] - A[1] > N + 1 ? "NO" : "YES");
	}
	return 0;
}