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

const int N = 2e5 + 10;

int T;
LL n, k;

int main() {		
	scanf ("%d", &T);
	while (T--) {
		scanf ("%lld%lld", &n, &k);
		LL s = k + (LL) k * (k - 1);
		if (s % 2 == n % 2 && n >= s) printf ("YES\n");
		else printf ("NO\n");
	}
	return 0;
}