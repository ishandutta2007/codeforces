#include <bits/stdc++.h>

using namespace std;
#define forn(i, n) for (ll i = 0; i < n; i++)
#define re return
#define fi first
#define mp make_pair
#define se second
#define sz(a) (int)a.size()
typedef long long ll;

const ll mod = 1e9 + 7, ma = 256 * 1024;
ll seg1[2 * ma], seg2[2 * ma], h[ma], hh[2 * ma];
int n, q, pr[200001], l[200001], r[200001];
vector<int> tp, p, v, e[200001];
ll sk[200001];
vector<ll> ans;
vector<int> num;

ll pow1(ll a, int st) {
	ll ans = 1;
	for (int nu = 0; nu < 30; nu++) {
		if (st & (1 << nu))
			ans = (ans * a) % mod;
		a = (a * a) % mod;
	}
	re ans;
}

void dfs(int nu, ll p) {
	ans.push_back(nu);
	p %= mod;
	h[nu] = (p * sk[nu]) % mod;
	l[nu] = sz(ans) - 1;
	for (int v : e[nu]) {
		pr[v] = nu;
		dfs(v, h[nu]);
	}

	r[nu] = sz(ans);
}

void mul(int nu, ll c) {
	seg2[nu] = (seg2[nu] * c) % mod;
	seg1[nu] = (seg1[nu] * c) % mod;
}

void push(ll nu) {
	mul(2 * nu, seg1[nu]);
	mul(2 * nu + 1, seg1[nu]);
	if (seg1[nu] != 0)
		seg1[nu] = 1;
}

void multip(int nu, int l, int r, int ql, int qr, ll c) {
	if (l >= qr || ql >= r) re;
	if (ql <= l && r <= qr) {
		seg2[nu] = (seg2[nu] * c) % mod;
		seg1[nu] = (seg1[nu] * c) % mod;
		re;
	}
	push(nu);
	int mid = (l + r) /2;
	multip(2 * nu, l, mid, ql, qr, c);
	multip(2 * nu + 1, mid, r, ql, qr, c);
	seg2[nu] = (seg2[2 * nu] + seg2[2 * nu + 1]) % mod;
}

void multip1(int l, int r, ll c) {
	if (l > r) re;
	if (l % 2) {
		hh[l] = (hh[l] * c) % mod;
		multip1(l + 1, r, c);
		re;
	}
	if (r % 2 == 0) {
		hh[r] = (hh[r] * c) % mod;
		multip1(l, r - 1, c);
		re;
	}
	multip1(l / 2, r / 2, c);
	re;
}

ll get_ans1(int nu, int l, int r, int ql, int qr) {
	if (l >= qr || ql >= r) re 0;
	if (ql <= l && r <= qr) {
		re seg2[nu];
	}
	push(nu);
	int mid = (l + r) /2;
	re (get_ans1(2 * nu, l, mid, ql, qr) + get_ans1(2 * nu + 1, mid, r, ql, qr)) % mod;
}

ll get_(int a) {
	if (a == 0) re 1; 
	//cout << pr[a] << "\n";
	a = l[pr[a]] + ma;
	ll ans = 1;
	while (a) {
		ans = (ans * hh[a]) % mod;
		a /= 2;
	}
	//cout << ans << "\n";
	re pow1(ans, mod - 2);
}
int main() {
	iostream::sync_with_stdio(0);
	//freopen("a.in", "r", stdin);
	v.resize(1);
	scanf("%d%d", &v[0], &q);
	//cin >> v[0] >> q;
	tp.resize(q);
	p.resize(q);
	// v.resize(q);
	sk[0] = 1;
	forn (i, q) {
		scanf("%d%d", &tp[i], &p[i]);
		p[i]--;
		if (tp[i] == 1) {
			v.push_back(0);
			scanf("%d", &v[sz(v) - 1]);
			e[p[i]].push_back(sz(v) - 1);
			sk[p[i]]++;
			sk[sz(v) - 1] = 1;
			p[i] = sz(v) - 1;
		}
	}

	dfs(0, 1);
	forn (i, 2 * ma) {
		seg1[i] = 1;
		hh[i] = 1;
	}
	forn (i, sz(v)) {
		seg2[i + ma] = ll(v[ans[i]]) * h[ans[i]] % mod;
		hh[i + ma] = h[ans[i]];
	}

	for (int j = ma - 1; j; j--) {
		seg2[j] = (seg2[2 * j] + seg2[2 * j + 1]) % mod;
	}
	ans.resize(0);
	for (int i = q - 1; i >= 0; i--) {
		if (tp[i] == 1) {
			int pos = l[p[i]] + ma;
			multip(1, ma, 2 * ma, pos, pos + 1, 0);
			int nu = pr[p[i]];
			sk[nu]--;
			ll c=  ll(sk[nu]) * pow1(sk[nu] + 1, mod - 2) % mod;
			multip(1, ma, 2 * ma, l[nu] + ma, r[nu] + ma, c);
			multip1(l[nu] + ma, r[nu] + ma - 1, c);
		} else {
			ans.push_back(get_ans1(1, ma, 2 * ma, l[p[i]] + ma, r[p[i]] + ma) * get_(p[i]));
		}
	}
	reverse(ans.begin(), ans.end());
	forn (i, sz(ans))
		cout << ans[i] % mod << "\n";
}