#include<bits/stdc++.h>
using namespace std;
const int MAXN = 55;
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
int n; char s[MAXN];
bool check() {
	for (int i = 1, j = n; i <= j; i++, j--)
		if (s[i] != s[j]) return false;
	return true;
}
int main() {
	scanf("%s", s + 1);
	n = strlen(s + 1);
	bool flg = true;
	for (int i = 1; i <= n; i++)
		flg &= s[i] == s[1];
	if (flg) printf("%d\n", 0);
	else if (check()) printf("%d\n", n - 1);
	else printf("%d\n", n);
	return 0;
}