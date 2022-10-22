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

int T, a, b;

int main() {
	scanf ("%d", &T);
	while (T--) {
		scanf ("%d%d", &a, &b);
		if (a > b) swap(a, b);
		int c = min({b - a, a, b / 2});
		int ans = c;
		b -= 2 * c;
		a -= c;
		int d = min(a, b) / 3;
		ans += 2 * d;
		a -= d * 3;
		b -= d * 3;
		if ((a >= 2 && b >= 1) || (a >= 1 && b >= 2))
			ans++;
		printf ("%d\n", ans);
	}
			
	
	return 0;
}