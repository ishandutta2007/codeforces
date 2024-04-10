#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(x) (int) x.size()
#define cat(x) cerr << #x << " = " << x << endl
#define all(x) x.begin(), x.end()
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
 
using ll = long long;
using ld = long double;
using namespace std;		
 
int n, a[5005]; 
 
int dp(int l, int r, int h) {
	if (l > r) return 0;
	if (l == r) return a[l] != h;
	int id = -1;
	rep(i, l, r) if (id == -1 || a[i] < a[id]) id = i;
	int ans = 0;
	rep(i, l, r) ans += h < a[i];
	return min(ans, dp(l, id - 1, a[id]) + dp(id + 1, r, a[id]) + a[id] - h);
}
 
int main() {
	scanf ("%d", &n);
	rep(i, 1, n) scanf ("%d", a + i);
	printf ("%d\n", dp(1, n, 0));
	return 0;
}