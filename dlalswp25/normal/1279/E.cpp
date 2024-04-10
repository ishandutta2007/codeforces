#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll XX = 1000000000000000000;

ll N, K;
ll D[55];
ll E[55];
int ans[55];
vector<int> perm;
int p[55];
bool chk[55];

int par(int x) {
	if(x == p[x]) return x;
	return p[x] = par(p[x]);
}

void unite(int a, int b) {
	a = p[a]; b = p[b];
	if(a == b) return;
	p[a] = b;
}

void f(int n, ll k) {
	perm.clear(); perm.push_back(n);
	k--;

	for(int i = 1; i <= n; i++) { p[i] = i; chk[i] = false; }
	unite(1, n); chk[n] = true;

	for(int i = 1; i < n; i++) {
		for(int j = 1; j < n; j++) {
			if(chk[j] || par(perm.size() + 1) == par(j)) continue;
			if(k >= D[n - i]) k -= D[n - i];
			else {
				unite(perm.size() + 1, j);
				perm.push_back(j); chk[j] = true;
				break;
			}
		}
	}
	for(int i = 1; i <= n; i++) if(!chk[i]) perm.push_back(i);
}

ll mul(ll a, ll b) {
	ll ret = 0;
	while(b) {
		if(b & 1) ret = ret + a;
		a = a + a;
		b >>= 1;
		if(ret > XX || a > XX) return XX + 1;
	}
	return ret;
}

int main() {
	D[0] = D[1] = D[2] = 1;
	for(int i = 3; i <= 22; i++) D[i] = D[i - 1] * (i - 2);
	for(int i = 23; i <= 50; i++) D[i] = D[i - 1];
	E[0] = 1;
	for(int i = 1; i <= 21; i++) {
		for(int j = 1; j <= i; j++) {
			E[i] += D[j] * E[i - j];
			// printf("%lld %lld\n", E[i], mul(D[j], E[i - j]));
		}
	}
	for(int i = 22; i <= 50; i++) E[i] = XX + 1;
	// printf("%lld %lld\n", D[22], E[21]);
	// printf("%lld %lld\n", D[21], E[21]);

	// f(5, 2);
	// for(int i : perm) printf("%d ", i); puts("");
	// for(int j = 2; j <= 21; j++) printf("%lld ", mul(D[j], E[22 - j]));

	int T; scanf("%d", &T);
	while(T--) {
		scanf("%lld%lld", &N, &K); K--;
		int i = 1;
		while(1) {
			if(E[N - i] > K) {
				ans[i] = i; i++; continue;
			}
			else break;
		}

		bool ok = true;

		while(i <= N) {
			int j;
			for(j = 1; j <= N - i + 1; j++) {
				if(E[N - i + 1 - j] <= K && mul(D[j], E[N - i + 1 - j]) <= K) {
					K -= D[j] * E[N - i + 1 - j];
				}
				else break;
			}
			if(j > N - i + 1) { puts("-1"); ok = false; break; }

			// printf("%d %d %lld\n", i, j, K);

			ll t = K / E[N - i + 1 - j];
			K -= t * E[N - i + 1 - j];

			f(j, t + 1);
			for(int k = 0; k < j; k++) ans[i + k] = perm[k] + i - 1;
			i += j;
		}

		if(!ok) continue;

		if(K > 0) puts("-1");
		else {
			for(int i = 1; i <= N; i++) printf("%d ", ans[i]); puts("");
		}
	}
	return 0;
}