#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define all(x) x.begin(), x.end()
 
using namespace std;

const int nax = 2e5 + 100;
const int mod = 1e9 + 7;

int n;
int a[nax];

void solve() {
	scanf ("%d", &n);
	rep(i, 1, n) scanf ("%d", a + i);
	ll dif = -1e18;
	ll prev = -1e18;
	rep(i, 1, n) {
		dif = max(dif, (ll) prev - a[i]);
		prev = max(prev, (ll) a[i]);
	}
	//cat(dif);
	rep(b, 0, 40) if ((1LL << b) - 1 >= dif) {
		printf ("%d\n", b);
		return;
	}
}
int main() {
	int T;
	scanf ("%d", &T);
	while (T--) solve();
	return 0;
}