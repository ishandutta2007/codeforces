#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep2(i, j, n) for (LL i = j; i <= n; ++i)
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
 
using namespace std;

const int nax = 1100;
const LL INF = 1e18 + 2;

void add(LL &a, LL b) {
	a += b;
	a = min(a, INF);
}

int n, m;
LL k;
char s[nax];

vector <string> v;

LL dp[nax][nax];
LL dp2[nax][nax];

LL solve(string t) {
	rep(i, 0, n)
		rep(j, 0, m)
			dp[i][j] = dp2[i][j] = 0;
			
	int sz = ss(t);
	t = '#' + t;
	dp[0][0] = 1;
	
	rep(i, 0, n - 1) {
		int len = 0;
		while (len <= sz && i + 1 + len <= n && s[i + 1 + len] == t[1 + len]) len++;
		len++;
		
		if (len <= sz && len <= n) {
			if (s[i + len] > t[len])
				rep(j, 0, m) {
					add(dp[i + len][j + 1], dp[i][j]);
					add(dp2[i + len][j + 1], dp[i][j]);
				}
		}
		else if (len == sz + 1) {
			rep(j, 0, m) {
				add(dp[i + len - 1][j + 1], dp[i][j]);
				add(dp2[i + len - 1][j + 1], dp[i][j]);
			}
		}
		rep(j, 1, m) {
			add(dp[i + 1][j], dp2[i][j]);
			add(dp2[i + 1][j], dp2[i][j]);
		}
	}
	return dp[n][m];
}			
	
 
int main() {
	scanf ("%d%d%lld", &n, &m, &k);
	scanf ("%s", s + 1);
	
	rep(i, 1, n) {
		string w = "";
		rep(j, i, n) {
			w.pb(s[j]);
			v.pb(w);
		}
	}
	
	sort(v.begin(), v.end());
	
	int l = 0, r = ss(v) - 1;
	while (l < r) {
		int m = (l + r + 1) / 2;
		if (solve(v[m]) < k) r = m - 1;
		else l = m;
	}
	cout << v[l];
	
	return 0;
}