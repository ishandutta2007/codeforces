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
int n, ans, root;
vector <int> a[MAXN];
bool key[MAXN], col[MAXN];
void dfs(int pos, int fa) {
	for (auto x : a[pos])
		if (x != fa) {
			col[x] = !col[pos];
			dfs(x, pos);
		}
}
int main() {
	read(n);
	for (int i = 1; i <= n - 1; i++) {
		int x, y; read(x), read(y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	for (int i = 1; i <= n; i++) {
		key[i] = a[i].size() == 1;
		if (key[i]) root = i;
	}
	dfs(root, 0);
	bool type = true;
	for (int i = 1; i <= n; i++)
		if (key[i]) type &= col[i] == col[root];
	int ans = n - 1;
	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for (auto x : a[i])
			cnt += key[x];
		if (cnt >= 2) ans -= cnt - 1;
	}
	printf("%d %d\n", 1 + !type * 2, ans);
	return 0;
}