#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5005;
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
bool ans;
void dfs(int pos, int fa) {
	if (a[pos].size() == 1) return;
	int cnt = 0;
	for (unsigned i = 0; i < a[pos].size(); i++) {
		if (a[a[pos][i]].size() == 1) cnt++;
		if (a[pos][i] != fa) dfs(a[pos][i], pos);
	}
	if (cnt <= 2) ans = false;
}
int main() {
	int n; read(n);
	for (int i = 2; i <= n; i++) {
		int x; read(x);
		a[x].push_back(i);
		a[i].push_back(x);
	}
	ans = true;
	dfs(1, 0);
	if (ans) printf("Yes\n");
	else printf("No\n");
	return 0;
}