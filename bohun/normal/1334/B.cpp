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
const int nax = 1e5 + 10; 
 
int T, n, k, a[nax]; 
ll b[nax];


void solve() {
	scanf ("%d%d", &n, &k);
	rep(i, 1, n) {
		scanf ("%d", &a[i]);
	}
	sort(a + 1, a + n + 1);
	b[n + 1] = 0;
	per(i, 1, n) b[i] = b[i + 1] + a[i];
	rep(i, 1, n) {
		if (b[i] >= (ll) k * (n - i + 1)) {
			printf ("%d\n", n - i + 1);
			return;
		}
	}
	printf ("0\n");
}	
		
 
int main() {
	scanf ("%d", &T);
	while (T--) solve();
	
    return 0;
}