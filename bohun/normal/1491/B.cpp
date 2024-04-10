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

int n, u, v, a[105];

void solve() {
	scanf("%d%d%d", &n, &u, &v);
	rep(i, 1, n) scanf("%d", a + i);
	rep(i, 2, n) if (abs(a[i - 1] - a[i]) > 1) return puts("0"), void();
	rep(i, 2, n) if (abs(a[i - 1] - a[i]) == 1) return !printf("%d\n", min(u, v)), void();
	printf("%d\n", v + min(u, v));
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) solve();
	return 0;
}