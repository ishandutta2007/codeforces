#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 998244353;
const int MX = 400000;

int N, M;
ll F[404040];
ll I[404040];
int X[202020];
int Y[202020];
int p[202020];
vector<int> v;

struct Fenwick {
	int T[202020] = {0, };

	void upd(int x, int v) {
		for(int i = x; i <= N; i += i&-i) T[i] += v;
	}

	int get(int x) {
		int ret = 0;
		for(int i = x; i; i -= i&-i) ret += T[i];
		return ret;
	}
}fwt;

int par(int x) {
	if(x == p[x]) return x;
	return p[x] = par(p[x]);
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

ll ncr(int n, int r) {
	if(n < r) return 0;
	return F[n] * I[r] % MOD * I[n - r] % MOD;
}

ll nhr(int n, int r) {
	return ncr(n + r - 1, r);
}

int main() {
	F[0] = 1; for(int i = 1; i <= MX; i++) F[i] = F[i - 1] * i % MOD;
	I[MX] = inv(F[MX]);
	for(int i = MX - 1; i >= 0; i--) I[i] = I[i + 1] * (i + 1) % MOD;

	for(int i = 1; i <= MX / 2; i++) p[i] = i;

	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &M);
		for(int i = 1; i <= M; i++) scanf("%d%d", &X[i], &Y[i]);
		v.clear();

		set<int> S;

		for(int i = M; i >= 1; i--) {
			int l = 1, r = N;
			while(l <= r) {
				int m = l + r >> 1;
				if(m - fwt.get(m) >= Y[i]) r = m - 1;
				else l = m + 1;
			}
			// l
			v.push_back(l);
			fwt.upd(l, 1);
			int t = par(l + 1);
			p[l] = t;
			S.insert(t);
		}

		int K = S.size();
		printf("%lld\n", nhr(N - K, N));

		for(int i : v) {
			fwt.upd(i, -1);
			p[i] = i;
		}
	}
	return 0;
}