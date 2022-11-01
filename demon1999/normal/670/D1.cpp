

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (ll i = 0; i < n; i++)
#define re return
#define sz(a) (int)a.size()
#define fi first
#define se second
#define mp(a, b) make_pair(a, b)
typedef long long ll;
typedef double ld;
typedef vector<ll> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int inf = 1000000000, ss = 8 * 1024;
ll n, k;
vector<ll> a, b;

bool ok(ll q) {
	ll sum = 0;
	forn (i, n) {
		sum += max(0LL, a[i] * q - b[i]);
	}
	if (sum <= k) re true;
	re false;
} 
int main() {
	iostream::sync_with_stdio(0), cin.tie(0);
	//freopen("sum.in", "r", stdin);
	//freopen("sumb.out", "w", stdout);
	cin >> n >> k;
	a.resize(n);
	b.resize(n);
	forn (i, n) cin >> a[i];
	forn (i, n) cin >> b[i];
	ll l = 0, r = 1000 * 1000 * 1000 + 2;
	while (r - l > 1) {
		ll mid = (l + r) / 2;
		if (ok(mid)) l = mid;
		else r = mid;
	}
	cout << l;
	re 0;
}