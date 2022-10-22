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
const int nax = 3e5 + 10; 
 
int T, n;
ll a[nax], b[nax];


void solve() {
	scanf ("%d", &n);
	rep(i, 0, n - 1) {
		scanf ("%lld%lld", a + i, b + i);
	}
	ll sum = 0, m = 1e18, s = 0;
	rep(i, 0, n - 1) {
		b[i] = min(b[i], a[(i + 1) % n]);
		sum += b[i];
		s += a[i];
		m = min(m, (ll) b[i]);
	}
	printf ("%lld\n", s - (sum - m));
}	
		
 
int main() {
	scanf ("%d", &T);
	while (T--) solve();
	
    return 0;
}