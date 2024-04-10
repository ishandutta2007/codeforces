#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep2(i, j, n) for (LL i = j; i <= n; ++i)
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define boost cin.tie(0);ios_base::sync_with_stdio(0);
#define vi vector <int>

using namespace std;

int n;
int a[1005], b[1005];

int main() {	
	int T;
	scanf ("%d", &T);
	while (T--) {
		scanf ("%d", &n);
		rep(i, 1, n) scanf ("%d", a + i);
		rep(i, 1, n) scanf ("%d", b + i);
		sort(a + 1, a + n + 1);
		sort(b + 1, b + n + 1);
		rep(i, 1, n) printf ("%d ", a[i]);
		printf ("\n");
		rep(i, 1, n) printf ("%d ", b[i]);
		printf ("\n");
	}
	
	return 0;
}