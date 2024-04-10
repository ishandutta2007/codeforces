
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
int n, k, nm = 0;
int go[26][1000000], dp[1000000], dp1[1000000];

void dfs(int nu) {
	dp1[nu] = 0;
	bool ok = true;
	forn (i, 26) {
		if (go[i][nu] != -1) {
			ok = false;
			dfs(go[i][nu]);
			if (dp[go[i][nu]] == 0)
				dp[nu] = 1;
			if (dp1[go[i][nu]] == 0)
				dp1[nu] = 1;
		}
	}
	if (ok)
		dp1[nu] = 1;
}

int main() {
	iostream::sync_with_stdio(0);
	//freopen("a.in", "r", stdin);
	//scanf("%d%d%d%d", &n, &m, &q, &k);
	cin >> n >> k;
	forn (i, 26)
		go[i][0] = -1;
	forn (i, n) {
		string s;
		cin >> s;
		int we = 0;
		forn(i, sz(s)) {
			if (go[s[i] - 'a'][we] == -1) {
				nm++;
				go[s[i] - 'a'][we] = nm;
				forn (i, 26)
					go[i][nm] = -1;
			}
			we = go[s[i] - 'a'][we];
		}
	}
	dfs(0);
	/*forn (i, nm + 1) {
		cout << dp[i] << " " << dp1[i] << "\n";
	}*/
	if (dp[0] == 1) {
		if (dp1[0])
			cout << "First";
		else {
			if (k % 2) cout << "First";
			else
				cout << "Second";
		}
	} else
		cout << "Second";
}