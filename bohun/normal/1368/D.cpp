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

int n;
int a;
int cnt[20];

int main() {
	scanf ("%d", &n);
	rep(i, 1, n) {
		scanf ("%d", &a);
		rep(j, 0, 19)
			if ((a >> j) & 1)
				cnt[j]++;
	}
	ll ans = 0;
	rep(i, 1, n) {
		int x = 0;
		rep(j, 0, 19)
			if (n - cnt[j] + 1 <= i)
				x += (1 << j);
		ans += 1LL * x * x;
	}
	printf ("%lld\n", ans);
				
	
	return 0;
}