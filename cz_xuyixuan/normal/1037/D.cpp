#include<bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
template <typename T> void chkmax(T &x, T y) {x = max(x, y); }
template <typename T> void chkmin(T &x, T y) {x = min(x, y); } 
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
template <typename T> void write(T x) {
	if (x < 0) x = -x, putchar('-');
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
template <typename T> void writeln(T x) {
	write(x);
	puts("");
}
vector <int> a[MAXN];
int n, b[MAXN], home[MAXN], depth[MAXN];
void dfs(int pos, int fa) {
	depth[pos] = depth[fa] + 1;
	for (unsigned i = 0; i < a[pos].size(); i++)
		if (a[pos][i] != fa) dfs(a[pos][i], pos);
}
bool cmp(int x, int y) {
	return home[x] < home[y];
}
int main() {
	read(n);
	for (int i = 1; i <= n - 1; i++) {
		int x, y; read(x), read(y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	for (int i = 1; i <= n; i++)
		read(b[i]), home[b[i]] = i;
	dfs(1, 0);
	for (int i = 1; i <= n; i++)
		if (depth[b[i]] < depth[b[i - 1]]) {
			printf("No\n");
			return 0;
		}	
	for (int i = 1; i <= n; i++)
		sort(a[i].begin(), a[i].end(), cmp);
	static int q[MAXN];
	static bool vis[MAXN];
	int l = 1, r = 1;
	q[l] = 1; vis[1] = true;
	while (l <= r) {
		int tmp = q[l++];
		for (unsigned i = 0; i < a[tmp].size(); i++)
			if (!vis[a[tmp][i]]) {
				vis[a[tmp][i]] = true;
				q[++r] = a[tmp][i];
			}
	}
	for (int i = 1; i <= n; i++)
		if (q[i] != b[i]) {
			printf("No\n");
			return 0;
		}
	printf("Yes\n");
	return 0;
}