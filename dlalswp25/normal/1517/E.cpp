#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, int> pii;

const ll MOD = 998244353;

int N;
ll A[202020];
ll X[202020];
ll Z[202020];
ll S[202020];
ll R[202020];
vector<pii> V;
ll ans;

struct FWT {
	int T[202020] = {0, };

	void init() {
		for(int i = 1; i <= N; i++) T[i] = 0;
	}

	void upd(int x, int v) {
		for(int i = x; i <= N; i += i&-i) T[i] += v;
	}

	int get(int x) {
		int ret = 0;
		for(int i = x; i; i -= i&-i) ret += T[i];
		return ret;
	}

	int query(int l, int r) {
		return get(r) - get(l - 1);
	}
}fwt;

void f(int l, int r, ll x) {
	if(l > r + 1) return;
	if(l > r) {
		if(x > 0) ans++;
		return;
	}

	S[l - 1] = 0;
	for(int i = l; i <= r; i++) {
		S[i] = -S[i - 1] - A[i];
	}
	X[r] = 0;
	for(int i = r - 1; i >= l - 1; i--) X[i] = X[i + 1] + A[i + 1];
	Z[l - 1] = 0;
	for(int i = l; i <= r; i++) Z[i] = Z[i - 1] - A[i];

	V.clear();
	fwt.init();
	for(int i = l - 1; i <= r; i++) V.emplace_back(Z[i] - S[i], i);
	sort(V.begin(), V.end());
	
	for(int i = l - 1; i <= r; i += 2) {
		int t = lower_bound(V.begin(), V.end(), pii(Z[i] - S[i], i)) - V.begin() + 1;
		fwt.upd(t, 1);
		t = lower_bound(V.begin(), V.end(), pii(-(S[i] + X[i] + x), 10101010)) - V.begin() + 1;
		ans += fwt.query(t, N);
	}
	fwt.init();
	for(int i = l; i <= r; i += 2) {
		int t = lower_bound(V.begin(), V.end(), pii(Z[i] - S[i], i)) - V.begin() + 1;
		fwt.upd(t, 1);
		t = lower_bound(V.begin(), V.end(), pii(-(S[i] + X[i] + x), 10101010)) - V.begin() + 1;
		ans += fwt.query(t, N);
	}
}

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		ans = 0;
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%lld", &A[i]);

		f(3, N - 2, A[1] - A[2] + A[N - 1] - A[N]);
		// printf("%lld\n", ans);
		f(3, N - 1, A[1] - A[2] + A[N]);
		// printf("%lld\n", ans);
		f(2, N - 2, -A[1] + A[N - 1] - A[N]);
		// printf("%lld\n", ans);
		f(2, N - 1, -A[1] + A[N]);
		// printf("%lld\n", ans);

		R[N] = 0;
		for(int i = N - 1; i >= 0; i--) R[i] = R[i + 1] - A[i + 1];
		ll lft = 0;
		for(int i = 0; i <= N; i++) {
			if(lft + R[i] > 0) ans++;
			lft += A[i + 1];
		}

		printf("%lld\n", ans % MOD);
	}
	return 0;
}