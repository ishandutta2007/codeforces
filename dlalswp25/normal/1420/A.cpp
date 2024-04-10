#include <bits/stdc++.h>

using namespace std;

int A[50505];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int N; scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		bool ok = false;
		for(int i = 2; i <= N; i++) if(A[i - 1] <= A[i]) ok = true;
		sort(A + 1, A + N + 1);
		for(int i = 2; i <= N; i++) if(A[i] == A[i - 1]) ok = true;
		puts(ok ? "YES" : "NO");
	}
	return 0;
}