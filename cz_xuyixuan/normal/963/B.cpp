#include<bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
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
vector <int> a[MAXN], b[MAXN];
int tot, ans[MAXN];
void finish(int pos) {
	ans[++tot] = pos;
	for (unsigned i = 0; i < b[pos].size(); i++)
		finish(b[pos][i]);
}
int work(int pos, int fa) {
	int degree = fa != 0;
	for (unsigned i = 0; i < a[pos].size(); i++)
		if (a[pos][i] != fa) degree += work(a[pos][i], pos);
	if (degree % 2 == 0) {
		finish(pos);
		return 0;
	} else {
		b[fa].push_back(pos);
		return 1;
	}
}
int main() {
	int n; read(n);
	for (int i = 1; i <= n; i++) {
		int x; read(x);
		if (x != 0) {
			a[x].push_back(i);
			a[i].push_back(x);
		}
	}
	if (work(1, 0)) printf("NO\n");
	else {
		printf("YES\n");
		for (int i = 1; i <= n; i++)
			writeln(ans[i]);
	}
	return 0;
}