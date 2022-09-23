#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MX = 300000;

int N;
ll A[202020];

struct FWT {
	ll T[303030] = {0, };

	void upd(int x, int v) {
		if(x > MX) return;
		for(int i = x; i <= MX; i += i&-i) T[i] += v;
	}

	ll get(int x) {
		ll ret = 0;
		for(int i = x; i; i -= i&-i) ret += T[i];
		return ret;
	}

	ll query(int l, int r) {
		r = min(r, MX);
		return get(r) - get(l - 1);
	}
}Fcnt, Fsum, Fx;

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%lld", &A[i]);
	ll ans = 0;
	for(int i = 1; i <= N; i++) {
		ans += A[i] * (i - 1);
		ans += Fsum.query(1, A[i] - 1);
		ans -= Fx.get(A[i]);
		ll s = Fsum.query(A[i] + 1, MX);

		int t = A[i];
		for(int j = 1; t <= MX; j++) {
			s -= t * Fcnt.query(t, t + A[i] - 1);
			Fx.upd(t, A[i]);

			t += A[i];
		}
		ans += s;

		Fcnt.upd(A[i], 1);
		Fsum.upd(A[i], A[i]);
		printf("%lld ", ans);
	}
	puts("");
	return 0;
}