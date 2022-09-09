#include<bits/stdc++.h>
using namespace std;
const int MAXN = 300005;
const int P = 1e9 + 7;
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
		int father, depth, cnt[3];
	} a[MAXN * 2];
	int last, root, size;
	vector <int> b[MAXN * 2];
	int newnode(int depth) {
		a[size].depth = depth;
		return size++;
	}
	void init() {
		size = 0;
		last = root = newnode(0);
	}
	void extend(int ch, int type) {
		int p = last, np;
		if (a[p].child[ch] == 0) {
			np = newnode(a[p].depth + 1);
			while (a[p].child[ch] == 0) {
				a[p].child[ch] = np;
				p = a[p].father;
			}
			if (a[p].child[ch] == np) a[np].father = root;
			else {
				int q = a[p].child[ch];
				if (a[p].depth + 1 == a[q].depth) a[np].father = q;
				else {
					int nq = newnode(a[p].depth + 1);
					memcpy(a[nq].child, a[q].child, sizeof(a[q].child));
					a[nq].father = a[q].father;
					a[q].father = a[np].father = nq;
					while (a[p].child[ch] == q) {
						a[p].child[ch] = nq;
						p = a[p].father;
					}
				}
			}
		} else {
			int q = a[p].child[ch];
			if (a[p].depth + 1 == a[q].depth) np = q;
			else {
				np = newnode(a[p].depth + 1);
				memcpy(a[np].child, a[q].child, sizeof(a[q].child));
				a[np].father = a[q].father;
				a[q].father = np;
				while (a[p].child[ch] == q) {
					a[p].child[ch] = np;
					p = a[p].father;
				}
			}
		}
		a[last = np].cnt[type]++;
	}
	void insert(char *s, int type) {
		int len = strlen(s + 1); last = root;
		for (int i = 1; i <= len; i++)
			extend(s[i] - 'a', type);
	}
	void work(int pos) {
		for (unsigned i = 0; i < b[pos].size(); i++) {
			work(b[pos][i]);
			for (int j = 0; j <= 2; j++)
				a[pos].cnt[j] += a[b[pos][i]].cnt[j];
		}
	}
	void getans(long long *ans, int Min) {
		for (int i = 1; i < size; i++)
			b[a[i].father].push_back(i);
		work(0);
		for (int i = 1; i < size; i++) {
			long long tmp = 1ll * a[i].cnt[0] * a[i].cnt[1] * a[i].cnt[2];
			ans[a[i].depth] += tmp;
			ans[a[a[i].father].depth] -= tmp;
		}
		for (int i = Min - 1; i >= 1; i--)
			ans[i] += ans[i + 1];
	}
} SAM;
char s[MAXN];
int len, Min;
long long ans[MAXN];
int main() {
	SAM.init();
	for (int i = 0; i <= 2; i++) {
		scanf("%s", s + 1);
		SAM.insert(s, i);
		if (i == 0) Min = strlen(s + 1);
		else chkmin(Min, (int) strlen(s + 1));
	}
	SAM.getans(ans, Min);
	for (int i = 1; i <= Min; i++)
		write(ans[i] % P), putchar(' ');
	return 0;
}