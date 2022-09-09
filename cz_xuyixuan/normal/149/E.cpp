#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2 * 100005;
const int MAXC = 26;
const int INF = 1e7;
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
	int child[MAXN][MAXC], val[MAXN];
	int fail[MAXN], depth[MAXN], cnt[MAXN];
	vector <int> a[MAXN];
	int newnode(int dep) {
		fail[size] = 0;
		depth[size] = dep;
		memset(child[size], 0, sizeof(child[size]));
		return size++;
	}
	void extend(int ch) {
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
		cnt[last = np]++;
	}
	void work(int pos) {
		val[pos] = INF;
		for (unsigned i = 0; i < a[pos].size(); i++) {
			work(a[pos][i]);
			chkmin(val[pos], val[a[pos][i]]);
		}
		if (cnt[pos]) chkmin(val[pos], depth[pos]);
	}
	void init(char *s) {
		size = 0;
		root = last = newnode(0);
		int len = strlen(s + 1);
		for (int i = 1; i <= len; i++)
			extend(s[i] - 'A');
		for (int i = 1; i < size; i++)
			a[fail[i]].push_back(i);
		work(0);
	}
	void match(char *s, int *res) {
		int len = strlen(s + 1);
		int now = root;
		for (int i = 1; i <= len; i++) {
			if (child[now][s[i] - 'A']) now = child[now][s[i] - 'A'];
			else {
				for (int j = i; j <= len; j++)
					res[j] = INF;
				return;
			}
			res[i] = val[now];
		}
	}
} A, B;
int n, m, a[MAXN], b[MAXN];
char s[MAXN], t[MAXN];
int main() {
	scanf("\n%s", s + 1);
	A.init(s);
	n = strlen(s + 1);
	reverse(s + 1, s + n + 1);
	B.init(s);
	read(m);
	int ans = 0;
	while (m--) {
		scanf("\n%s", t + 1);
		int len = strlen(t + 1);
		if (len == 1) continue;
		A.match(t, a);
		reverse(t + 1, t + len + 1);
		B.match(t, b);
		for (int i = 1; i <= len; i++)
			if (a[i] + b[len - i] <= n) {
				ans++;
				break;
			}
	}
	writeln(ans);
	return 0;
}