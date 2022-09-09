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
char s[MAXN];
int main() {
	int n; read(n);
	scanf("%s", s + 1);
	int x = 0, y = 0, ans = 0;
	for (int i = 1; i <= n; i++) {
		if (x == y && s[i] == s[i - 1]) ans++;
		if (s[i] == 'U') y++;
		else x++;
	}
	cout << ans << endl;
	return 0;
}