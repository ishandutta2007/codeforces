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
 
using namespace std;

int T;
int n, d;
int lvl[5100];
int p[5100];

bool ok(int x) {
	assert(2 <= x);
	if (2 * lvl[x - 2] < lvl[x - 1] + 1) return false;
	if (2 * (lvl[x] - 1) < lvl[x + 1]) return false;
	return true;
} 

void solve() {
	scanf ("%d%d", &n, &d);
	rep(i, 0, n) lvl[i] = 0;
	int Min = 0;
	int x = n;
	rep(i, 0, 20) {
		int y = min(x, (1 << i));
		Min += i * y;
		x -= y;
	}
		
	if (d < Min || d > n * (n - 1) / 2) {
		printf ("NO\n");
		return;
	}
	
	int ans = n * (n - 1) / 2;
	
	rep(i, 0, n - 1) lvl[i] = 1;
	
	while (ans != d) {
		int j = -1;
		rep(i, 2, n - 1) {
			if (ok(i)) {
				j = i;
				break;
			}
		}
		lvl[j - 1]++;
		lvl[j]--;
		ans--;
	}
	
	printf ("YES\n");
	
	vector <int> nodes = {1};
	x = 2;
	
	rep(i, 1, n - 1) {
		vector <int> v;
		rep(j, 1, lvl[i]) v.pb(x++);
		for (int j = 0; j < lvl[i]; j += 2) {
			p[v[j]] = nodes[j / 2];
			if (j + 1 < lvl[i])
				p[v[j + 1]] = nodes[j / 2];
		}
		nodes = v;
	}
	
	rep(i, 2, n) printf ("%d ", p[i]);
	printf ("\n");
	
}
 
int main() {
	scanf ("%d", &T);
	while (T--) solve();
	
	return 0;
}