#include <bits/stdc++.h>

using namespace std;

int A[303030];
int N, M;

int main() {
	scanf("%d%d", &N, &M);
	for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
	int l = 0, r = M - 1;

	while(l <= r) {
		int m = l + r >> 1;

		int a = 0;
		bool ok = true;
		for(int i = 1; i <= N; i++) {
			int mn = A[i], mx = A[i] + m;
			if(mx >= M && mx % M < a) a = max(a, mn);
			else if(mx >= M) continue;
			else if(mx < a) { ok = false; break; }
			else a = max(a, mn);
		}
		if(ok) r = m - 1;
		else l = m + 1;
	}
	printf("%d\n", l);
	return 0;
}