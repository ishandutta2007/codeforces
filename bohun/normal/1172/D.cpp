#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define per(i, a, b) for (int i = b; i >= a; --i)
#define all(x) x.begin(), x.end()

using ll = long long;
using namespace std;

const int N = 1024;

int n, r[N], c[N];
vector<tuple<int, int, int, int>> ans;

int main() {
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d", r + i);
	rep(i, 1, n) scanf("%d", c + i);
	rep(f, 1, n) {
		int i = find(r + 1, r + n + 1, f) - r;
		int j = find(c + 1, c + n + 1, n - f + 1) - c;
		if (r[f] != f || c[n - f + 1] != n - f + 1) {
			ans.pb({f, j, r[f], n - f + 1});
			swap(r[i], r[f]);
			swap(c[j], c[n - f + 1]);
		}
	}
	printf("%d\n", sz(ans));
	for (auto [a, b, c, d] : ans) printf("%d %d %d %d\n", a, b, c, d);
	return 0;
}