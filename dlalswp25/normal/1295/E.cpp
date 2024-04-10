#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll A[202020];
ll B[202020];
int P[202020];
int pos[202020];
int N;

struct NODE {
	ll x;
	ll lz;
}T[4 * 202020];

void upd(int idx, int s, int e, int p, int q, ll x) {
	if(q < p || q < s || e < p) return;
	if(p <= s && e <= q) { T[idx].x += x; T[idx].lz += x; return; }
	int m = s + e >> 1;
	upd(idx << 1, s, m, p, q, x);
	upd(idx << 1 | 1, m + 1, e, p, q, x);
	T[idx].x = min(T[idx << 1].x, T[idx << 1 | 1].x) + T[idx].lz;
}

ll get(int idx, int s, int e, int p, int q) {
	if(q < p || q < s || e < p) return (1LL << 60);
	if(p <= s && e <= q) return T[idx].x;
	int m = s + e >> 1;
	return min(get(idx << 1, s, m, p, q), get(idx << 1 | 1, m + 1, e, p, q)) + T[idx].lz;
}

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) { scanf("%d", &P[i]); pos[P[i]] = i; }
	for(int i = 1; i <= N; i++) scanf("%lld", &A[i]);
	for(int i = 1; i <= N; i++) B[P[i]] = A[i];

	ll ans = (1LL << 60);

	upd(1, 1, N, 1, P[1] - 1, A[1]);
	for(int i = 2; i <= N; i++) upd(1, 1, N, P[i] + 1, N, A[i]);

	ans = get(1, 1, N, 1, N);

	for(int i = 2; i < N; i++) {
		upd(1, 1, N, P[i] + 1, N, -A[i]);
		upd(1, 1, N, 1, P[i] - 1, A[i]);
		ans = min(ans, get(1, 1, N, 1, N));
	}
	printf("%lld\n", ans);

	return 0;
}