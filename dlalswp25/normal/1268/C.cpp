#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll inv[202020];
int N;
int A[202020];
int pos[202020];

int F[202020];
ll T[4 * 202020];

set<int> S;

void updf(int x, int v) {
	for(int i = x; i <= N; i += i&-i) F[i] += v;
}
int query(int x) {
	if(!x) return 0;
	int ret = 0;
	for(int i = x; i; i -= i&-i) ret += F[i];
	return ret;
}

ll f(int s, int e) {
	return (ll)e * (e + 1) / 2 - (ll)s * (s - 1) / 2;
}

void upd(int idx, int s, int e, int p, int x) {
	if(e < s || p < s || e < p) return;
	if(s == e) { T[idx] = x; return; }
	int m = s + e >> 1;
	upd(idx << 1, s, m, p, x);
	upd(idx << 1 | 1, m + 1, e, p, x);
	T[idx] = T[idx << 1] + T[idx << 1 | 1];
}

ll get(int idx, int s, int e, int p, int q) {
	if(e < s || q < p || q < s || e < p) return 0;
	if(p <= s && e <= q) return T[idx];
	int m = s + e >> 1;
	return get(idx << 1, s, m, p, q) + get(idx << 1 | 1, m + 1, e, p, q);
}

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) {
		scanf("%d", &A[i]);
		pos[A[i]] = i;
	}

	for(int i = 1; i <= N; i++) {
		inv[i] = inv[i - 1] + (query(N) - query(pos[i]));
		updf(pos[i], 1);
	}

	int tmp = 1;
	printf("0 ");
	S.insert(pos[1]);
	auto it = S.begin();
	upd(1, 1, N, pos[1], pos[1]);

	// for(int i = 1; i <= N; i++) printf("%lld ", inv[i]); puts("");

	for(int i = 2; i <= N; i++) {
		upd(1, 1, N, pos[i], pos[i]);
		S.insert(pos[i]);
		if(pos[i] < *it) tmp++;

		int mid = (i + 1) / 2;

		if(tmp > mid) { it--; tmp--; }
		if(tmp < mid) { it++; tmp++; }

		int x = (*it);
		ll ans = inv[i];
		// printf("x %d\n", x);

		// printf("f1 %lld\n", f(x + 1, x + (i - mid)));
		// printf("f2 %lld\n", f(x - mid + 1, x - 1));

		// printf("%lld ", ans);
		// printf("%lld ", get(1, 1, N, x + 1, N));
		ans += get(1, 1, N, x + 1, N) - f(x + 1, x + (i - mid));
		// printf("%lld ", ans);
		ans += f(x - mid + 1, x - 1) - get(1, 1, N, 1, x - 1);
		printf("%lld ", ans);
	}
	puts("");

	return 0;
}