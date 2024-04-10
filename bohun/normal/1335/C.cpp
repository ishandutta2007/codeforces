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

int n;
int a[200005];
int ile[200005];

void solve() {
	scanf ("%d", &n);
	rep(i, 1, n) ile[i] = 0;
	rep(i, 1, n) {
		scanf ("%d", a + i);
		ile[a[i]]++;
	}
	int maks = 0, dif = 0;
	rep(i, 1, n) {
		maks = max(maks, ile[i]);
		if (ile[i]) dif++;
	}
	int ans = 0;
	ans = min(dif - 1, maks);
	ans = max(ans,  min(maks - 1, dif));
	printf ("%d\n", ans);
}
	

int main() {
	int T;
	scanf ("%d", &T);
	while (T--) solve();
	
	
	return 0;
}