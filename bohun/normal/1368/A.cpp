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

int T;

int main() {
	scanf ("%d", &T);
	while (T--) {
		int a, b, c;
		scanf ("%d%d%d", &a, &b, &c);
		int ans = 0;
		while (a <= c && b <= c) {
			ans++;
			if (a <= b) {
				a += b;
			}
			else {
				b += a;
			}
		}
		printf ("%d\n", ans);
	}
	
	return 0;
}