#include <bits/stdc++.h>

using namespace std;

int N;
int A[202020];

int S[202020][105];
int F[105][404040];
int X;

vector<int> v;

int cnt[105];

int main() {
	scanf("%d", &N);

	int mx = -1, mxcnt = 0;

	for(int i = 1; i <= N; i++) {
		scanf("%d", &A[i]);
		cnt[A[i]]++;
	}

	for(int i = 1; i <= 100; i++) {
		if(mx < cnt[i]) { mx = cnt[i]; mxcnt = 1; }
		else if(mx == cnt[i]) mxcnt++;
	}

	if(mx == N) { puts("0"); return 0; }
	if(mxcnt >= 2) { printf("%d\n", N); return 0; }

	for(int i = 1; i <= 100; i++) {
		if(cnt[i] == mx) X = i;
	}

	for(int i = 1; i <= N; i++) if(A[i] == X) v.push_back(i);
	v.push_back(N + 1);
	for(int i = 1; i <= 100; i++) for(int j = 0; j <= 400000; j++) F[i][j] = N + 1;

	for(int i = 1; i <= 100; i++) {
		S[0][i] = 200000;
		F[i][200000] = 0;
	}

	for(int i = 1; i <= N; i++) {
		if(A[i] == X) {
			for(int j = 1; j <= 100; j++) {
				S[i][j] = S[i - 1][j];
				if(j != X) S[i][j]--;
			}
		}
		else {
			for(int j = 1; j <= 100; j++) S[i][j] = S[i - 1][j];
			S[i][A[i]]++;
		}

		for(int j = 1; j <= 100; j++) {
			F[j][S[i][j]] = min(F[j][S[i][j]], i);
		}
	}

	int ans = 0;
	for(int i : v) {
		int x = i - 1;
		if(!x) continue;

		int l = N + 1;
		for(int j = 1; j <= 100; j++) {
			if(j == X) continue;
			l = min(l, F[j][S[x][j]]);
			ans = max(ans, x - l);
		}
	}
	printf("%d\n", ans);

	return 0;
}