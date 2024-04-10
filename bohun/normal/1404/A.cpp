#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ss(x) (int) x.size()
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)

using ll = long long;
using namespace std;

char s[300005];
int cnt[300005][3];

int main() {
	int T, n, k;
	scanf ("%d", &T);
	while (T--) {
		scanf ("%d%d%s", &n, &k, s);
		rep(i, 0, n - 1) rep(j, 0, 2) cnt[i][j] = 0;
		rep(i, 0, n - 1) {
			if (s[i] == '0') cnt[i % k][0]++;
			if (s[i] == '1') cnt[i % k][1]++;
			if (s[i] == '?') cnt[i % k][2]++;
		}
		bool bad = false;
		int x = 0, y = 0, z = 0;
		for (int i = 0; i < k; ++i) {
			bad |= cnt[i][0] && cnt[i][1];
			if (cnt[i][0]) x++;
			else if (cnt[i][1]) y++;
			else z++;
		}
		if (x > y) swap(x, y);
		if (!bad && x + z >= y) printf ("YES\n");
		else printf ("NO\n");
	}
	return 0;
}