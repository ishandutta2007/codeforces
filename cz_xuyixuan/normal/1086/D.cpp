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
struct BinaryIndexTree {
	int n, a[MAXN];
	void init(int x) {
		n = x;
		memset(a, 0, sizeof(a));
	}
	void modify(int x, int d) {
		for (int i = x; i <= n; i += i & -i)
			a[i] += d;
	}
	int query(int x) {
		int ans = 0;
		for (int i = x; i >= 1; i -= i & -i)
			ans += a[i];
		return ans;
	}
	int query(int l, int r) {
		int ans = 0;
		for (int i = r; i >= 1; i -= i & -i)
			ans += a[i];
		for (int i = l - 1; i >= 1; i -= i & -i)
			ans -= a[i];
		return ans;
	}
} BIT[3];
set <int> st[3];
// 0 : Rock, 1 : Paper, 2 : Scissors
int n, m; char s[MAXN];
int fst(set <int> &st) {
	return *st.begin();
}
int lst(set <int> &st) {
	set <int> :: iterator tmp = st.end(); tmp--;
	return *tmp;
}
int getans() {
	int ans = 0;
	if (st[1].empty()) ans += BIT[0].query(1, n);
	else if (!st[2].empty()) {
		int l = fst(st[2]), r = lst(st[2]);
		int x = fst(st[1]), y = lst(st[1]);
		ans += BIT[0].query(l, r);
		ans += BIT[0].query(1, min(l, x));
		ans += BIT[0].query(max(r, y), n);
	}
	if (st[2].empty()) ans += BIT[1].query(1, n);
	else if (!st[0].empty()) {
		int l = fst(st[0]), r = lst(st[0]);
		int x = fst(st[2]), y = lst(st[2]);
		ans += BIT[1].query(l, r);
		ans += BIT[1].query(1, min(l, x));
		ans += BIT[1].query(max(r, y), n);
	}
	if (st[0].empty()) ans += BIT[2].query(1, n);
	else if (!st[1].empty()) {
		int l = fst(st[1]), r = lst(st[1]);
		int x = fst(st[0]), y = lst(st[0]);
		ans += BIT[2].query(l, r);
		ans += BIT[2].query(1, min(l, x));
		ans += BIT[2].query(max(r, y), n);
	}
	return ans;
}
void add(int pos, char x) {
	int type = 0;
	if (x == 'P') type = 1;
	if (x == 'S') type = 2;
	st[type].insert(pos);
	BIT[type].modify(pos, 1);
}
void del(int pos, char x) {
	int type = 0;
	if (x == 'P') type = 1;
	if (x == 'S') type = 2;
	st[type].erase(pos);
	BIT[type].modify(pos, -1);
}
int main() {
	read(n), read(m);
	scanf("%s", s + 1);
	for (int i = 0; i <= 2; i++)
		BIT[i].init(n);
	for (int i = 1; i <= n; i++)
		add(i, s[i]);
	writeln(getans());
	for (int i = 1; i <= m; i++) {
		int pos; char opt;
		scanf("%d %c", &pos, &opt);
		del(pos, s[pos]);
		add(pos, opt), s[pos] = opt;
		writeln(getans());
	}
	return 0;
}