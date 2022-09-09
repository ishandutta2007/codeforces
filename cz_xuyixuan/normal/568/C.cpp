#include<bits/stdc++.h>
using namespace std;
const int MAXN = 405;
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
char s[MAXN], lim[MAXN], ans[MAXN];
int n, m, l, edge[MAXN][MAXN], tot, point[MAXN][2];
int timer, dfn[MAXN], low[MAXN], cnt, belong[MAXN];
int top, Stack[MAXN]; bool instack[MAXN];
void work(int pos) {
	dfn[pos] = low[pos] = ++timer;
	Stack[++top] = pos, instack[pos] = true;
	for (int i = 1; i <= tot; i++)
		if (edge[pos][i]) {
			if (dfn[i] == 0) {
				work(i);
				chkmin(low[pos], low[i]);
			} else if (instack[i]) chkmin(low[pos], dfn[i]);
		}
	if (low[pos] == dfn[pos]) {
		int tmp = Stack[top--];
		belong[tmp] = ++cnt;
		instack[tmp] = false;
		while (tmp != pos) {
			tmp = Stack[top--];
			belong[tmp] = cnt;
			instack[tmp] = false;
		}
	}
}
bool check() {
	timer = cnt = 0, memset(dfn, 0, sizeof(dfn));
	for (int i = 1; i <= tot; i++)
		if (dfn[i] == 0) work(i);
	for (int i = 1; i <= n; i++)
		if (belong[point[i][0]] == belong[point[i][1]]) return false;
	return true;
}
void limit(int pos, bool type, int d) {
	edge[point[pos][type ^ 1]][point[pos][type]] += d;
}
int main() {
	scanf("\n%s", s + 1);
	l = strlen(s + 1), read(n), read(m);
	int cnt[2] = {0, 0};
	for (int i = 1; i <= l; i++)
		cnt[s[i] == 'V']++;
	for (int i = 1; i <= n; i++) {
		point[i][0] = ++tot;
		point[i][1] = ++tot;
	}
	if (cnt[0] == 0) {
		for (int i = 1; i <= n; i++)
			limit(i, 1, 1);
	}
	if (cnt[1] == 0) {
		for (int i = 1; i <= n; i++)
			limit(i, 0, 1);
	}
	for (int i = 1; i <= m; i++) {
		int x, y; char tx, ty;
		scanf("%d %c %d %c", &x, &tx, &y, &ty);
		edge[point[x][tx == 'V']][point[y][ty == 'V']]++;
		edge[point[y][ty != 'V']][point[x][tx != 'V']]++;
	}
	scanf("\n%s", lim + 1);
	for (int i = 1; i <= n; i++)
		limit(i, s[lim[i] - 'a' + 1] == 'V', 1);
	if (check()) {
		printf("%s\n", lim + 1);
		return 0;
	}
	for (int i = 1; i <= n; i++)
		limit(i, s[lim[i] - 'a' + 1] == 'V', -1);
	for (int p = n; p >= 1; p--) {
		for (int i = 1; i <= p - 1; i++)
			limit(i, s[lim[i] - 'a' + 1] == 'V', 1);
		int q[2] = {l + 1, l + 1};
		for (int i = l; i >= lim[p] - 'a' + 2; i--)
			q[s[i] == 'V'] = i;
		int nxt = l + 1;
		limit(p, 0, 1);
		if (q[0] != l + 1 && check()) chkmin(nxt, q[0]);
		limit(p, 0, -1);
		limit(p, 1, 1);
		if (q[1] != l + 1 && check()) chkmin(nxt, q[1]);
		limit(p, 1, -1);
		if (nxt != l + 1) {
			for (int i = 1; i <= p - 1; i++)
				ans[i] = lim[i];
			ans[p] = nxt + 'a' - 1;
			limit(p, s[nxt] == 'V', 1);
			int r[2] = {l + 1, l + 1};
			for (int i = l; i >= 1; i--)
				r[s[i] == 'V'] = i;
			for (int i = p + 1; i <= n; i++) {
				ans[i] = l + 'a';
				limit(i, 0, 1);
				if (r[0] != l + 1 && check()) chkmin(ans[i], (char) (r[0] + 'a' - 1));
				limit(i, 0, -1);
				limit(i, 1, 1);
				if (r[1] != l + 1 && check()) chkmin(ans[i], (char) (r[1] + 'a' - 1));
				limit(i, 1, -1);
				limit(i, s[ans[i] - 'a' + 1] == 'V', 1);
			}
			printf("%s\n", ans + 1);
			return 0;
		}
		for (int i = 1; i <= p - 1; i++)
			limit(i, s[lim[i] - 'a' + 1] == 'V', -1);
	}
	puts("-1");
	return 0;
}