#include <bits/stdc++.h>
using namespace std;

#define sz(x) ((int) x.size())
#define all(x) x.begin(), x.end()

using ll = long long;

const char nl = '\n';
const int MX = 5000 + 10;

const int MOD = 998244353;

int add(int a, int b) {
	a += b;
	if (a >= MOD) a -= MOD;
	if (a < 0) a += MOD;
	return a;
}
int mul(int a, int b) {
	return (ll) a * b % MOD;
}

int pw(int a, int b) {
	if(b == 0) return 1;
	int r = pw(a, b/2);
	r = mul(r,r);
	if(b % 2 == 1) r = mul(r, a);
	return r;
}

int fact[MX], finv[MX];
int choose(int a, int b) {
	if(a < b) return 0;
	return mul(fact[a], mul(finv[a-b], finv[b]));
}

int n, a[MX];
int cnt[MX];

int dp[MX][MX];
/*
	dp[i][j] = after processing all elements <= i, I have placed the first j even positions and the first j odd positions
	
	I have placed 2j for sure
	sum(cnts <= i) - 2*j that are 'free'

  */

void debug() {
	for(int x = 1; x <= n; x++) {
		cerr << x << ":";
		for(int p = 0; p <= n/2; p++) {
			cerr << " " << dp[x][p] ;
		}
		cerr << nl;
	}
}

void clear() {
	fill_n(cnt, n+1, 0);
	for(int i = 0; i <= n; i++) {
		fill_n(dp[i], n+1, 0);
	}
}

const int MAXN = MX;
int sec[MAXN];
void solve() {
	cin >> n;
	clear();
	int sz = 0;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		++cnt[a[i]];
		sec[sz++] = a[i];
	}
	sort(sec, sec + sz);
	sz = unique(sec, sec + sz) - sec;
	if (cnt[sec[sz-1]] > 1) {
		cout << "0\n";
		return;
	}

	dp[sz-1][1] = 1;
	int sm = cnt[sec[sz-1]];
	for (int i = sz-2; ~i; i--) {
		int cc = cnt[sec[i]];
		for (int picked = 1; picked <= sm; picked++)
			if (dp[i+1][picked]) {
				int rem = 2*picked - sm;
				if (rem - 1 >= cc - 1) {  // pick
					dp[i][picked + 1]
						= add(dp[i][picked + 1],
							1ll*choose(rem-1, cc-1)*dp[i+1][picked]%MOD);
				}
				if (picked < n/2 && rem - 1 >= cc - 1) {
					dp[i][picked] =
						add(dp[i][picked],
						   1ll * choose(rem-1, cc) * dp[i+1][picked]%MOD);
				}
				else if (picked == n/2 && rem >= cc - 1) {
					dp[i][picked] =
						add(dp[i][picked],
						   1ll * choose(rem, cc) * dp[i+1][picked]%MOD);

				}
			}
		sm += cc;
	}


	cout << dp[0][n / 2] << "\n";
}

int main() {

	fact[0] = finv[0] = 1;
	for(int i = 1; i < MX; i++) {
		fact[i] = mul(i, fact[i-1]);
		finv[i] = pw(fact[i], MOD-2);
	}

	int t;
	cin >> t;
	while(t--)
		solve();

	return 0;
}