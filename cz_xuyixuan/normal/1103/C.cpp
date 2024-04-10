#include<bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 5;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
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
bool vis[MAXN], leaf[MAXN];
int n, m, k, len, depth[MAXN], father[MAXN];
vector <int> a[MAXN], b[MAXN];
void work(int pos) {
	vis[pos] = true;
	for (auto x : a[pos])
		if (!vis[x]) {
			b[pos].push_back(x);
			b[x].push_back(pos);
			work(x);
		}
}
void dfs(int pos, int fa) {
	leaf[pos] = true;
	father[pos] = fa;
	depth[pos] = depth[fa] + 1;
	for (auto x : b[pos])
		if (x != fa) {
			dfs(x, pos);
			leaf[pos] = false;
		}
}
int main() {
	read(n), read(m), read(k);
	for (int i = 1; i <= m; i++) {
		int x, y; read(x), read(y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	work(1);
	dfs(1, 0);
	int pos = 0;
	for (int i = 1; i <= n; i++)
		if (depth[i] > depth[pos]) pos = i;
	dfs(pos, 0);
	for (int i = 1; i <= n; i++)
		if (depth[i] > depth[pos]) pos = i;
	if (depth[pos] >= n / k) {
		puts("PATH");
		printf("%d\n", depth[pos]);
		while (pos) {
			printf("%d ", pos);
			pos = father[pos];
		}
		return 0;
	}
	puts("CYCLES");
	dfs(1, 0);
	for (int i = 1; i <= n && k >= 1; i++)
		if (leaf[i]) {
			sort(a[i].begin(), a[i].end(), [&] (int x, int y) {return depth[x] > depth[y]; });
			bool found = false;
			for (unsigned j = 0; j < a[i].size() && !found; j++)
			for (unsigned k = j + 1; k < a[i].size() && !found; k++) {
				int x = a[i][j], y = a[i][k];
				if (depth[x] - depth[y] + 2 >= 3 && (depth[x] - depth[y] + 2) % 3 != 0) {
					printf("%d\n%d", depth[x] - depth[y] + 2, i);
					int pos = x;
					while (pos != y) {
						printf(" %d", pos);
						pos = father[pos];
					}
					printf(" %d\n", pos);
					found = true;
				}
			}
			assert(found);
			k--;
		}
	assert(k == 0);
	return 0;
}