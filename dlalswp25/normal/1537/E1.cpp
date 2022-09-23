#include <bits/stdc++.h>

using namespace std;

int N, K;

char A[1010101];
int G[1010101];
int sa[1010101];
int cnt[1010101];
int tmp[1010101];

int main() {
	scanf("%d%d", &N, &K);
	scanf("%s", A + 1);
	for(int i = N + 1; i <= N + N; i++) A[i] = A[i - N];

	N <<= 1;

	for(int i = 1; i <= N; i++) G[i] = A[i] - 'a' + 1;
	int M = 26;

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
			if(G[sa[i - 1]] < G[sa[i]] || G[sa[i - 1] + len] < G[sa[i] + len]) tmp[sa[i]]++;
		}

		for(int i = 1; i <= N; i++) G[i] = tmp[i];
		M = G[sa[N]];

		if(M == N) break;
	}

	int mn = N + 1;
	bool fg = false;
	for(int i = 1; i <= N; i++) {
		if(fg) mn = min(mn, sa[i]);
		if(sa[i] == 1) fg = true;
	}

	int p = 1;
	for(int i = 1; i <= K; i++) {
		printf("%c", A[p]);
		p = p % (mn - 1) + 1;
	}
	puts("");

	return 0;
}