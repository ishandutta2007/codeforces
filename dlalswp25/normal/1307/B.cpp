#include <bits/stdc++.h>

using namespace std;

int N;
int A[101010];

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		int x; scanf("%d%d", &N, &x);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);

		sort(A + 1, A + N + 1);

		bool ok = false;
		for(int i = 1; i <= N; i++) {
			if(A[i] == x) { ok = true; break; }
		}
		if(ok) { puts("1"); continue; }

		if(A[N] > x) { puts("2"); continue; }
		int ans = x / A[N];
		if(x % A[N]) ans++;
		printf("%d\n", ans);
	}
	return 0;
}