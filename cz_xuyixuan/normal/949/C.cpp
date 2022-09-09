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
int x[MAXN];
int e, ex[MAXN], ey[MAXN];
int tot, belong[MAXN], size[MAXN];
int timer, dfn[MAXN], low[MAXN];
int top, Stack[MAXN];
bool instack[MAXN], dis[MAXN];
void tarjan(int pos) {
	dfn[pos] = low[pos] = ++timer;
	instack[pos] = true;
	Stack[++top] = pos;
	for (unsigned i = 0; i < a[pos].size(); i++)
		if (dfn[a[pos][i]] == 0) {
			tarjan(a[pos][i]);
			low[pos] = min(low[pos], low[a[pos][i]]);
		} else if (instack[a[pos][i]]) low[pos] = min(low[pos], dfn[a[pos][i]]);
	if (low[pos] == dfn[pos]) {
		int tmp = Stack[top--];
		instack[tmp] = false;
		belong[tmp] = ++tot;
		size[tot] = 1;
		while (tmp != pos) {
			tmp = Stack[top--];
			instack[tmp] = false;
			belong[tmp] = tot;
			size[tot]++;
		}
	}
}
int main() {
	int n, m, h;
	read(n), read(m), read(h);
	for (int i = 1; i <= n; i++)
		read(x[i]);
	for (int i = 1; i <= m; i++) {
		int q, w;
		read(q), read(w);
		if ((x[q] + 1) % h == x[w]) {
			a[q].push_back(w);
			e++;
			ex[e] = q;
			ey[e] = w;
		}
		if ((x[w] + 1) % h == x[q]) {
			e++;
			a[w].push_back(q);
			ex[e] = w;
			ey[e] = q;
		}
	}
	for (int i = 1; i <= n; i++)
		if (!dfn[i]) tarjan(i);
	for (int i = 1; i <= e; i++)
		if (belong[ex[i]] != belong[ey[i]]) dis[belong[ex[i]]] = true;
	int ans = 1, cnt = n + 1;
	for (int i = 1; i <= tot; i++)
		if (dis[i] == false && size[i] < cnt) {
			cnt = size[i];
			ans = i;
		}
	printf("%d\n", cnt);
	for (int i = 1; i <= n; i++)
		if (belong[i] == ans) printf("%d ", i);
	return 0;
}