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

const int N = 4005;

int T, n, cnt[4];
char s[N], t[N]; 
vector <int> ans[2];

void add(char *r, int sign) {
	for (int i = 1; i <= n; i += 2)
		cnt[2 * (r[i] - '0') + r[i + 1] - '0'] += sign;
}

void rev(char *r, int e, int len) {
	if (len == 2 && r[1] == r[2]) return;
	ans[e].pb(len);
	reverse(r + 1, r + len + 1);
}	

void solve() {
	scanf ("%s%s", s + 1, t + 1);
	n = strlen(s + 1);
	memset(cnt, 0, sizeof cnt);
	add(s, 1);
	add(t, -1);
	if (cnt[0] != 0 || cnt[3] != 0) {
		puts("-1");
		return;
	}
	ans[0].clear(); ans[1].clear();
	for (int i = n - 1; 1 <= i; i -= 2) {
		if (s[i] == t[i] && s[i + 1] == t[i + 1]) continue;
		bool suc = 0;
		if (s[1] == t[i + 1] && s[2] == t[i]) {
			rev(s, 0, i + 1);
			continue;
		}
		if (t[1] == s[i + 1] && t[2] == s[i]) {
			rev(t, 1, i + 1);
			continue;
		}
		for (int j = 1; j < i; j += 2) {
			if (t[j] == s[i] && t[j + 1] == s[i + 1]) {
				suc = 1;
				rev(t, 1, j + 1);
				rev(t, 1, i + 1);
				break;
			}
		}
		if (suc) continue;
		for (int j = 1; j < i; j += 2) {
			if (s[j] == t[i] && s[j + 1] == t[i + 1]) {
				suc = 1;
				rev(s, 0, j + 1);
				rev(s, 0, i + 1);
				break;
			}
		}
		if (suc) continue;
		assert(s[i] != s[i + 1]);
		assert(t[i] != t[i + 1]);
		vector <int> ocur;
		for (int j = 1; j <= i; j += 2)
			if (s[j] != s[j + 1]) 
				ocur.pb(j);
		assert(sz(ocur));
		int g = rand() % sz(ocur);
		rev(s, 0, ocur[g] + 1);
		rev(s, 0, 2);
		rev(s, 0, i + 1);
	}
	reverse(ans[1].begin(), ans[1].end());
	ans[0].insert(ans[0].end(), ans[1].begin(), ans[1].end());
	printf ("%d\n", sz(ans[0]));
	for (auto x : ans[0])
		printf ("%d ", x);
	puts("");
} 
 
int main() {
	srand(2137);
	scanf ("%d", &T);
	while (T--)
		solve();
}