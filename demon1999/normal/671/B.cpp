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
const ll inf = 1000 * 1000 * 1000, mod = inf + 7, ma = 1024 * 128;

ll n, k;
vector<ll> a;

int main() {
	iostream::sync_with_stdio(0), cin.tie(0);
	//freopen("sum.in", "r", stdin);
	//freopen("sum.out", "w", stdout);
	cin >> n >> k;
	a.resize(n);
	ll sum = 0;
	forn (i, n) {
		cin >> a[i];
		sum += a[i];
	}
	ll kk = sum % n;
	sum /= n;
	sort(a.begin(), a.end());
	ll k1 = k, p = 1, mi = sum, ma = sum;
	if (kk) ma++;
	forn (i, n) {
		ll c = sum - a[i];
		if (a[i] == sum) {
			mi = sum;
			break;
		}
		if (i < n - 1) c = min(c, a[i + 1] - a[i]);
		if (c < 0) break;
		if (k1 >= p * c) {
			k1 -= p * c;
			if (i + 1 < n)mi = min(a[i + 1], sum);
			else mi = sum;
		}
		else {
			mi = a[i] + k1 / p;
			break; 
		}
		p++;
	}
	reverse(a.begin(), a.end());
	k1 = k, p = 1;
	forn (i, n) {
		ll c = a[i] - sum;
		if (a[i] == sum) {
			ma = sum;
			break;
		}
		if (i < n - 1) c = min(c, a[i] - a[i + 1]);
		if (c < 0) break;
		if (k1 >= p * c) {
			//cout << "HEH\n";
			k1 -= p * c;
			ma = sum;
			if (i < n - 1) ma = max(ma, a[i + 1]);
		}
		else {
			ma = a[i] - k1 / p;
			break;
		}
		p++;
	}
	//cout << ma << " " << mi << " " << sum << endl;
	if (ma == sum && kk) ma++; 
	cout << ma - mi;
	re 0;
}