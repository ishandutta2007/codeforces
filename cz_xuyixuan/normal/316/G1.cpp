#include<bits/stdc++.h>
using namespace std;
const int MAXN = 15;
const int MAXL = 50005;
const int MAXP = 1200005;
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
	struct Node {
		int child[26];
		int size[MAXN];
		int father, depth;
	} a[MAXP];
	char s[MAXL];
	vector <int> b[MAXP];
	int l[MAXL], r[MAXL];
	int n, len, root, last, size;
	long long ans;
	int newnode(int dep) {
		a[size].depth = dep;
		return size++;
	}
	void extend(int ch, int col) {
		int p = last;
		if (!a[p].child[ch]) {
			int np = newnode(a[p].depth + 1);
			while (!a[p].child[ch]) {
				a[p].child[ch] = np;
				p = a[p].father;
			}
			if (a[p].child[ch] == np) last = np;
			else {
				int q = a[p].child[ch];
				if (a[p].depth + 1 == a[q].depth) a[np].father = q, last = np;
				else {
					int nq = newnode(a[p].depth + 1);
					memcpy(a[nq].child, a[q].child, sizeof(a[q].child));
					a[nq].father = a[q].father;
					a[q].father = a[np].father = nq;
					while (a[p].child[ch] == q) {
						a[p].child[ch] = nq;
						p = a[p].father;
					}
					last = np;
				}
			}
		} else {
			int q = a[p].child[ch];
			if (a[p].depth + 1 == a[q].depth) last = q;
			else {
				int np = newnode(a[p].depth + 1);
				memcpy(a[np].child, a[q].child, sizeof(a[q].child));
				a[np].father = a[q].father;
				a[q].father = np;
				while (a[p].child[ch] == q) {
					a[p].child[ch] = np;
					p = a[p].father;
				}
				last = np;
			}
		}
		a[last].size[col]++;
	}
	void init() {
		size = 0;
		last = root = newnode(0);
		scanf("\n%s", s + 1);
		len = strlen(s + 1);
		for (int i = 1; i <= len; i++)
			extend(s[i] - 'a', 0);
		read(n);
		for (int i = 1; i <= n; i++) {
			last = root;
			scanf("\n%s", s + 1);
			len = strlen(s + 1);
			for (int j = 1; j <= len; j++)
				extend(s[j] - 'a', i);
			read(l[i]), read(r[i]);	
		}
	}
	void work(int pos) {
		for (unsigned i = 0; i < b[pos].size(); i++) {
			int tmp = b[pos][i]; work(tmp);
			for (int j = 0; j <= n; j++)
				a[pos].size[j] += a[tmp].size[j];
		}
		if (pos) {
			bool flg = a[pos].size[0] != 0;
			for (int j = 1; j <= n; j++)
				flg &= a[pos].size[j] >= l[j] && a[pos].size[j] <= r[j];
			ans += flg * (a[pos].depth - a[a[pos].father].depth);
		}
	}
	void calc() {
		for (int i = 1; i < size; i++)
			b[a[i].father].push_back(i);
		work(0);
		writeln(ans);
	}
} SAM;
int main() {
	SAM.init();
	SAM.calc();
	return 0;
}