#include<bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
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
struct info {int limit, value, home; };
info a[MAXN], b[MAXN];
int n, m, ans, lans, Ans[MAXN];
bool cmp(info a, info b) {
	return a.value < b.value;
}
bool check(int x) {
	int lb = 0;
	for (int i = 1; i <= n; i++)
		if (a[i].limit >= x) b[++lb] = a[i];
	if (lb < x) return false;
	sort(b + 1, b + lb + 1, cmp);
	int total = 0;
	for (int i = 1; i <= x; i++)
		total += b[i].value;
	if (total > m) return false;
	lans = x;
	for (int i = 1; i <= x; i++)
		Ans[i] = b[i].home;
	return true;
}
int main() {
	read(n), read(m);
	for (int i = 1; i <= n; i++) {
		read(a[i].limit), read(a[i].value);
		a[i].home = i;
	}
	lans = 0;
	int l = 0, r = n;
	while (l < r) {
		int mid = (l + r + 1) / 2;
		if (check(mid)) l = mid;
		else r = mid - 1;
	}
	printf("%d\n", l);
	printf("%d\n", lans);
	for (int i = 1; i <= lans; i++)
		printf("%d ", Ans[i]);
	return 0;
}