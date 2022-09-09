#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
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
namespace SuffixAutomaton {
	const int MAXN = 2 * 100005;
	const int MAXC = 26;
	int root, size, last;
	int child[MAXN][MAXC];
	int fail[MAXN], depth[MAXN], cnt[MAXN];
	vector <int> a[MAXN];
	long long ans;
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
	void init(char *s) {
		size = 0;
		root = last = newnode(0);
		int len = strlen(s + 1);
		for (int i = 1; i <= len; i++)
			extend(s[i] - 'a');
	}
	long long f(long long x) {return x * (x + 1) / 2; }
	void work(int pos) {
		for (unsigned i = 0; i < a[pos].size(); i++) {
			work(a[pos][i]);
			cnt[pos] += cnt[a[pos][i]];
		}
		ans += f(cnt[pos]) * (depth[pos] - depth[fail[pos]]);
	}
	void calc() {
		for (int i = 1; i < size; i++)
			a[fail[i]].push_back(i);
		work(0);
		writeln(ans);
	}
}
char s[MAXN];
int main() {
	scanf("%s", s + 1);
	SuffixAutomaton::init(s);
	SuffixAutomaton::calc();
	return 0;
}