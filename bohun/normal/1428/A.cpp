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

int main() {
	int t;
	scanf ("%d", &t);
	while (t--) {
		int a, b, c, d;
		scanf ("%d%d%d%d", &a, &b, &c, &d);
		if (a == c || b == d)
			printf ("%d\n", max(abs(a - c), abs(b- d)));
		else
			printf ("%d\n", abs(a - c) + abs(b - d) + 2);
	}
	return 0;
}