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

const int N = 1e5 + 101;

int n;
int a, x;
int p[N];

int main() {
	int T;
	scanf ("%d", &T);
	while (T--) {
		scanf ("%d%d", &n, &x);
		int F = -1, L = -1;
		rep(i, 1, n) {
			scanf ("%d", &a);
			p[i] = (p[i - 1] + a) % x;
			if (F == -1 && p[i])
				F = i;
			if (p[i]) 
				L = i;
		}
		int ans = -1;
		if (L != -1)
			ans = L;
		if (F != -1)
			ans = max(ans, n - F);
		printf ("%d\n", ans);
	}
		
	return 0;
}