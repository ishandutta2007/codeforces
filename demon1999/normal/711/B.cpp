#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < n; i++)
#define sz(a) (int)a.size()
#define re return
#define fi first
#define se second
#define mp(a, b) make_pair(a, b)
#define mp1(a, b, c, d) mp(mp(a, b), mp(c, d))

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef long double ld;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int szz = 10, buben = 3500000;

ll n, sum, a[600][600];

int main() {
	iostream::sync_with_stdio(0), cin.tie(0);
	//freopen("a.in", "r", stdin);
	//freopen(".out", "w", stdout);
	cin >> n;
	if (n == 1) {
		cout << "1\n";
		re 0;
	}
	int nu = 0, y;
	forn (i, n)
		forn (j, n) {
			cin >> a[i][j];
			if (a[i][j] == 0) {
				nu = i;
				y = j;
			}
		}
	if (nu == 0) {
		forn (i, n) sum += a[1][i] - a[0][i];
	}
	else
		forn (i, n) sum += a[0][i] - a[nu][i];
	if (sum <= 0) {
		cout << -1;
		re 0;
	}
	a[nu][y] = sum;
	bool ok = true;
	ll sm = 0;
	forn (i, n) sm += a[0][i];
	forn (i, n) {
		ll sm1 = 0, sm2 = 0;
		forn (j, n) {
			sm1 += a[i][j];
			sm2 += a[j][i];
		}
		if (sm1 != sm || sm2 != sm) ok = false;
	}
	ll sm1 = 0, sm2 = 0;
	forn (i, n)
		sm1 += a[i][i], sm2 += a[i][n - 1 - i];
	if (sm1 != sm || sm2 != sm) ok = false;
	if (ok) 
		cout << sum;
	else
		cout << -1;
	re 0;
}