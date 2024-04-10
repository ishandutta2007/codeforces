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
	int t;
	scanf ("%d", &t);
	while (t--) {
		int n;
		scanf ("%d", &n);
		if (n % 4) {
			printf ("NO\n");
			continue;
		}
		printf ("YES\n");
		n /= 2;
		rep(i, 1, n) {
			printf ("%d ", 2 * i);
		}
		rep(i, 1, n - 1) {
			printf ("%d ", 2 * i - 1);
		}
		printf ("%d\n", 2 * n - 1 + n); 
	}
	
	return 0;
}