#include<bits/stdc++.h>
using namespace std;

const int maxN = 1000005;
int N, M, K;
int S, T;
int p[21];
int F[1048576], G[1048576];
int calc(int s, int a, int b) {
	int k = ((s >> a) & 1) ^ ((s >> b) & 1);
	return s ^ (k << a) ^ (k << b);
}

int main() {
	scanf("%d%d%d", &N, &M, &K);
	memset(F, 0x3f, sizeof(F)); memset(G, -1, sizeof(G));
	for(int i = 0; i < K; i++) {int x; scanf("%1d", &x); S = S << 1 | x;} if(F[S] == 0x3f3f3f3f) F[S] = 0;
	for(int i = 0; i < K; i++) {int x; scanf("%1d", &x); T = T << 1 | x;} G[T] = 0;
	for(int i = 0; i < K; i++) p[i] = i;
	for(int i = 1; i <= N; i++) {
		int a, b; scanf("%d%d", &a, &b); swap(p[a = K - a], p[b = K - b]);
		S = calc(S, p[a], p[b]); if(F[S] == 0x3f3f3f3f) F[S] = i;
		T = calc(T, p[a], p[b]); G[T] = i;
	}
	for(int i = 0; i < 20; i++)
	for(int s = 0; s < 1048576; s++) if(!((s >> i) & 1))
		F[s] = min(F[s], F[s | (1 << i)]),
		G[s] = max(G[s], G[s | (1 << i)]);
	int ans = -1, l = -1, r = -1;
	for(int s = 0; s < 1048576; s++) if(__builtin_popcount(s) > ans)
		if(G[s] - F[s] >= M) ans = __builtin_popcount(s), l = F[s] + 1, r = G[s];
	printf("%d\n%d %d\n", 2 * ans + K - __builtin_popcount(S) - __builtin_popcount(T), l, r);
}