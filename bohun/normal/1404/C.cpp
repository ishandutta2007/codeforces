#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ss(x) (int) x.size()
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)

using ll = long long;
using namespace std;

const int T = 1 << 19;
const int N = 3e5 + 100;

int n, q;
int ans[N], a[N];

vector <pair<int, int>> Q[N];

struct BIT {
	int F[N];
	BIT() {
		rep(i, 1, N - 1) F[i] = 0;
	}
	void add(int x, int c) {
		for (; x < N; x += x & -x) F[x] += c;
	}
	int query(int x) {
		int res = 0;
		for (; x; x -= x & -x) res += F[x];
		return res;
	}
} B;

int main() {
	int T;
	//scanf ("%d", &T);
	T = 1;
	while (T--) {
		scanf ("%d%d", &n, &q);
		rep(i, 1, n) Q[i].clear();
		rep(i, 1, n) scanf ("%d", a + i);
		rep(i, 1, q) {
			int l, r;
			scanf ("%d%d", &l, &r);
			Q[n - r].pb(mp(l + 1, i));
		}
		for (int i = 1; i <= n; ++i) {
			int x = i - a[i];
			if (x >= 0) {
				int l = 0, r = i;
				while (l < r) {
					int m = (l + r + 1) / 2;
					if (B.query(m) >= x) l = m;
					else r = m - 1;
				}
				if (l) {
					//cat(i);
					//cat(l);
					B.add(1, +1);
					B.add(l + 1, -1);
				}
			}
			//for (int j = 1; j <= i; ++j) cout << B.query(j) << " ";
			//cout << endl;
			for (auto it : Q[i])
				ans[it.se] = B.query(it.fi);
		}
		for (int i = 1; i <= q; ++i) printf ("%d\n", ans[i]);
			
	}
	return 0;
}