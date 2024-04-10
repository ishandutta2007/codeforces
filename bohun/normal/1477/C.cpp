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

const int N = 5005;

int n, x[N], y[N], vis[N];

int main() {
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d%d", x + i, y + i);
	vis[1] = 1; int a = 1; printf("1 ");
	rep(i, 2, n) {
		pair<ll, int> best = {0, 0};
		rep(j, 1, n) {
			ll d = ll(x[j] - x[a]) * (x[j] - x[a]) + ll(y[j] - y[a]) * (y[j] - y[a]);
			if (!vis[j] && d > best.fi) best = {d, j};
		}
		printf("%d ", a = best.se);
		vis[a] = 1;
	}
	return 0;
}