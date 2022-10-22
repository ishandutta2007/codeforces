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

int n;
char s[510];

int done[510][510];

int dp(int l, int r) {
	if (l > r) return 0;
	if (done[l][r] != -1) return done[l][r];
	if (l == r) return 1;
	int ans = 1 + dp(l + 1, r);
	rep(j, l + 1, r)
		if (s[l] == s[j])
			ans = min(ans, dp(l + 1, j - 1) + dp(j, r));
	return done[l][r] = ans;
}	

int main() {
	scanf ("%d", &n);
	scanf ("%s", s + 1);
	rep(i, 1, n) rep(j, 1, n) done[i][j] = -1;
	printf ("%d\n", dp(1, n));
		
	
	return 0;
}