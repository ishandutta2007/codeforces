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
int n; char s[MAXN], t[MAXN];
bool check(int x) {
	int m = 0;
	for (int i = x + 1; i <= n; i++)
		t[++m] = s[i];
	for (int i = 1; i <= x; i++)
		t[++m] = s[i];
	for (int i = 1; i <= n; i++)
		if (t[i] != t[n - i + 1]) return false;
	bool flg = false;
	for (int i = 1; i <= n; i++)
		flg |= s[i] != t[i];
	return flg;
}
int main() {
	scanf("%s", s + 1);
	n = strlen(s + 1);
	bool flg = true;
	for (int i = 1; i <= n; i++)
		if (i * 2 - 1 != n && s[i] != s[1]) {
			flg = false;
			break;
		}
	if (flg) {
		puts("Impossible");
		return 0;
	}
	for (int i = 1; i <= n - 1; i++)
		if (check(i)) {
			puts("1");
			return 0;
		}
	puts("2");
	return 0;
}