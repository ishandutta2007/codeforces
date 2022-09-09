#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
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
int n, root;
vector <int> a[MAXN];
int dfs(int pos, int fa) {
	int dest = 0;
	for (auto x : a[pos])
		if (x != fa) {
			if (dest) {
				printf("No\n");
				exit(0);
			} else dest = x;
		}
	if (dest == 0) return pos;
	else return dfs(dest, pos);
}
int main() {
	read(n);
	for (int i = 1; i <= n - 1; i++) {
		int x, y; read(x), read(y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	root = 1;
	for (int i = 2; i <= n; i++)
		if (a[i].size() > a[root].size()) root = i;
	vector <int> ans;
	for (auto x : a[root])
		ans.push_back(dfs(x, root));
	printf("Yes\n");
	writeln(ans.size());
	for (auto x : ans)
		printf("%d %d\n", root, x);
	return 0;
}