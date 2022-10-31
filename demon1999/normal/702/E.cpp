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

ll n, k, pr[38][200000], sum[38][200000], mi[38][200000];

int main() {
	iostream::sync_with_stdio(0), cin.tie(0);
	//freopen("a.in", "r", stdin);
	//freopen(".out", "w", stdout);
	cin >> n >> k;
	forn (i, n) {
		cin >> pr[0][i];
	}
	forn (i, n) {
		cin >> sum[0][i];
		mi[0][i] = sum[0][i];
	}
	for (ll i = 1; i < 38; i++) {
		forn (j, n) {
			pr[i][j] = pr[i - 1][pr[i - 1][j]];
			sum[i][j] = sum[i - 1][pr[i - 1][j]] + sum[i - 1][j];
			mi[i][j] = min(mi[i - 1][pr[i - 1][j]], mi[i - 1][j]);
			//cout << pr[i][j] << " " << sum[i][j] << " " << mi[i][j] << " hh ";
		}
		//cout << endl;
	}
	 
	forn (j, n) {
		ll sm = 0, mi1 = 100000001, num = j;
		for (ll i = 37; i >= 0; i--) {
			if (k & (1LL << i)) {
				sm += sum[i][num];
				mi1 = min(mi1, mi[i][num]);
				num = pr[i][num];
			}
		}
		cout << sm << " " << mi1 << "\n";
	}
 	re 0;
}