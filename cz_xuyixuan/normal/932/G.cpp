#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
const int P = 1e9 + 7;
const int MAXC = 26;
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
struct PalindromicTree {
	int root, size, last, n, m;
	int f[MAXN], g[MAXN];
	int up[MAXN], delta[MAXN];
	int father[MAXN], depth[MAXN];
	int child[MAXN][MAXC];
	char s[MAXN];
	int newnode(int len) {
		depth[size] = len;
		return size++;
	}
	void extend(int ch) {
		int p = last; ++m;
		while (s[m] != s[m - depth[p] - 1])
			p = father[p];
		if (!child[p][ch]) {
			int np = newnode(depth[p] + 2);
			child[p][ch] = np;
			if (p == root) father[np] = 1;
			else {
				int q = father[p];
				while (s[m] != s[m - depth[q] - 1])
					q = father[q];
				if (child[q][ch] == root) father[np] = 1;
				else father[np] = child[q][ch];
			}
			delta[np] = depth[np] - depth[father[np]];
			up[np] = (delta[np] == delta[father[np]]) ? up[father[np]] : father[np];
		}
		last = child[p][ch];
	}
	void calc(char *t) {
		n = strlen(t + 1); m = 0;
		int l = 1, r = n;
		for (int i = 1; i <= n; i++)
			if (i & 1) s[i] = t[l++];
			else s[i] = t[r--];
		f[0] = 1;
		root = size = 0;
		root = newnode(-1);
		last = newnode(0);
		father[last] = root;
		for (int i = 1; i <= n; i++) {
			extend(s[i] - 'a');
			for (int j = last; depth[j] > 0; j = up[j]) {
				if (father[j] == up[j]) g[j] = f[i - depth[j]];
				else g[j] = (g[father[j]] + f[i - delta[j] - depth[up[j]]]) % P;
				if (i % 2 == 0) f[i] = (f[i] + g[j]) % P;
			}
		}
		writeln(f[n]);
	}
} PT;
char s[MAXN];
int main() {
	scanf("%s", s + 1);
	PT.calc(s);
	return 0;
}