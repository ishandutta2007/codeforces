#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define per(i, a, b) for (int i = b; i >= a; --i)
#define all(x) x.begin(), x.end()
 
using ll = long long;
using namespace std;

const int N = 1 << 20;

int n, a[N], l[N], r[N], cnt[N], dp[N];

int main() {
	scanf("%d", &n);
	rep(i, 1, n) {
		scanf("%d", a + i);
		if (!l[a[i]]) l[a[i]] = i;
		r[a[i]] = i;
	}
	per(i, 1, n) {
		int x = a[i];
		cnt[x]++;
		dp[i] = max(dp[i + 1], cnt[x]);
		if (l[x] == i)
			dp[i] = max(dp[i], dp[r[x] + 1] + cnt[x]);
	}
	printf("%d\n", n - dp[1]);
	return 0;
}