#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int mod = 998244353;

const int N = 3007;
int dp[N][N];

string s, t;

inline bool good(int x) {
	return (x >= 0 && x < t.size());
}

void recalc(int a, int i, int len) {

	int Q = dp[i][len];

	if (good(i-1) && good(i+len-1) && t[i-1] == s[a]) {
		dp[i-1][len+1] += dp[i][len];
		dp[i-1][len+1] %= mod;
	}



	if (good(i) && good(i+len) && t[i+len] == s[a]) {
		dp[i][len+1] += dp[i][len];
		dp[i][len+1] %= mod;
	}

	if (good(i) && !good(i+len)) {
		dp[i][len] *= 2;
		dp[i][len] %= mod;
	}

	if (i == t.size() && len == 0) {

		ll kek = dp[i][len];
		kek *= 3;

		dp[i][len] = (kek%mod);
	}

	dp[i][len] -= Q;
	if (dp[i][len] < 0) dp[i][len] += mod;

}

int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> s >> t;

	for (int i = 0; i <= t.size(); ++i) {
		dp[i][0] = 1;
	}

	int ans = 0;

	for (int i = 0; i < s.size(); ++i) {
		for (int len = t.size(); len >= 0; len--) {

			recalc(i, 0, len);
			if (len != t.size()) recalc(i, t.size() - len, len);

			if (i == len) {
				for (int j = 0; j <= t.size(); ++j) {
					if (j != 0 && j + len != t.size()) recalc(i, j, len);
				}
			}
		}

		ans += dp[0][t.size()];
		ans %= mod;

	}

	cout << ans;

}