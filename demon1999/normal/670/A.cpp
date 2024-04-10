

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
int n, ans, mi = 1000000, ma = 0;

int main() {
	//iostream::sync_with_stdio(0), cin.tie(0);
	//freopen("sum.in", "r", stdin);
	//freopen("sumb.out", "w", stdout);
	cin >> n;
	ans = ((n - 1) / 7) * 2 + max((n - 1) % 7 - 4, 0);
	int nu = (n - 1) % 7;
	forn (i, 7) {
		ma = max(ans, ma);
		mi = min(ans, mi);
		if (i >= 5) {
			ans--;
		}
		nu = (nu + 1) % 7;
		if (nu >= 5)
			ans++;
	}	
	cout << mi << " " << ma;
	re 0;
}