#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < n; i++)
#define sz(a) (int)a.size()
#define re return
#define x first
#define y second
#define mp(a, b) make_pair(a, b)

typedef long long ll;
typedef vector<int> vi;
typedef long double ld;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define fi first
#define se second

ll n, m, ans = 0, sm = 0, sum, c[1000100], k;

ll kk(int nu) {
	int nu1 = (nu + n - 1) % n, nu2 = (nu + 1) % n;
	re c[nu] * (c[nu1] + c[nu2]);
}
int main() {
	iostream::sync_with_stdio(0), cin.tie(0);
	//freopen("a.in", "r", stdin);
	//freopen(".out", "w", stdout);
	cin >> n >> m;
	forn (i, n) {
		cin >> c[i];
		sum += c[i];
	}
	vector<ll> k(2 * n, 0), ko(2 * n, 0);
	forn (i, m) {
		cin >> k[i];
		k[i]--;
		ko[k[i]] = 1;
	}
	ll sum = 0, supr = 0;
	forn (i, n) {
		if (ko[i]) {
			sm += supr * c[i];
			sum += c[i];
			supr += c[i];
			continue;
		}
		ll smm = sum;
		int fr = (i - 1 + n) % n;
		if (fr < i)
			smm += (1LL - ko[fr]) * c[fr];
		fr = (i + 1) % n;
		if (fr < i)
			smm += (1LL - ko[fr]) * c[fr];
		sm += smm * c[i];
		supr += c[i];
	}
	cout << sm << "\n";
	re 0;
}