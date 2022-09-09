#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1000005;
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
int n, a[MAXN], bit[MAXN];
void modify(int pos) {
	for (int i = pos; i <= n; i += i & -i)
		bit[i] ^= 1;
}
int query(int pos) {
	int ans = 0;
	for (int i = pos; i >= 1; i -= i & -i)
		ans ^= bit[i];
	return ans;
}
int main() {
	read(n);
	for (int i = 1; i <= n; i++)
		read(a[i]);
	int ans = 0;
	for (int i = n; i >= 1; i--) {
		ans ^= query(a[i]);
		modify(a[i]);
	}
	if (n & 1) {
		if (ans & 1) printf("Petr\n");
		else printf("Um_nik\n");
	} else {
		if (ans & 1) printf("Um_nik\n");
		else printf("Petr\n");
	}
	return 0;
}