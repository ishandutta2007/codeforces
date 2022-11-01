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
const ll inf = 1000 * 1000 * 1000, mod = inf + 7, kkk = 10, ss = 8 * 1024;

int n, a, b, c, d, k;
vector<int> ans;

int main() {
	iostream::sync_with_stdio(0), cin.tie(0);
	//freopen("sum.in", "r", stdin);
	//freopen("sum.out", "w", stdout);
	cin >> n >> k >> a >> b >> c >> d;
	if (n == 4 || k < n + 1) {
		cout << -1;
		re 0;
	}
	ans.push_back(a);
	ans.push_back(c);
	for (int i = 1; i <= n; i++) {
		if (i != a && i != b && i != c && i != d)
			ans.push_back(i);
	}
	ans.push_back(d);
	ans.push_back(b);
	forn (i, n)
		cout << ans[i] << " ";
	cout << "\n";
	swap(ans[0], ans[1]);
	swap(ans[sz(ans) - 1], ans[sz(ans) - 2]);
	forn (i, n)
		cout << ans[i] << " ";
	cout << "\n";
	re 0;
}