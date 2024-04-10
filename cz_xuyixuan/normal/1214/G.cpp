#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2048;
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
set <int> ans;
int n, m, q, nxt[MAXN];
bitset <MAXN> a[MAXN], b[MAXN];
set <pair <int, int>> st;
void del(int x, int y) {
	assert(nxt[x] == y), nxt[x] = 0;
	if ((a[y] | a[x]) != a[y]) ans.erase(x);
}
void ins(int x, int y) {
	assert(nxt[x] == 0), nxt[x] = y;
	if ((a[y] | a[x]) != a[y]) ans.insert(x);
}
void del(int pos) {
	pair <int, int> val = make_pair(a[pos].count(), pos);
	auto tmp = st.lower_bound(val), suf = tmp; suf++;
	if (tmp != st.begin()) {
		auto pre = tmp; pre--;
		del((*pre).second, (*tmp).second);
		if (suf != st.end()) {
			ins((*pre).second, (*suf).second);
		}
	}
	if (suf != st.end()) {
		del((*tmp).second, (*suf).second);
	}
	st.erase(tmp);
}
void ins(int pos) {
	pair <int, int> val = make_pair(a[pos].count(), pos);
	auto tmp = st.insert(val).first, suf = tmp; suf++;
	if (tmp != st.begin()) {
		auto pre = tmp; pre--;
		if (suf != st.end()) {
			del((*pre).second, (*suf).second);
		}
		ins((*pre).second, (*tmp).second);
	}
	if (suf != st.end()) {
		ins((*tmp).second, (*suf).second);
	}
}
int main() {
	read(n), read(m), read(q);
	for (int i = 1; i <= m; i++) {
		b[i] = b[i - 1];
		b[i].set(i);
	}
	for (int i = 1; i <= n; i++)
		ins(i);
	for (int i = 1; i <= q; i++) {
		int x, l, r;
		read(x), read(l), read(r);
		del(x), a[x] ^= b[r] ^ b[l - 1], ins(x);
		if (ans.size()) {
			int x = *ans.begin(), y = nxt[x];
			int l = (a[x] & ~a[y])._Find_first(), r = (~a[x] & a[y])._Find_first();
			if (x > y) swap(x, y);
			if (l > r) swap(l, r);
			printf("%d %d %d %d\n", x, l, y, r);
		} else puts("-1");
	}
	return 0;
}