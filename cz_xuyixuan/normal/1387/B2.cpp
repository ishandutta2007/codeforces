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
int timer, sa[MAXN], match[MAXN];
ll ans; int root, n, weight[MAXN], size[MAXN];
void work(int pos, int fa) {
	size[pos] = 1;
	weight[pos] = 0;
	for (auto x : a[pos])
		if (x != fa) {
			work(x, pos);
			size[pos] += size[x];
			ans += 2 * min(size[x], n - size[x]);
			chkmax(weight[pos], size[x]);
		}
	chkmax(weight[pos], n - size[pos]);
	if (root == 0 || weight[pos] < weight[root]) root = pos;
}
void dfs(int pos, int fa) {
	sa[++timer] = pos;
	for (auto x : a[pos])
		if (x != fa) dfs(x, pos);
}
int main() {
	read(n);
	for (int i = 1; i <= n - 1; i++) {
		int x, y; read(x), read(y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	work(1, 0);
	dfs(root, 0);
	for (int i = 1, j = n / 2 + 1; i <= n; i++, j = (j == n) ? 1 : (j + 1))
		match[sa[i]] = sa[j];
	cout << ans << endl;
	for (int i = 1; i <= n; i++)
		printf("%d ", match[i]);
	printf("\n");
	return 0;
}