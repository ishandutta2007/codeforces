#include <bits/stdc++.h>
#define ll long long
#define ld long double
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

int main() {
	int T;
	scanf ("%d", &T);
	while (T--) {
		int a, b, c, d;
		scanf ("%d%d%d%d", &a, &b, &c, &d);
		if (a <= b) {
			printf ("%d\n", b);
			continue;
		}
		int total = a - b;
		if (c <= d) {
			printf ("-1\n");
			continue;
		}
		int z = (total + c - d - 1) / (c - d);
		printf ("%lld\n", b + 1LL * z * c);
	}
	
	return 0;
}