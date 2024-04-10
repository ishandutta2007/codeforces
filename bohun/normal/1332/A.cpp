#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define all(x) x.begin(), x.end()

using namespace std;

int T;
int a, b, c, d;
int x, xx, xxx, y, yy, yyy;

int main() {
	scanf ("%d", &T);
	while (T--) {
		scanf ("%d%d%d%d", &a, &b, &c, &d);
		scanf ("%d%d%d%d%d%d", &x, &y, &xx, &yy, &xxx, &yyy);
		bool ok = 1;
		if (x - a + b > xxx) ok = 0;
		if (x - a + b < xx) ok = 0;
		if (y - c + d > yyy) ok = 0;
		if (y - c + d < yy) ok = 0;
		if (xx == xxx && a + b > 0) ok = 0;
		if (yy == yyy && c + d > 0) ok = 0;
		printf (ok == 1 ? "Yes\n" : "No\n");
	}
	
    return 0;
}