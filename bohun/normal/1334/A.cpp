#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define sz(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define all(x) x.begin(), x.end()
 
using namespace std;
 
int T, a, b, c, d, n; 

void solve() {
	scanf ("%d", &n);
	bool ok = 1;
	int c = -1, d = -1;
	rep(i, 1, n) {
		scanf ("%d%d", &a, &b);
		if (c != -1 && c > a) ok = 0;
		if (d != -1 && d > b) ok = 0;
		if (c != -1 && b - d > a - c) ok = 0;
		if (a < b) ok = 0;
		c = a;
		d = b;
	}
	printf (ok ? "YES\n" : "NO\n");
}
 
int main() {
	scanf ("%d", &T);
	while (T--) solve();
	
    return 0;
}