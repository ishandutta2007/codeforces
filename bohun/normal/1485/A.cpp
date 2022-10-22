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

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int a, b, ans = 100;
		scanf("%d%d", &a, &b);
		rep(i, 0, 30) {
			int x = b + i, cur = 0, y = a;
			if (x == 1) continue;
			while (y > 0) {
				y /= x;
				cur++;
			}
			ans = min(ans, cur + i);
		}
		printf("%d\n", ans);
	}
	return 0;
}