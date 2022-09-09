#include<bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
const int MAXC = 26;
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
struct SuffixAutomaton {
	int root, size, last;
	int child[MAXN][MAXC];
	int fail[MAXN], depth[MAXN], num[MAXN];
	vector <int> a[MAXN];
	int newnode(int dep) {
		fail[size] = 0;
		depth[size] = dep;
		memset(child[size], 0, sizeof(child[size]));
		return size++;
	}
	void extend(int ch, int pos) {
		int p = last, np = newnode(depth[last] + 1);
		while (child[p][ch] == 0) {
			child[p][ch] = np;
			p = fail[p];
		}
		if (child[p][ch] == np) fail[np] = root;
		else {
			int q = child[p][ch];
			if (depth[q] == depth[p] + 1) fail[np] = q;
			else {
				int nq = newnode(depth[p] + 1);
				fail[nq] = fail[q];
				fail[q] = fail[np] = nq;
				memcpy(child[nq], child[q], sizeof(child[q]));
				while (child[p][ch] == q) {
					child[p][ch] = nq;
					p = fail[p];
				}
			}
		}
		num[last = np] = pos;
	}
	void init(char *s) {
		size = 0;
		root = last = newnode(0);
		int len = strlen(s + 1);
		for (int i = 1; i <= len; i++)
			extend(s[i] - 'a', i);
		for (int i = 1; i < size; i++)
			a[fail[i]].push_back(i);
	}
	int tot, pos[MAXN];
	void dfs(int root) {
		if (num[root]) pos[++tot] = num[root];
		for (unsigned i = 0; i < a[root].size(); i++)
			dfs(a[root][i]);
	}
	int query(int cnt, char *s) {
		int now = root, len = strlen(s + 1);
		for (int i = 1; i <= len; i++)
			if (child[now][s[i] - 'a']) now = child[now][s[i] - 'a'];
			else return -1;
		tot = 0; dfs(now);
		if (tot < cnt) return -1;
		sort(pos + 1, pos + tot + 1);
		int ans = MAXN;
		for (int i = cnt; i <= tot; i++)
			chkmin(ans, pos[i] - pos[i - cnt + 1]);
		return ans + len;
	}
} SAM;
char s[MAXN], t[MAXN];
int main() {
	scanf("%s", s + 1);
	SAM.init(s);
	int q; read(q);
	for (int i = 1; i <= q; i++) {
		int cnt;
		scanf("%d %s", &cnt, t + 1);
		writeln(SAM.query(cnt, t));
	}
	return 0;
}