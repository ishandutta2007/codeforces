#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sz(a) int((a).size())
#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define fore(i, l, r) for (int i = int(l); i < int(r); ++i)

const int INF = 1e9;
const int N = 10010;

int n, m;
string s, t;
int dp[N][N];
int nxt[N];

int main() {
	cin >> s >> t;
	n = sz(s), m = sz(t);
	
	forn(i, n) if (s[i] != '.') {
		int bal = 0;
		nxt[i] = -1;
		fore(j, i, n) {
			if (s[j] == '.') --bal;
			else ++bal;
			if (bal == 0) {
				nxt[i] = j;
				break;
			}
		}
	}
	
	forn(i, n + 1) forn(j, m + 1)
		dp[i][j] = INF;
	dp[0][0] = 0;
	
	forn(i, n) forn(j, m + 1) {
		dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1);
		if (j < m && s[i] == t[j])
			dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j]);
		if (s[i] != '.' && nxt[i] != -1)
			dp[nxt[i] + 1][j] = min(dp[nxt[i] + 1][j], dp[i][j]);
	}
	
	cout << dp[n][m] << endl;
}