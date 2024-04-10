#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2005;
const int MAXANS = 7005;
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
char s[MAXN], t[MAXN];
vector <int> a[MAXN], b[MAXN];
int n, cnt, ans[MAXANS], val[MAXN];
int vl, vr, l, r;
int find(int x) {
	for (int i = 1; i <= n; i++)
		if (val[i] == x) return i;
	return -1;
}
void operate(int x) {
	ans[++cnt] = x;
	static int tmp[MAXN];
	int len = 0;
	for (int i = 1; i <= x; i++)
		tmp[++len] = val[n - i + 1];
	for (int i = 1; i <= n - x; i++)
		tmp[++len] = val[i];
	for (int i = 1; i <= n; i++) {
		val[i] = tmp[i];
		if (val[i] == vl) l = i;
		if (val[i] == vr) r = i;
	}
}
int main() {
	read(n);
	scanf("\n%s\n%s", s + 1, t + 1);
	for (int i = 1; i <= n; i++) {
		a[s[i] - 'a'].push_back(i);
		b[t[i] - 'a'].push_back(i);
	}
	for (int i = 0; i <= 25; i++)
		if (a[i].size() != b[i].size()) {
			printf("-1\n");
			return 0;
		} else {
			for (unsigned j = 0; j < a[i].size(); j++)
				val[a[i][j]] = b[i][j];
		}
	if (n == 1) {
		printf("0\n");
		return 0;
	}
	vl = (n + 1) / 2, vr = (n + 1) / 2;
	l = find(vl), r = find(vr);
	while (vl != 1 || vr != n) {
		if (r >= l) {
			if (r != n) operate(n - r);
			int tmp = find(vr + 1);
			operate(n - tmp);
			vr++; operate(1);
		} else {
			if (l != n) operate(n - l);
			int tmp = find(vl - 1);
			operate(n - tmp);
			vl--; operate(1);
		}
	}
	if (l >= r) operate(n);
	writeln(cnt);
	for (int i = 1; i <= cnt; i++)
		printf("%d ", ans[i]);
	return 0;
}