#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define per(i, a, b) for (int i = b; i >= a; --i)
#define all(x) x.begin(), x.end()
 
using ll = long long;
using namespace std;

int n, m;
char s[1005][1005];

void solve() {
	scanf("%d%d", &n, &m);
	rep(i, 1, n) scanf("%s", s[i] + 1);
	if (m % 2 == 1) {
		puts("YES");
		rep(i, 1, m + 1)
			printf ("%d ", i % 2 ? 1 : 2);
		puts("");
		return;
	}
	rep(i, 1, n) rep(j, 1, n)
		if (i != j && s[i][j] == s[j][i]) {
			puts("YES");
			rep(k, 1, m + 1)
				printf("%d ", k % 2 ? i : j);
			puts("");
			return;
		}
	rep(i, 1, n) rep(j, 1, n) rep(k, 1, n) {
		if (i == j || i == k || k == j) continue;
		if (s[i][j] == s[j][k]) {
			vector<int> s, e;
			rep(g, 1, (m - 2) / 2) {
				s.pb(g % 2 ? j : i);
				e.pb(g % 2 ? j : k);
			}
			reverse(all(s));
			puts("YES");
			for (auto x : s) printf("%d ", x);
			printf("%d %d %d ", i, j, k);
			for (auto x : e) printf("%d ", x);
			puts("");
			return;
		}
	}
	printf("NO\n");
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
	return 0;
}