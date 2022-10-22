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

int n, k, h[105];

int go() {
	rep(i, 1, n - 1) 
		if (h[i] < h[i + 1]) {
			h[i]++;
			return i;
		}
	return n;
}		

void solve() {
	scanf("%d%d", &n, &k);
	rep(i, 1, n) scanf("%d", h + i);
	int lst;
	while (k--) {
		lst = go();
		if (lst == n) break;
	}
	printf("%d\n", lst < n ? lst : -1);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
	return 0;
}