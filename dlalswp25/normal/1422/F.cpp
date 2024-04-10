#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 1000000007;
const int BSZ = 500;

int N, Q;
int A[101010];
int C[101010];
int rgt[101010];
int lst[202020];
bool notprime[202020];

struct SEG {
	int T[262626];
	int base = 131072;

	void build() {
		for(int i = 0; i < N; i++) T[base + i] = C[i + 1];
		for(int i = base - 1; i >= 1; i--) T[i] = max(T[i << 1], T[i << 1 | 1]);
	}

	int get(int idx, int s, int e, int p, int q) {
		p += base; q += base;
		p--; q--;
		int ret = 0;
		while(p <= q) {
			if(p & 1) { ret = max(ret, T[p]); p++; }
			if(~q & 1) { ret = max(ret, T[q]); q--; }
			p >>= 1; q >>= 1;
		}
		return ret;
	}
}seg[105];

struct NODE {
	ll x;
	int l, r;

	NODE() : x(1), l(0), r(0) {}
}T[20 * 101010];

int rt[101010];
int id;

int maketree(int bef, int s, int e, int p, ll x) {
	if(p < s || e < p) return bef;
	int now = ++id;
	if(s == e) {
		T[now].x = T[bef].x * x % MOD;
		return now;
	}

	int m = s + e >> 1;
	T[now].l = maketree(T[bef].l, s, m, p, x);
	T[now].r = maketree(T[bef].r, m + 1, e, p, x);
	T[now].x = T[T[now].l].x * T[T[now].r].x % MOD;
	return now;
}

ll get(int idx, int s, int e, int p, int q) {
	if(q < p || q < s || e < p) return 1;
	if(p <= s && e <= q) return T[idx].x;
	int m = s + e >> 1;
	return get(T[idx].l, s, m, p, q) * get(T[idx].r, m + 1, e, p, q) % MOD;
}

ll pw(ll a, ll b) {
	ll ret = 1;
	while(b) {
		if(b & 1) ret = ret * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return ret;
}

ll inv(ll x) { return pw(x, MOD - 2); }

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%d", &A[i]);

	int sid = 0;
	for(int i = 2; i <= BSZ; i++) {
		if(notprime[i]) continue;

		for(int j = 1; j <= N; j++) {
			C[j] = 1;
			while(A[j] % i == 0) {
				A[j] /= i; C[j] *= i;
			}
		}

		sid++;
		seg[sid].build();

		for(ll j = (ll)i * i; j <= 200000; j += i) notprime[j] = true;
	}

	for(int i = 1; i <= N; i++) {
		rgt[lst[A[i]]] = i;
		lst[A[i]] = i;
	}

	for(int i = 1; i <= N; i++) if(!rgt[i]) rgt[i] = N + 1;

	for(int i = 1; i <= N; i++) {
		rt[i] = maketree(rt[i - 1], 1, N + 1, rgt[i], A[i]);
	}

	scanf("%d", &Q);
	ll last = 0;
	while(Q--) {
		int x, y; scanf("%d%d", &x, &y);
		x = (x + last) % N + 1;
		y = (y + last) % N + 1;

		if(x > y) swap(x, y);
		// printf("x y %d %d\n", x, y);
		ll ans = 1;
		for(int i = 1; i <= sid; i++) ans = ans * seg[i].get(1, 1, N, x, y) % MOD;

		ans = ans * get(rt[y], 1, N + 1, y + 1, N + 1) % MOD * inv(get(rt[x - 1], 1, N + 1, y + 1, N + 1)) % MOD;
		printf("%lld\n", ans);
		last = ans;
	}

	return 0;
}