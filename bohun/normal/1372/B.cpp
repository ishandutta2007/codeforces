#include <bits/stdc++.h>
#define ll long long
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
	int T, n;
	scanf ("%d", &T);
	while (T--) {
		int mx = 0, a;
		scanf ("%d", &n);
		for (int i = 1; i * i <= n; ++i) {
			if (n % i == 0) {
				int d = i;
				if (d != n && d > mx) {
					mx = d;
					a = d;
				}
				d = n / i;
				if (d != n && d > mx) {
					mx = d;
					a = d;
				}
			}
		}
		printf ("%d %d\n", a, n - a);
	}
	
	return 0;
}