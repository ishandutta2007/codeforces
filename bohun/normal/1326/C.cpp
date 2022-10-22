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
#define all(x) x.begin(), x.end()

using namespace std;

const int N = 2e5 + 100;
const int MOD = 998244353;

int n, k;
int a[N];

int main() {
	scanf ("%d%d", &n, &k);
	int last = 0;
	LL ans1 = 0;
	int ans2 = 1;
	rep(i, 1, n) {
		scanf ("%d", a + i);
		if (a[i] >= n - k + 1) {
			ans1 += a[i];
			if (last == 0) ;
			else {
				ans2 = (LL) ans2 * (i - last) % MOD;
			}
			last = i;
		}
	}
	printf ("%lld %d\n", ans1, ans2);
				
	
    return 0;
}