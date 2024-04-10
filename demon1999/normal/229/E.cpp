//#include "grader.h"
#include <bits/stdc++.h>


using namespace std;

#define re return
#define sz(a) (int)a.size()
#define mp(a, b) make_pair(a, b)
#define fi first
#define se second
#define re return
#define forn(i, n) for (int i = 0; i < int(n); i++)


typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long double ld;
//const int ma = 128 * 1024, mal = 8;
const ll mod = ll(1e9) + 7, bub = 1000;
int n, m, a[5000], cnt[1000], ct[1000], cn[1000];
long double  dp[1000][1001], c[1001][1001];
vector<ll> h;
vector<pair<int, int> > qq;
vector<int> must, can;

long double ans = 1;

long double getc(int n, int k) {
	if (n <= k)
		re 1;
	re c[n][k];
} 
int main() {
	iostream::sync_with_stdio(0);
	//freopen("a.in", "r", stdin);
	cin >> n >> m;
	c[0][0] = 1;
	for (int i = 1; i < 1001; i++) {
		for (int j = 0; j <= i; j++) {
			c[i][j] = c[i - 1][j] * (ld(i - j)) / (ld(i));
		}
		c[i][i] = 1;
	}
	forn (i, m) {
		int k;
		cin >> k;
		forn (j, k) {
			int a;
			cin >> a;
			qq.push_back(mp(a, i));
		}
		ct[i] = k;

	}
	sort(qq.begin(), qq.end());
	reverse(qq.begin(), qq.end());
	forn (i, sz(qq)) {
		if (qq[i].fi > qq[n - 1].fi) {
			must.push_back(qq[i].se);
			cnt[qq[i].se]++;
		}
		if (qq[i].fi == qq[n - 1].fi) {
			can.push_back(qq[i].se);
			cn[qq[i].se] = 1;
		}
	}

	forn (i, m) {
		if (!cn[i]) {
			//cout << i << " " << ct[i] << " " << cnt[i] << endl;
			ans *= getc(ct[i], cnt[i]);
		}
	}
	n -= sz(must);
	dp[0][0] = getc(ct[can[0]], cnt[can[0]]);
	dp[0][1] = getc(ct[can[0]], cnt[can[0]] + 1);
	//cout << ct[can[0]] << " " << cnt[can[0]] << endl;
	for (int i = 1; i < sz(can); i++) {
		forn (j, n + 1) {
			dp[i][j] = dp[i - 1][j] * getc(ct[can[i]], cnt[can[i]]);
			if (j)
				dp[i][j] += dp[i - 1][j - 1] * getc(ct[can[i]], cnt[can[i]] + 1);
		}
	}
	ans *= dp[sz(can) - 1][n];
	ans *= getc(sz(can), n);
	cout.precision(30);
	cout << ans;
}