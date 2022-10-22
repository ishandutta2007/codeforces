#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define per(i, a, b) for (int i = b; i >= a; --i)
#define all(x) x.begin(), x.end()
#define mp make_pair
 
using ll = long long;
using namespace std;	

const int N = 2005;

int n, vis[N];

int ask(vector<int> v, int x) {
	printf("? %d 1\n", sz(v));
	for (auto i : v) printf("%d ", i); puts("");
	printf("%d\n", x);
	fflush(stdout);
	scanf("%d", &x);
	return x;
}

void solve() {
	memset(vis, 0, sizeof vis);
	scanf("%d", &n);
	vector<int> v = {1};
	rep(i, 2, n) {
		if (ask(v, i)) {
			int l = 1, r = i - 1;
			while (l < r) {
				int m = (l + r) / 2;
				v = {};
				rep(j, 1, m) v.pb(j);
				if (ask(v, i)) r = m;
				else l = m + 1;
			}
			vis[i] = vis[l] = 1;
			rep(j, i + 1, n) vis[j] = !!ask({i}, j);
			break;
		}
		else v.pb(i);
	}
	int ans = 0;
	rep(i, 1, n) ans += !vis[i];
	printf("! %d ", ans);
	rep(i, 1, n) if (!vis[i]) printf(" %d", i);
	puts("");
	fflush(stdout);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) solve();
	return 0;
}