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

int n, x, y;
char s[1 << 20];

void solve() {
	scanf("%d%d%s", &x, &y, s + 1);
	n = strlen(s + 1);
	int x0 = 0, x1 = 0, y0 = 0, y1 = 0;
	rep(i, 1, n) {
		if (s[i] == 'L') x0++;
		if (s[i] == 'R') x1++;
		if (s[i] == 'D') y0++;
		if (s[i] == 'U') y1++;
	}
	printf((x > 0 ? x <= x1 : -x <= x0) && (y > 0 ? y <= y1 : -y <= y0) ? "YES\n" : "NO\n");
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
	return 0;
}