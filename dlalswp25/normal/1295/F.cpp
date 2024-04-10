#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 998244353;

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

int up[55];
int dn[55];
int N;

ll D[105][105];

ll L[55];
ll R[55];

vector<ll> v;

ll ncr(ll n, ll r) {
	ll ret = 1;
	for(int i = n; i >= n - r + 1; i--) ret = ret * i % MOD;
	for(int i = 2; i <= r; i++) ret = ret * inv(i) % MOD;
	// printf("%lld %lld %lld\n", n, r, ret);
	return ret;
}

int get(ll x) {
	return lower_bound(v.begin(), v.end(), x) - v.begin() + 1;
}
ll gety(int idx) { return v[idx - 1]; }

ll f(ll x, ll y) {
	if(x > N) return 1;
	if(y < dn[x]) return 0;
	if(D[x][y] != -1) return D[x][y];
	if(y >= up[x]) return D[x][y] = f(x, up[x] - 1);

	ll& ret = D[x][y];
	ret = f(x, y - 1);
	
	//for(int i = y - 1; i >= dn[x]; i--) ret = (ret + f(x, i)) % MOD;
	// printf("%lld %lld %lld\n", x, y, ret);

	ll dy = gety(y + 1) - gety(y);
	// printf("%lld %lld %lld\n", x, y, dy);
	for(int i = x; i <= N; i++) {
		if(up[i] <= y || y < dn[i]) break;
		int r = i - x + 1;
		// printf("%lld %lld fojiewf e%lld\n", x, y, ncr(dy + r - 1, r));
		ret = (ret + ncr(dy + r - 1, r) * f(i + 1, y - 1)) % MOD;
	}
	return ret;
}

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) {
		scanf("%lld%lld", &L[i], &R[i]);
		R[i]++;
		v.push_back(L[i]);
		v.push_back(R[i]);
	}

	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	for(int i = 1; i <= N; i++) {
		up[i] = get(R[i]);
		dn[i] = get(L[i]);
	}

	// for(int i = 1; i <= N; i++) printf("%d %d\n", dn[i], up[i]);

	for(int i = 1; i <= 2 * N; i++) {
		for(int j = 1; j <= 2 * N; j++) D[i][j] = -1;
	}

	ll ans = f(1, v.size());
	// printf("%lld\n", ans);
	for(int i = 1; i <= N; i++) ans = ans * inv(R[i] - L[i]) % MOD;
	printf("%lld\n", ans);

	// printf("%lld\n", f(1, v.size()));
	// for(int i = 1; i <= N; i++) for(int j = 1; j <= 3; j++) printf("%d %d %lld\n", i, j, f(i, j));

	return 0;
}