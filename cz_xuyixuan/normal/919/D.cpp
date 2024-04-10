#include<bits/stdc++.h>
using namespace std;
const int MAXN = 300005;
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
char s[MAXN], now;
int ans[MAXN];
vector <int> a[MAXN];
bool vis[MAXN], ins[MAXN], halted;
void chkmax(int &x, int y) {
	x = max(x, y);
}
int get(int pos) {
	if (ans[pos] != -1) return ans[pos];
	int tans = 0;
	for (unsigned i = 0; i < a[pos].size(); i++)
		chkmax(tans, get(a[pos][i]));
	return ans[pos] = tans + (now == s[pos]);
}
void visit(int pos) {
	if (vis[pos]) return;
	if (ins[pos]) {
		halted = true;
		return;
	}
	ins[pos] = true;
	for (unsigned i = 0; i < a[pos].size(); i++)
		visit(a[pos][i]);
	ins[pos] = false;
	vis[pos] = true;
}
int main() {
	int n, m; read(n), read(m);
	scanf("\n%s", s + 1);
	for (int i = 1; i <= m; i++) {
		int x, y;
		read(x), read(y);
		a[x].push_back(y);
	}
	for (int i = 1; i <= n; i++)
		visit(i);
	if (halted) {
		printf("-1\n");
		return 0;
	}
	int Max = 0;
	for (now = 'a'; now <= 'z'; now++) {
		memset(ans, -1, sizeof(ans));
		for (int i = 1; i <= n; i++)
			chkmax(Max, get(i));
	}
	writeln(Max);
	return 0;
}