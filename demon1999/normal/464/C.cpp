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

const ll mod = (int)1e9 + 7;
ll n, dp[10][100001], len[10][100001];

vector<string> t;
string s;

ll pow1(ll k) {
	ll ans = 1, cc = 10;
	for (ll i = 1; i <= k; i = (i * 2LL)) {
		if (k & i)
			ans = (ans * cc) % mod;
		cc = (cc * cc) % mod;
	}
	re ans;
}

int main() {
	iostream::sync_with_stdio(0), cin.tie(0);
	//freopen("a.in", "r", stdin);
	//freopen(".out", "w", stdout);
	cin >> s;
	cin >> n;
	t.resize(n);
	forn (i, n)
		cin >> t[i];
	forn (i, 10)
		dp[i][n] = i, len[i][n] = 1;
	for (int i = n - 1; i >= 0; i--) {
		forn (j, 10) {
			if (j != int(t[i][0] - '0')) {
				dp[j][i] = dp[j][i + 1];
				len[j][i] = len[j][i + 1];
			} else {
				ll suml = 0;
				for (int ik = sz(t[i]) - 1; ik > 2; ik--) {
					dp[j][i] = (dp[j][i] + pow1(suml) * dp[t[i][ik] - '0'][i + 1]) % mod;
					suml += len[t[i][ik] - '0'][i + 1];
					suml %= (mod - 1);
				}
				len[j][i] = suml;
			}
			//cout << dp[j][i] << " " << len[j][i] << " h ";
		}
		//cout << endl;
	}
	ll suml = 0, ans = 0;
	for (int i = sz(s) - 1; i >= 0; i--) {
		ans = (ans + pow1(suml) * dp[s[i] - '0'][0]) % mod;
		suml += len[s[i] - '0'][0];
		suml %= (mod - 1);
	}
	cout << ans;
	re 0;
}