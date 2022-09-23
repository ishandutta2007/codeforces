#include <bits/stdc++.h>

using namespace std;

int A[202020];
int C[202020];

int cnt[202020];
vector<int> ans[202020];

int main() {
	int N, K; scanf("%d%d", &N, &K);
	for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
	for(int i = 1; i <= K; i++) scanf("%d", &C[i]);

	sort(A + 1, A + N + 1);
	reverse(A + 1, A + N + 1);

	int l = 1, r = N;
	while(l <= r) {
		int m = l + r >> 1;
		bool ok = true;

		int x = 1;
		for(int i = 1; i <= N; i++) {
			cnt[x]++;
			if(C[A[i]] < cnt[x]) ok = false;

			x++; if(x > m) x = 1;
		}

		if(ok) r = m - 1;
		else l = m + 1;

		for(int i = 1; i <= m; i++) cnt[i] = 0;
	}

	int x = 1;
	for(int i = 1; i <= N; i++) {
		ans[x].push_back(A[i]);
		x++; if(x > l) x = 1;
	}

	printf("%d\n", l);
	for(int i = 1; i <= l; i++) {
		printf("%d ", ans[i].size());
		for(int j : ans[i]) printf("%d ", j); puts("");
	}

	return 0;
}