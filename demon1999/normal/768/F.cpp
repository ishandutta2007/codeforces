#include <bits/stdc++.h>

using namespace std;
#define forn(i, n) for (ll i = 0; i < n; i++)
#define re return
#define fi first
#define mp make_pair
#define se second
#define sz(a) (int)a.size()
typedef long long ll;

const ll MAXN = 5 * 100 * 1000,/* ma = 128 * 1024,*/ mod = 1000 * 1000 * 1000 + 7;
ll f, w, h, ans, sum, fc[300001], bfc[300001];

ll pow1(ll k, int pw) {
	if (pw == 0) re 1;
	if (pw == 1) re k;
	ll ans = pow1(k, pw / 2);
	ans = (ans * ans) % mod;
	if (pw % 2)
		ans = (ans * k) % mod;
	re ans;
}

ll getc(ll n, ll k) {
    if(k==n && n==0)re 1;
	if (k <= 0 || n < k || n <= 0)
		re 0;

	re (((fc[n - 1] * bfc[k - 1]) % mod) * bfc[n - k]) % mod;
}

int main() {
	iostream::sync_with_stdio(0);
	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);
	cin >> w >> f >> h;
	fc[0] = 1;
	bfc[0] = pow1(1, mod - 2);
	for (ll i = 1; i <= 200000; i++) {
		fc[i] = (fc[i - 1] * i) % mod;
		bfc[i] = pow1(fc[i], mod - 2);
	}
	forn (i, f + 1) {
		sum = (sum + getc(f, i) * (((getc(w, i - 1) + getc(w, i + 1) + 2LL * getc(w, i))) % mod)) % mod;
		ans = (ans + getc(f - h * i, i) * (((getc(w, i - 1) + getc(w, i + 1) + 2LL * getc(w, i))) % mod)) % mod;

	}
	//cout << sum << "\n";
	//cout << ans << "\n";
	cout << (ans * pow1(sum, mod - 2)) % mod;
}