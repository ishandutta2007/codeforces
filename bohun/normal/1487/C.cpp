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

int n, ans[105][105];

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		memset(ans, -1, sizeof ans);
		rep(i, 0, n - 1) 
			rep(j, 1, (n - 1) / 2)
				ans[i][(i + j) % n] = 1;
		if (n % 2 == 0)
			rep(i, 0, n - 1) ans[i][(i + n / 2)] = 0;
		rep(i, 0, n - 1) 
			rep(j, i + 1, n - 1)
				printf("%d ", ans[i][j]);
		puts("");
	}
	return 0;
}