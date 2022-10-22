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

int T, n, a[1100], m;

int main() {	
	scanf ("%d", &T);
	while (T--) {
		scanf ("%d%d", &n, &m);
		int z = 0;
		rep(i, 1, n) {
			scanf ("%d", a + i);
			if (i > 1) z += a[i];
		}
		printf ("%d\n", min(m, a[1] + z));
	}
	
	
	return 0;
}