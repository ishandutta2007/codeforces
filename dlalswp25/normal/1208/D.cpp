#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll INF = (1LL) << 60;

struct NODE {
	ll x;
	ll lz;
};

NODE T[4 * 202020];
ll A[202020];
int N;
int ans[202020];

void init(int idx, int s, int e) {
	if(s == e) {
		T[idx].x = A[s];
		return;
	}
	int m = s + e >> 1;
	init(idx * 2, s, m);
	init(idx * 2 + 1, m + 1, e);
	T[idx].x = min(T[idx * 2].x, T[idx * 2 + 1].x);
}

void propa(int idx, int s, int e) {
	T[idx].x -= T[idx].lz;
	if(s == e) { T[idx].lz = 0; return; }
	T[idx * 2].lz += T[idx].lz;
	T[idx * 2 + 1].lz += T[idx].lz;
	T[idx].lz = 0;
}

void upd(int idx, int s, int e, int p, int q, ll x) { // subtract x
	propa(idx, s, e);
	if(e < s || q < p || q < s || e < p) return;
	if(p <= s && e <= q) {
		T[idx].lz += x;
		propa(idx, s, e);
		return;
	}
	int m = s + e >> 1;
	upd(idx * 2, s, m, p, q, x);
	upd(idx * 2 + 1, m + 1, e, p, q, x);
	T[idx].x = min(T[idx * 2].x, T[idx * 2 + 1].x);
}

ll get(int idx, int s, int e, int p, int q) {
	propa(idx, s, e);
	if(e < s || q < p || q < s || e < p) return INF;
	if(p <= s && e <= q) return T[idx].x;
	int m = s + e >> 1;
	return min(get(idx * 2, s, m, p, q), get(idx * 2 + 1, m + 1, e, p, q));
}

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%lld", &A[i]);

	init(1, 1, N);
	
	for(int i = 1; i <= N; i++) {
		int l = 1, r = N;
		while(l <= r) {
			int m = l + r >> 1;
			ll t = get(1, 1, N, m, N);
			if(t) r = m - 1;
			else l = m + 1;
		}
		ans[r] = i;
		upd(1, 1, N, r + 1, N, i);
		upd(1, 1, N, r, r, -INF);
	}
	for(int i = 1; i <= N; i++) printf("%d ", ans[i]); puts("");

	return 0;
}