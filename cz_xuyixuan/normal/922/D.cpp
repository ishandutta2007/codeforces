#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
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
struct info {long long s, h; };
info a[MAXN];
char s[MAXN];
bool cmp(info a, info b) {
	return a.s * b.h > b.s * a.h;
}
int main() {
	int n; read(n);
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%s", s + 1);
		int len = strlen(s + 1);
		info tmp = (info) {0, 0};
		for (int j = 1; j <= len; j++)
			if (s[j] == 's') tmp.s++;
			else tmp.h++, ans += tmp.s;
		a[i] = tmp;
	}
	sort(a + 1, a + n + 1, cmp);
	long long tmp = 0;
	for (int i = 1; i <= n; i++) {
		ans += tmp * a[i].h;
		tmp += a[i].s;
	}
	writeln(ans);
	return 0;
}