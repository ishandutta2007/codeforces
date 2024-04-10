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

ll d, k, a, b, t;


ll ans(ll kk) {
	ll an = (d - kk) * b + kk * a + (max((kk - 1LL), 0LL) / k) * t;
	re an;
}

int main() {
	iostream::sync_with_stdio(0), cin.tie(0);
	//freopen("a.in", "r", stdin);
	//freopen(".out", "w", stdout);
	cin >> d >> k >> a >> b >> t;
	ll an = min(d * b, ans(d)), ma = d / k;
	forn (i, min(2LL, ma))
		an = min(an, ans(ll(i) * k));
	an = min(an, ans(ma * k));
	cout << an;
 	re 0;
}