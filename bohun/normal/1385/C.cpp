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

const int N = 2e5 + 100;

int n;
int a[N];

int main() {
	int T;
	scanf ("%d", &T);
	while (T--) {
		scanf ("%d", &n);
		rep(i, 1, n) scanf ("%d", a + i);
		int type = 1, ans = 0;
		per(i, 1, n - 1) {
			if (type == 1) {
				if (a[i] >= a[i + 1]) ;
				else {
					type = -1;
				}
			}
			else {
				if (a[i] <= a[i + 1]) ;
				else {
					ans = i;
					break;
				}
			}
		}
		printf ("%d\n", ans);
	}
	return 0;
}