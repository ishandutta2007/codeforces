#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define per(i, a, b) for (int i = b; i >= a; --i)
#define all(x) x.begin(), x.end()
#define mp make_pair

using ll = long long;
using namespace std;

const int N = 305;

int n;
char s[N][N];

void solve() {
	int cnt[3]{};
	scanf("%d", &n);
	rep(i, 1, n) {
		scanf("%s", s[i] + 1);
		rep(j, 1, n) cnt[(i + j) % 3] += s[i][j] == 'X';
	}
	int x = min_element(cnt, cnt + 3) - cnt;
	rep(i, 1, n) {
		rep(j, 1, n) printf("%c", x == (i + j) % 3 && s[i][j] == 'X' ? 'O' : s[i][j]);
		puts("");
	}
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) solve();
	return 0;
}