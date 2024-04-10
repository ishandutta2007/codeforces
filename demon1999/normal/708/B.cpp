#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < n; i++)
#define sz(a) (int)a.size()
#define re return
#define fi first
#define se second
#define mp(a, b) make_pair(a, b)

typedef long long ll;
typedef vector<int> vi;
typedef long double ld;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

string s;

ll a, b, c, d, p1 = -1, p2 = -1;
int main() {
	iostream::sync_with_stdio(0), cin.tie(0);
	//freopen("a.in", "r", stdin);
	//freopen(".out", "w", stdout);
	cin >> a >> b >> c >> d;
	for (ll i = 0; i * (i - 1LL) <= 2LL * a; i++)
		if (i * (i - 1) == 2LL * a) {
			p1 = i;
			break;
		}
	for (ll i = 0; i * (i - 1LL) <= 2LL * d; i++)
		if (i * (i - 1) == 2LL * d) {
			p2 = i;
			break;
		}
	if (p1 == 0 && p2 == 0) {
		if (b + c != 0) {
			p1 = p2 = 1;
		}
		else {
			cout << "1\n";
			re 0;
		}
	}
	if (p1 == 0) {
		if (b + c != 0)
			p1 = 1;
	}
	if (p2 == 0)
		if (b + c != 0)
			p2 = 1;
	if (p1 == -1 || p2 == -1 || b + c != p1 * p2) {
		cout << "Impossible";
		re 0;
	}
	string ans = "";
	if (p1 == 0 || p2 == 0) {
		forn (i, p1) ans += "0";
		forn (j, p2) ans += "1";
		cout << ans << "\n";
		re 0;
	}
	forn (j, b / p2) {
		ans += "0";
		p1--;
	}
	ll kk = p2 - b % p2;
	forn (i, kk)
		ans += "1";
	if (p1) {
		ans += "0";
		p1--;
	}
	forn (i, p2 - kk)
		ans += "1";
	forn (i, p1)
		ans += "0";
	cout << ans << "\n";
	re 0;
}