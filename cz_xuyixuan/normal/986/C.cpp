#include<bits/stdc++.h>
using namespace std;
const int MAXN = 4194304;
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
int n, m, goal;
int top, Stack[MAXN];
int tot, belong[MAXN];
int timer, dfn[MAXN], low[MAXN];
bool instack[MAXN], selected[MAXN];
set <int> ans;
void tarjan(int s) {
	Stack[++top] = s;
	instack[s] = true;
	dfn[s] = low[s] = ++timer;
	for (int i = 0; i < n; i++) {
		int tmp = 1 << i;
		if ((s & tmp) == 0) continue;
		int t = s ^ tmp;
		if (dfn[t] == 0) {
			tarjan(t);
			chkmin(low[s], low[t]);
		} else if (instack[t]) chkmin(low[s], dfn[t]);
	}
	if (selected[s]) {
		int t = s ^ goal;
		if (dfn[t] == 0) {
			tarjan(t);
			chkmin(low[s], low[t]);
		} else if (instack[t]) chkmin(low[s], dfn[t]);
	}
	if (low[s] == dfn[s]) {
		int tmp = Stack[top--];
		instack[tmp] = false;
		belong[tmp] = ++tot;
		while (tmp != s) {
			tmp = Stack[top--];
			instack[tmp] = false;
			belong[tmp] = tot;
		}
	}
}
int main() {
	read(n), read(m);
	for (int i = 1; i <= m; i++) {
		int x; read(x);
		selected[x] = true;
	}
	tarjan(goal = (1 << n) - 1);
	for (int i = 0; i <= goal; i++)
		if (selected[i]) ans.insert(belong[i]);
	writeln(ans.size());
	return 0;
}