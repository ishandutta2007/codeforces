
#include <bits/stdc++.h>

using namespace std;
#define forn(i, n) for (int i = 0; i < n; i++)
#define re return
#define fi first
#define mp make_pair
#define se second
#define sz(a) (int)a.size()
typedef long long ll;

const ll p = 239, mod = 1e9 + 7;
int n;
ll dp[2][100001], k[100001];

int main() {
	iostream::sync_with_stdio(0);
	//freopen("a.in", "r", stdin);
	//scanf("%d%d%d%d", &n, &m, &q, &k);
	cin >> n;
	forn (i, n) {
		int a;
		cin >> a;
		k[a]++;
	}
	for (int i = 1; i <= 100000; i++) {
		dp[0][i] = max(dp[1][i - 1], dp[0][i - 1]);
		dp[1][i] = dp[0][i - 1] + k[i] * ll(i);
	}
	cout << max(dp[0][100000], dp[1][100000]);
}