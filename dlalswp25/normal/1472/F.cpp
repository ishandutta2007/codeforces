#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int N, M;
pii A[202020];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &M);
		for(int i = 1; i <= M; i++) {
			scanf("%d%d", &A[i].second, &A[i].first);
		}
		if(M & 1) { puts("NO"); continue; }
		sort(A + 1, A + M + 1);
		bool ok = true;
		for(int i = 1; i <= M / 2; i++) {
			int a = 2 * i - 1, b = 2 * i;
			if((A[a].first + A[a].second & 1) == (A[b].first + A[b].second & 1)) { ok = false; break; }
			if(i < M / 2 && A[b].first == A[b + 1].first) { ok = false; break; }
		}
		puts(ok ? "YES" : "NO");
	}
	return 0;
}