#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(x) (int) x.size()
#define cat(x) cerr << #x << " = " << x << endl
#define all(x) x.begin(), x.end()
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)

using ll = long long;
using ld = long double;
using namespace std;	

int n;
char s[300005];

int main() {
	int t;
	scanf ("%d", &t);
	while (t--) {
		scanf ("%d%s", &n, s);
		int ans = 0;
		int ri = 0, le = 0;
		rep(i, 0, n - 1) {
			if (s[i] == '>') ri++;
			if (s[i] == '<') le++;
		}
		rep(i, 0, n - 1) {
			int j = (i - 1 + n) % n;
			if (s[i] == '-' || s[j] == '-' || !ri || !le) ans++;
		}
		printf ("%d\n", ans);
	}
	return 0;
}