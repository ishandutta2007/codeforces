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
int n, m, timer, dfn[MAXN], low[MAXN];
int tot, belong[MAXN], top, Stack[MAXN];
vector <int> a[MAXN], b[MAXN], s[MAXN];
bool instack[MAXN]; int d[MAXN];
void tarjan(int pos) {
	dfn[pos] = low[pos] = ++timer;
	Stack[++top] = pos;
	instack[pos] = true;
	for (auto x : a[pos]) {
		if (!dfn[x]) {
			tarjan(x);
			chkmin(low[pos], low[x]);
		} else if (instack[x]) chkmin(low[pos], dfn[x]);
	}
	if (low[pos] == dfn[pos]) {
		int tmp = Stack[top--];
		instack[tmp] = false;
		belong[tmp] = ++tot;
		while (tmp != pos) {
			tmp = Stack[top--];
			instack[tmp] = false;
			belong[tmp] = tot;
		}
	}
	
}
int main() {
	read(n), read(m);
	for (int i = 1; i <= m; i++) {
		int x, y; read(x), read(y);
		a[x].push_back(y);
	}
	for (int i = 1; i <= n; i++) {
		if (!dfn[i]) tarjan(i);
		s[belong[i]].push_back(i);
		for (auto x : a[i])
			if (belong[i] != belong[x]) {
				b[belong[i]].push_back(belong[x]);
				d[belong[x]]++;
			}
	}
	static int q[MAXN];
	int l = 0, r = -1;
	for (int i = 1; i <= tot; i++)
		if (d[i] == 0) q[++r] = i;
	while (l < r) {
		int x = q[l++], y = q[l++];
		cout << "? " << s[x].back() << ' ' << s[y].back() << endl;
		bool res; read(res);
		if (res) {
			q[--l] = x;
			s[y].pop_back();
			if (s[y].empty()) {
				for (auto p : b[y])
					if (--d[p] == 0) q[++r] = p;
			} else q[--l] = y;
		} else {
			q[--l] = y;
			s[x].pop_back();
			if (s[x].empty()) {
				for (auto p : b[x])
					if (--d[p] == 0) q[++r] = p;
			} else q[--l] = x;
		}
	}
	cout << "! " << s[q[l]].back() << endl;
	return 0;
}