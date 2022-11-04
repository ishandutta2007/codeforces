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
typedef unsigned long long ull;
const ll ma = 128 * 1024;

int n, k, p, dp[20001][50];
vector<int> a;

int main() {
	iostream::sync_with_stdio(0);
	cin >> n >> k >> p;
	a.resize(n);
	forn (i, n) {
		cin >> a[i];
		dp[i + 1][0] = (dp[i][0] + a[i]) % p;
	}
	for (int i = 1; i < k; i++) {
		dp[0][i] = -int(1e9);
	}
	vector<int> pos(100, 0);
	dp[0][0] = -p * int(1e7);
	forn (j, n) {
		//cout << dp[j + 1][0] << " ";
		for (int i = 1; i < k; i++) {
			int sum = 0;
			dp[j + 1][i] = -int(1e9);
			for (int pr : pos) {
				sum = ((dp[j + 1][0] - dp[pr][0]) % p + p) % p;
				dp[j + 1][i] = max(dp[j + 1][i], dp[pr][i - 1] + sum);
			}
			//cout << dp[j + 1][i] << " ";
		}
		//cout << "\n";
		pos[dp[j + 1][0]] = j + 1;
	}
	cout << dp[n][k - 1];
}