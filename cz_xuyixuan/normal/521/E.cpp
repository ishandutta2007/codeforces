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
bool instack[MAXN], ine[MAXN], key[MAXN], thr[MAXN], vis[MAXN];
vector <pair <int, int>> a[MAXN];
int n, m, timer, dfn[MAXN], low[MAXN];
int top, Stack[MAXN], se[MAXN], cnte[MAXN];
void getans(int pos, int fa, int dest, vector <int> &cur) {
	if (pos == dest) {
		cout << cur.size();
		for (auto x : cur) printf(" %d", x);
		printf("\n");
		return;
	}
	for (auto x : a[pos])
		if (x.first != fa && ine[x.second]) {
			cur.push_back(x.first);
			getans(x.first, pos, dest, cur);
			cur.pop_back();
		}
}
void findpath(int pos, vector <int> &cur) {
	if (instack[pos]) {
		cout << cur.size();
		assert(pos != cur[0]);
		for (auto x : cur) printf(" %d", x);
		printf("\n");
		vector <int> tmp = {cur[0]};
		getans(cur[0], 0, cur.back(), tmp);
		exit(0);
	}
	vis[pos] = true;
	for (auto x : a[pos])
		if (key[x.first] && !vis[x.first] && !ine[x.second] && !thr[x.second]) {
			cur.push_back(x.first);
			thr[x.second] = true;
			findpath(x.first, cur);
			cur.pop_back();
		}
}
void dfs(int pos) {
	instack[pos] = true;
	Stack[++top] = pos;
	for (auto x : a[pos])
		if (!ine[x.second]) {
			ine[x.second] = true;
			se[top] = x.second;
			if (instack[x.first]) {
				for (int i = 1; i <= top; i++) {
					if (Stack[i] == x.first) break;
					instack[Stack[i]] = false;
					ine[se[i]] = false;
				}
				for (int i = 1; i <= n; i++) {
					if (!instack[i]) continue;
					for (auto y : a[i])
						if (key[y.first] && !ine[y.second]) {
							thr[y.second] = true;
							vector <int> cur = {i, y.first};
							vis[i] = true;
							findpath(y.first, cur);
							assert(false);
						}
				}
				assert(false);
				exit(0);
			} else if (key[x.first]) dfs(x.first);
			ine[x.second] = false;
		}
	top--, instack[pos] = false;
}
void solve(vector <int> s) {
	for (auto x : s) key[x] = true;
	memset(ine, false, sizeof(ine));
	memset(instack, false, sizeof(instack));
	top = 0, dfs(s[0]);
}
void tarjan(int pos) {
	instack[pos] = true;
	dfn[pos] = low[pos] = ++timer;
	Stack[++top] = pos, cnte[top] = 0;
	int upe = 0, tmp = top;
	for (auto x : a[pos]) {
		if (dfn[x.first] == 0) {
			tarjan(x.first);
			chkmin(low[pos], low[x.first]);
			if (dfn[pos] == low[x.first]) {
				vector <int> s = {pos}; int e = 0;
				int tmp = Stack[top];
				s.push_back(tmp), e += cnte[top--];
				while (tmp != x.first) {
					tmp = Stack[top];
					s.push_back(tmp), e += cnte[top--];
				}
				if (e >= s.size() + 1) {
					puts("YES");
					solve(s);
					assert(false);
					exit(0);
				}
			}
		} else chkmin(low[pos], dfn[x.first]), upe += instack[x.first];
	}
	cnte[tmp] = upe;
	instack[pos] = false;
}
int main() {
	read(n), read(m);
	for (int i = 1; i <= m; i++) {
		int x, y; read(x), read(y);
		a[x].emplace_back(y, i);
		a[y].emplace_back(x, i);
	}
	for (int i = 1; i <= n; i++)
		if (dfn[i] == 0) tarjan(i);
	puts("NO");
	return 0;
}