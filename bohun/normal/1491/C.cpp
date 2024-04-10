#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define per(i, a, b) for (int i = b; i >= a; --i)
#define all(x) x.begin(), x.end()
#define mp make_pair
 
using ll = long long;
using namespace std;	

const int N = 5005;

int n; 
ll s[N], r[N], ans;

void solve() {
	ans = 0;
	memset(r, 0, sizeof r);
	scanf("%d", &n);
	rep(i, 1, n) {
		scanf("%lld", s + i); 
		ll now = max(0LL, s[i] - 1 - r[i]);
		r[i] += now;
		ans += now;
		rep(j, i + 2, n)
			if (j - i <= s[i])
				r[j]++;
		r[i + 1] += max(0LL, r[i] - (s[i] - 1));
	}
	printf("%lld\n", ans);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) solve();
	return 0;
}