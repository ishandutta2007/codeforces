#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
typedef long long ll;
template <typename T> void chkmax(T &x, T y) {x = max(x, y); }
template <typename T> void chkmin(T &x, T y) {x = min(x, y); } 
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
vector <int> a[MAXN];
int n, k, depth[MAXN], size[MAXN], inc[MAXN];
void dfs(int pos, int fa) {
	depth[pos] = depth[fa] + 1, size[pos] = 1;
	for (auto x : a[pos])
		if (x != fa) {
			dfs(x, pos);
			size[pos] += size[x];
		}
}
int main() {
	read(n), read(k);
	for (int i = 1; i <= n - 1; i++) {
		int x, y; read(x), read(y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	dfs(1, 0);
	for (int i = 1; i <= n; i++)
		inc[i] = (depth[i] - 1) - (size[i] - 1);
	sort(inc + 1, inc + n + 1, [&] (int x, int y) {return x > y; });
	ll ans = 0;
	for (int i = 1; i <= k; i++)
		ans += inc[i];
	cout << ans << endl;
	return 0;
}