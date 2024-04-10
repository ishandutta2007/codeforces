#include <bits/stdc++.h>

using namespace std;

int A[55];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int N; scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		sort(A + 1, A + N + 1);
		bool ok = true;
		for(int i = 2; i <= N; i++) if(A[i] - A[i - 1] >= 2) ok = false;
		puts(ok ? "YES" : "NO");
	}
	return 0;
}