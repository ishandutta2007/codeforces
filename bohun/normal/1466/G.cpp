#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define cat(x) cerr << #x << " = " << x << endl
 
using ll = long long;
using namespace std;	

const int N = 1 << 21;
const int P = 1e9 + 7;
const int B = 31;

int bin_pow(int a, int b) {
	int c = 1;
	while (b) {
		if (b & 1)
			c = 1LL * c * a % P;
		a = 1LL * a * a % P;
		b >>= 1;
	}
	return c;
}

int n, m, k, q, f[N], g[N], base[N], pw2[N], c[1 << 17][26], MAX;
string s[30], t, w;

int ha(int l, int r, int *h) {
	return (h[r] - 1LL * base[r - l + 1] * h[l - 1] % P + P) % P;
}

void build(int id) {
	int len = s[id].size();
	for (int i = 0; i < len; ++i)
		g[i + 1] = (1LL * B * g[i] + s[id][i]) % P;
}

int brute(int id) {
	if (id < 0) return 0;
	build(id);
	int ans = 0;
	int e = pw2[k - id];
	
	for (int i = 0; i < s[id].size(); ++i)
		if (i + m <= s[id].size()) {
			//~ cout << i << " " << i + m << " " << ha(i + 1, i + m, g) << " " << ha(1, m, f) << endl;
			if (ha(i + 1, i + m, g) == ha(1, m, f)) {
				ans = (ans + e) % P;
			}
		}
	return ans;
}

ll range(int l, int r, int k) {
	assert(l <= r);
	ll ans = c[r][k];
	if (l > 0) ans = (ans - c[l - 1][k] + P) % P;
	return ans;
}
	
void solve() {
	cin >> k >> w;
	m = w.size();
	
	if (k <= MAX && s[k].size() < m) {
		printf("0\n");
		return;
	}
	
	for (int i = 0; i < m; ++i) 
		f[i + 1] = (1LL * B * f[i] + w[i]) % P;
	
	int r = 0;
	while (s[r].size() < m) r++;
	
	ll ans = 0;
	
	ans = brute(r);
	
	if (r == k) {
		printf("%lld\n", ans);
		return;
	}
	
	build(r);
	
	int S = s[r].size(), u = 0;
	for (int i = 0; i < m; ++i) {
		if (i > 0 && ha(S - i + 1, S, g) != ha(1, i, f)) continue;
		int j = m - i - 1;
		if (j > 0 && ha(1, j, g) != ha(m - j + 1, m, f)) continue;
		int c = w[i] - 'a';
		u = (u + range(r, k - 1, c)) % P;
	}
	assert(k > 0);
	ans = (ans + 1LL * u * pw2[k - 1] % P) % P;
	printf("%lld\n", ans);
}
	
int main() {
	base[0] = 1;
	for (int i = 1; i < N; ++i)
		base[i] = 1LL * base[i - 1] * B % P;
	pw2[0] = 1;
	for (int i = 1; i < N; ++i)
		pw2[i] = 2LL * pw2[i - 1] % P;
		
	cin >> n >> q >> s[0] >> t;
	
	int T = t.size();
	for (int i = 0; i < T; ++i) {
		if (i > 0) {
			for (int j = 0; j < 26; ++j)
				c[i][j] = c[i - 1][j];
		}
		c[i][t[i] - 'a'] = (c[i][t[i] - 'a'] + bin_pow(pw2[i], P - 2)) % P;
	}
	
	for (int i = 0; i < n; ++i) {
		s[i + 1] = s[i] + t[i] + s[i];
		if (s[i + 1].size() > 1000000) {
			MAX = i + 1;
			break;
		}
	}
	while (q--)
		solve();
	return 0;
}