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
int main() {
	int n; read(n);
	int al = 0, ar = 1e9;
	int bl = 0, br = 1e9;
	for (int i = 1; i <= n; i++) {
		char s[15];
		if (i & 1) {
			int mid = (al + ar) / 2;
			cout << 0 << ' ' << mid << endl;
			scanf("%s", s);
			if (s[0] == 'b') al = mid;
			else ar = mid;
		} else {
			int mid = (bl + br) / 2;
			cout << 1 << ' ' << mid << endl;
			scanf("%s", s);
			if (s[0] == 'b') bl = mid;
			else br = mid;
		}
	}
	cout << 0 << ' ' << (al + ar) / 2 << ' ' << 1 << ' ' << (bl + br) / 2 << endl;
	return 0;
}