
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
using namespace std;

#define forn(i, n) for (int i = 0; i < n; i++)
#define sz(a) (int)a.size()
#define re return
#define fi first
#define se second
#define mp(a, b) make_pair(a, b)

typedef vector<int> vi;
typedef long double ld;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
#define fi first
#define se second

const ll sz1 = (int)1e5, ma = 2 * 128 * 1024, ma1 = 16;

ll ans = 0, c[10 * sz1], k[10 * sz1];

vector<pair<int, int> > cq;
int main() {
	iostream::sync_with_stdio(0), cin.tie(0);
	//freopen("a.in", "r", stdin);
	int n, q;
	cin >> n >> q;
	int j = 0;
	forn (i, q) {
		ll ck, t, x;
		cin >> ck >> x;
		x--;
		if (ck == 1) {
			cq.push_back(mp(c[x] + 1, x));
			c[x]++;
			ans++;
		}
		if (ck == 2) {
			ans -= (c[x] - k[x]);
			k[x] = c[x];
		}
		if (ck == 3) {
			for (; j <= x; j++) {
				if (k[cq[j].se] < cq[j].fi) {
					ans--;
					k[cq[j].se]++;
				}
			}
		}
		cout << ans << "\n";
	}
	re 0;
}