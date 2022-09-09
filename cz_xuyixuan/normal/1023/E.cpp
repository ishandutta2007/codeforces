#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1005;
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
int n;
char ans[MAXN];
string res;
int main() {
	cin >> n;
	int x = 1, y = 1;
	for (int i = 1; i <= n - 1; i++) {
		cout << '?' << ' ' << x << ' ' << y + 1 << ' ' << n << ' ' << n << endl;
		cin >> res;
		if (res == "YES") ans[i] = 'R', y++;
		else ans[i] = 'D', x++;
	}
	x = n, y = n;
	for (int i = 1; i <= n - 1; i++) {
		cout << '?' << ' ' << 1 << ' ' << 1 << ' ' << x - 1 << ' ' << y << endl;
		cin >> res;
		if (res == "YES") ans[2 * n - 1 - i] = 'D', x--;
		else ans[2 * n - 1 - i] = 'R', y--;
	}
	cout << '!' << ' ' << ans + 1 << endl;
	return 0;
}