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

const int N = 1 << 18;

int n, p[N], vis[N];
vector<pair<int, int>> ans;
vector<int> v;

void foo(int a, int b) {
	swap(p[a], p[b]);
	ans.pb({a, b});
}

void solve(int a, int b) {
	foo(a, b);
	while (true) {
		if (p[a] != b) foo(a, p[a]);
		else if (p[b] != a) foo(b, p[b]);
		else {
			foo(a, b);
			break;
		}
	}
}

int main() {
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d", p + i);
	rep(i, 1, n) {
		if (vis[i]) continue;
		int j = i;
		while (!vis[j]) {
			vis[j] = 1;
			j = p[j];
		}
		v.pb(i);
	}
	rep(i, 0, sz(v) / 2 - 1) solve(v[2 * i], v[2 * i + 1]);
	if (sz(v) & 1) {
		int x = v.back();
		if (sz(v) == 1) {
			int y = p[x];
			foo(x, y);
			foo(p[x], y);
			while (true) {
				if (p[x] != y) foo(x, p[x]);
				if (p[y] != x) foo(y, p[y]);
				else {
					foo(x, y);
					break;
				}
			}
		}
		else {
			int k = 1;
			while (p[k] != k) k++;
			if (k != x) solve(k, x);
		}
	}	
	printf("%d\n", sz(ans));
	for (auto [a, b] : ans) printf("%d %d\n", a, b);
	return 0;
}