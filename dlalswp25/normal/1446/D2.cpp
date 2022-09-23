#include <bits/stdc++.h>

using namespace std;

const int B = 2000;

int N;
int A[202020];

int S[202020][105];
int F[105][404040];
int X;

int big[105];
int rev[202020];
int id;

int lst[2020];

vector<int> v;

vector<int> w[202020];

int cnt[202020];

int main() {
	// freopen("input.txt", "r", stdin);
	scanf("%d", &N);

	int mx = -1, mxcnt = 0;

	for(int i = 1; i <= N; i++) {
		scanf("%d", &A[i]);
		cnt[A[i]]++;
	}

	for(int i = 1; i <= N; i++) {
		if(mx < cnt[i]) { mx = cnt[i]; mxcnt = 1; }
		else if(mx == cnt[i]) mxcnt++;
	}

	if(mx == N) { puts("0"); return 0; }
	if(mxcnt >= 2) { printf("%d\n", N); return 0; }

	for(int i = 1; i <= N; i++) {
		if(cnt[i] == mx) X = i;
	}
	for(int i = 1; i <= N; i++) {
		if(cnt[i] >= B || i == X || i % N + 1 == X) {
			big[++id] = i;
			rev[i] = id;
		}
	}

	for(int i = 1; i <= N; i++) if(A[i] == X) v.push_back(i);
	v.push_back(N + 1);
	for(int i = 1; i <= id; i++) for(int j = 0; j <= 400000; j++) F[i][j] = N + 1;

	for(int i = 1; i <= id; i++) {
		S[0][i] = 200000;
		F[i][200000] = 0;
	}

	for(int i = 1; i <= N; i++) {
		if(A[i] == X) {
			for(int j = 1; j <= id; j++) {
				S[i][j] = S[i - 1][j];
				if(big[j] != X) S[i][j]--;
			}
		}
		else {
			for(int j = 1; j <= id; j++) S[i][j] = S[i - 1][j];
			S[i][rev[A[i]]]++;
		}

		for(int j = 1; j <= id; j++) {
			F[j][S[i][j]] = min(F[j][S[i][j]], i);
		}
	}

	int bef = 0;
	int ans = 0;
	for(int i = 0; i < v.size(); i++) {
		int x = v[i] - 1;
		if(!x) continue;

		for(int j = bef + 1; j <= v[i] - 1; j++) {
			if(rev[A[j]]) continue;
			w[A[j]].push_back(j);
			for(int k = (int)w[A[j]].size() - 1, l = 1; k >= 0; k--, l++) {
				lst[l] = max(lst[l], w[A[j]][k]);
			}
		}
		// printf("x=%d\n", v[i]);
		// for(int j = 1; j <= 5; j++) printf("%d ", lst[j]); puts("");

		for(int j = 1; j <= min(B, i - 1); j++) {
			// printf("%d %d %d %d\n", j, v[i - j - 1], lst[j], lst[j + 1]);
			if(lst[j] >= v[i - j - 1] && v[i - j - 1] >= lst[j + 1]) ans = max(ans, v[i] - v[i - j - 1] - 1);
		}
		int j = i;
		if(j <= B) {
			if(lst[j] >= 1 && 1 >= lst[j + 1]) ans = max(ans, v[i] - 1);
		}

		bef = v[i];

		int l = N + 1;
		for(int j = 1; j <= id; j++) {
			if(big[j] == X) continue;
			l = min(l, F[j][S[x][j]]);
		}
		if(i >= B && l < v[i - B]) ans = max(ans, x - l);
	}

	printf("%d\n", ans);

	return 0;
}