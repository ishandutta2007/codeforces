#include <bits/stdc++.h>

using namespace std;

int N;
char A[5050];
int G[5050];
int cnt[5050];
int sa[5050];
int tmp[5050];
int pos[5050];
int lcp[5050];
int D[5050];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		scanf("%s", A + 1);

		for(int i = 1; i <= N; i++) G[i] = A[i] - 'a' + 1;
		int M = 26;
		G[N + 1] = 0;

		for(int len = 1; ; len <<= 1) {
			for(int i = 1; i <= M + 1; i++) cnt[i] = 0;
			for(int i = 1; i <= N; i++) cnt[G[i]]++;
			for(int i = 1; i <= M + 1; i++) cnt[i] += cnt[i - 1];
			for(int i = 1; i <= N; i++) tmp[cnt[G[i]]--] = i;
			for(int i = 1; i <= M; i++) cnt[i] = cnt[i + 1];

			for(int i = N; i >= 1; i--) {
				if(tmp[i] <= len) continue;
				sa[cnt[G[tmp[i] - len]]--] = tmp[i] - len;
			}
			for(int i = N; i > N - len; i--) sa[cnt[G[i]]--] = i;

			tmp[sa[1]] = 1;
			for(int i = 2; i <= N; i++) {
				tmp[sa[i]] = tmp[sa[i - 1]];
				if(G[sa[i - 1]] != G[sa[i]] || G[sa[i - 1] + len] != G[sa[i] + len]) tmp[sa[i]]++;
			}

			for(int i = 1; i <= N; i++) G[i] = tmp[i];
			M = G[sa[N]];
			if(M == N) break;
		}

		for(int i = 1; i <= N; i++) pos[sa[i]] = i;

		int p = 0;
		for(int i = 1; i <= N; i++) {
			if(pos[i] == 1) continue;
			int j = sa[pos[i] - 1];
			while(A[i + p] == A[j + p]) p++;
			lcp[pos[i]] = p;
			p = max(0, p - 1);
		}

		int ans = 0;
		for(int i = 1; i <= N; i++) {
			D[i] = N - i + 1;
			int l = lcp[pos[i]];
			for(int j = pos[i] - 1; j >= 1; j--) {
				if(sa[j] > i) { l = min(l, lcp[j]); continue; }
				D[i] = max(D[i], D[sa[j]] + (N - i + 1) - l);
				l = min(l, lcp[j]);
			}
			ans = max(ans, D[i]);
		}
		printf("%d\n", ans);
	}

	return 0;
}