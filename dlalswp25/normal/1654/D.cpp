#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef tuple<int, int, int> piii;

const ll MOD = 998244353;
const int MX = 200000;

int N;
vector<piii> adj[202020];
vector<int> pf[202020];
vector<int> primes;
int sieve[202020];
int cnt[202020];
int mx[202020];
ll I[202020];
ll ans;

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

ll gcd(ll a, ll b) { while(b) { a %= b; swap(a, b); } return a; }

void dfs(int v, int par) {
	for(auto& i : adj[v]) {
		int w, p, q; tie(w, p, q) = i;
		if(w == par) continue;
		for(int j : pf[q]) {
			cnt[j]--;
			mx[j] = max(mx[j], cnt[j]);
		}
		for(int j : pf[p]) {
			cnt[j]++;
			mx[j] = max(mx[j], cnt[j]);
		}
		dfs(w, v);
		for(int j : pf[q]) cnt[j]++;
		for(int j : pf[p]) cnt[j]--;
	}
}

void calc(int v, int par, ll cur) {
	ans = (ans + cur) % MOD;
	for(auto& i : adj[v]) {
		int w, p, q; tie(w, p, q) = i;
		if(w == par) continue;
		for(int j : pf[q]) cur = cur * j % MOD;
		for(int j : pf[p]) cur = cur * I[j] % MOD;
		calc(w, v, cur);
		for(int j : pf[q]) cur = cur * I[j] % MOD;
		for(int j : pf[p]) cur = cur * j % MOD;
	}
}

int main() {
	for(int i = 2; i <= MX; i++) {
		if(!sieve[i]) { sieve[i] = i; primes.push_back(i); }
		for(int j : primes) {
			if(i * j > MX) break;
			sieve[i * j] = j;
			if(i % j == 0) break;
		}
	}

	for(int i = 2; i <= MX; i++) {
		pf[i] = pf[i / sieve[i]];
		pf[i].push_back(sieve[i]);
	}

	for(int i = 1; i <= MX; i++) I[i] = inv(i);

	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) adj[i].clear();
		for(int i = 1; i < N; i++) {
			int a, b, p, q; scanf("%d%d%d%d", &a, &b, &p, &q);
			int g = gcd(p, q); p /= g; q /= g;
			adj[a].emplace_back(b, p, q);
			adj[b].emplace_back(a, q, p);
		}

		for(int i = 1; i <= N; i++) cnt[i] = mx[i] = 0;
		dfs(1, 0);

		ans = 0;
		ll x = 1;
		for(int i = 2; i <= N; i++) {
			if(sieve[i] != i) continue;
			x = x * pw(i, mx[i]) % MOD;
		}
		calc(1, 0, x);
		printf("%lld\n", ans);
	}
	return 0;
}