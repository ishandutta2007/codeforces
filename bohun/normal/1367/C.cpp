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

const int N = 2e5 + 101;

int n, k;
char s[N];
vector <int> v;

void solve() {
	scanf ("%d%d", &n, &k);
	scanf ("%s", s + 1);
	v.clear();
	rep(i, 1, n)
		if (s[i] == '1')
			v.pb(i);
	if (ss(v) == 0) {
		printf ("%d\n", (n + k) / (k + 1));
		return;
	}
	int A = v[0] - 1;
	int B = n - v.back();
	int ans = 0;
	ans += A / (k + 1) + B / (k + 1);
	rep(i, 1, ss(v) - 1)
		ans += max(0, (v[i] - v[i - 1] - k - 1) / (k + 1));
	printf ("%d\n", ans);
}

int main() {
	int T;
	scanf ("%d", &T);
	while (T--) solve();	
	return 0;
}