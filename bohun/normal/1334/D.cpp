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
 
int T, n, q;
ll l, r;
vector <int> res;
 
void go(int a, int b) {
	while (true) {
		if (b == n + 1) {
			a++;
			b = a + 1;
		}
		if (a == n) {
			if (q) {
				res.pb(1);
				q--;
			}
			return;
		}
		if (q) {
			res.pb(a);
			q--;
		}
		if (q) {
			res.pb(b);
			q--;
		}
		b++;
		if (!q) return;
	}
}
	
vector <int> xd = {1, 2, 1};
 
void solve() {
	res.clear();
	scanf ("%d%lld%lld", &n, &l, &r);
	if (n == 2) {
		l--; r--;
		rep(i, l, r) printf ("%d ", xd[i]);
		printf ("\n");
		return;
	}
	q = r - l + 1;
	rep(i, 1, n - 1) {
		int k = 2 * (n - i);
		if (k < l) {
			l -= k;
			continue;
		}
		if (l % 2 == 0) {
			q--;
			res.pb(l / 2 + i);
		}
		go(i, l / 2 + i + 1);
		break;
	}
	if (ss(res) == 0) {
		res.pb(1);
		assert(q == 1);
		q--;
	}
	assert(q == 0);
	for (auto it : res)
		printf ("%d ", it);
	printf ("\n");
	
}	
		
 
int main() {
	scanf ("%d", &T);
	while (T--) solve();
	
    return 0;
}