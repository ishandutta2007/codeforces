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

const int nax = 4e5 + 100;

int n, k;
int a[nax];

int res[nax];

void add(int l, int r, int x) {
	if (l > r) return;
	res[l] += x;
	res[r + 1] -= x;
}

int main() {
	int t;
	scanf ("%d", &t);
	while (t--) {
		scanf ("%d%d", &n, &k);
		rep(i, 1, n) {
			scanf ("%d", a + i);
		}
		rep(i, 1, 2 * k)
			res[i] = 0;
		rep(i, 1, n / 2) {
			int b = min(a[i], a[n - i + 1]);
			int c = max(a[i], a[n - i + 1]);
			add(c + k + 1, 2 * k, 1);
			add(b + c + 1, 2 * k, 1);
			
			add(1, b + c - 1, 1);
			add(1, b, 1);
		}
		rep(i, 1, 2 * k)
			res[i] += res[i - 1];
		int ans = 1e9;
		rep(i, 1, 2 * k)
			ans = min(ans, res[i]);
		printf ("%d\n", ans);
		
			
		
	}
	
	return 0;
}