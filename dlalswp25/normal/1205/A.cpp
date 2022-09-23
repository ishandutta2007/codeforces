#include <bits/stdc++.h>

using namespace std;

int ans[202020];

int main() {
	int N; scanf("%d", &N);
	if(N % 2 == 0) { puts("NO"); return 0; }
	puts("YES");

	for(int i = 1; i <= N; i++) {
		if(i & 1) { ans[i] = 2 * i - 1; ans[N + i] = 2 * i; }
		else { ans[i] = 2 * i; ans[N + i] = 2 * i - 1; }
	}
	for(int i = 1; i <= 2 * N; i++) printf("%d ", ans[i]); puts("");

	return 0;
}