#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(x) (int) x.size()
#define cat(x) cerr << #x << " = " << x << endl
#define all(x) x.begin(), x.end()
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
 
using ll = long long;
using ld = long double;
using namespace std;		
 
const int N = 3e5 + 5;
const int MOD = 998244353; 

void addself(ll &a, ll b) {
	a = (a + b + MOD) % MOD;
}

ll bin_pow(ll a, ll b) {
	ll c = 1;
	while (b) {
		if (b & 1) c = c * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return c;
} 
 
vector <int> add[N], rem[N];
int cnt, all, n, m, l[N], r[N], id[N], space, p[N], q[N], who[N];
bool in[N];
ll fac[N], rev[N], ways[N];

ll C(int x, int y) {
	if (x < 0 || y < 0 || x < y) return 0;
	return fac[x] * rev[x - y] % MOD * rev[y] % MOD;
}

void qq(int x, ll mask, int counter) {
	if (x == m) {
		int pop = __builtin_popcountll(mask);
		rep(i, 0, 40)
			addself(ways[i], counter * C(cnt - pop, i - pop));
		return;
	}
	if (in[p[x]] && in[q[x]])
		qq(x + 1, mask | (1LL << id[p[x]]) | (1LL << id[q[x]]), MOD - counter);
	qq(x + 1, mask, counter);
}
 
int main() {
	fac[0] = rev[0] = 1;
	rep(i, 1, N - 1) {
		fac[i] = fac[i - 1] * i % MOD;
		rev[i] = bin_pow(fac[i], MOD - 2);
	}
	
	fill(id, id + N, -1);
	scanf ("%d%d", &n, &m);
	rep(i, 1, n) {
		scanf ("%d%d", l + i, r + i);
		add[l[i]].pb(i);
		rem[r[i] + 1].pb(i);
	}
	
	rep(i, 0, m - 1) {
		scanf ("%d%d", p + i, q + i);
		if (id[p[i]] == -1) {
			who[space] = p[i];
			id[p[i]] = space++;
		}
		if (id[q[i]] == -1) {
			who[space] = q[i];
			id[q[i]] = space++;
		}
	}
	
	ll ans = 0;
	ways[0] = 1;
	rep(i, 1, n) {
		bool flag = false;
		for (auto x : add[i]) {
			all++;
			in[x] = true;
			if (id[x] != -1)
				flag = true;
		}
		for (auto x : rem[i]) {
			all--;
			in[x] = false;
			if (id[x] != -1)
				flag = true;
		}
		
		if (flag) {
			cnt = 0;
			rep(j, 0, space - 1)
				cnt += in[who[j]];
			fill(ways, ways + 41, 0);
			qq(0, 0, 1);
		}
		rep(j, 0, 40)
			addself(ans, ways[j] * C(all - cnt, i - j));
	}
	printf ("%lld\n", ans);
	return 0;
}