#include <bits/stdc++.h>

using namespace std;

int N;
int A[10101];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		bool ok = true;
		for(int i = 1; i < N; i++) if(A[i] > A[i + 1]) ok = false;
		puts(ok ? "NO" : "YES");
	}
	return 0;
}