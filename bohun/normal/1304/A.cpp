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

using namespace std;

int main() {	
	int T;	
	scanf ("%d", &T);
	while (T--) {
		int a, b, x, y;
		scanf ("%d %d %d %d", &x, &y, &a, &b);
		if ((y - x) % (a + b) != 0) {
			printf ("-1\n");
		}
		else {
			printf ("%d\n", (y - x) / (a + b));
		}
	}
	
	
	return 0;
}