#include <bits/stdc++.h>

using namespace std;
#define forn(i, n) for (ll i = 0; i < n; i++)
#define re return
#define fi first
#define mp make_pair
#define se second
#define sz(a) (int)a.size()
typedef long long ll;

const ll mod = 1e9 + 7, ma1 = 8, ma = 2 * 16 * 1024;

ll n, k, ans;
vector<ll> pw;
vector<ll> a;
map<ll, ll> qq;

int main() {
	iostream::sync_with_stdio(0);
	//freopen("a.in", "r", stdin);
	//cin >> n >> k;
	scanf("%I64d%I64d", &n, &k);
	pw.push_back(1);
	if (abs(k) > 1) {
		ll p = k;
		while (abs(k) <= ll(1e16)) {
			pw.push_back(k);
			k *= p;
		}
	} else {
		if (k < 0)
			pw.push_back(-1);
	}
	a.resize(n);
	qq[0] = 1;
	ll sum = 0;
	forn (i, n) {
		scanf("%I64d", &a[i]);
		sum += a[i];
		for (ll v : pw)
			ans += qq[sum - v];
		qq[sum]++;
	}
	printf("%I64d", ans);
	//cout << ans;
}