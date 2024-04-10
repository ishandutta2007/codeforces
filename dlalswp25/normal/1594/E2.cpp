#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

int N, K;
char buf[20];
int id = 1;

struct Node {
	int l = 0, r = 0;
	int c = -1;
	ll D[3];
}T[202020];

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

int ins(int now, int b, ll x, int c) {
	if(!now) now = ++id;
	if(b < 0) {
		T[now].c = c;
		return now;
	}
	if(~x & 1) {
		T[now].l = ins(T[now].l, b - 1, x >> 1, c);
	}
	else {
		T[now].r = ins(T[now].r, b - 1, x >> 1, c);
	}
	return now;
}

void f(int now, int b) {
	if(!now) return;
	if(!b) {
		for(int i = 0; i < 3; i++) T[now].D[i] = 0;
		if(T[now].c != -1) T[now].D[T[now].c] = 1;
		return;
	}
	ll lft[3], rgt[3];
	f(T[now].l, b - 1);
	f(T[now].r, b - 1);
	if(!T[now].l) {
		lft[0] = lft[1] = lft[2] = 2 * pw(4, (1LL << b) - 2) % MOD;
	}
	else {
		for(int i = 0; i < 3; i++) lft[i] = T[T[now].l].D[i];
	}
	if(!T[now].r) {
		rgt[0] = rgt[1] = rgt[2] = 2 * pw(4, (1LL << b) - 2) % MOD;
	}
	else {
		for(int i = 0; i < 3; i++) rgt[i] = T[T[now].r].D[i];
	}

	// for(int i = 0; i < 3; i++) printf("%lld ", lft[i]); puts("");
	// for(int i = 0; i < 3; i++) printf("%lld ", rgt[i]); puts("");

	for(int i = 0; i < 3; i++) {
		if(T[now].c != -1 && i != T[now].c) { T[now].D[i] = 0; continue; }
		T[now].D[i] = 0;
		for(int j = 0; j < 3; j++) {
			for(int k = 0; k < 3; k++) {
				if(i == j || i == k) continue;
				if(T[now].c != -1 && (T[now].c == j || T[now].c == k)) continue;
				T[now].D[i] = (T[now].D[i] + lft[j] * rgt[k] * (1 + (T[now].c == -1))) % MOD;
			}
		}
	}

	// printf("%d %lld %lld %lld\n", now, T[now].D[0], T[now].D[1], T[now].D[2]);
}

int main() {
	scanf("%d", &K);
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) {
		ll t; scanf("%lld", &t);

		int dep = 0; ll x = 0;
		while(t) {
			x = x << 1 | (t & 1);
			t >>= 1; dep++;
		}

		scanf("%s", buf);
		int c;
		if(buf[0] == 'o' || buf[0] == 'r') c = 0;
		else if(buf[0] == 'b' || buf[0] == 'g') c = 1;
		else c = 2;
		ins(1, dep - 2, x >> 1, c);
	}

	f(1, K - 1);
	ll ans = (T[1].D[0] + T[1].D[1] + T[1].D[2]) % MOD;
	printf("%lld\n", ans);

	return 0;
}