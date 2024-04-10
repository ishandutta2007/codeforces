#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
typedef long long ll;
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
struct point {ll x, y; } a[MAXN];
point operator + (point a, point b) {return (point) {a.x + b.x, a.y + b.y}; }
point operator - (point a, point b) {return (point) {a.x - b.x, a.y - b.y}; }
point operator * (point a, int b) {return (point) {a.x * b, a.y * b}; }
long long operator * (point a, point b) {return 1ll * a.x * b.y - 1ll * a.y * b.x; }
bool operator < (point a, point b) {
	if (a.x == b.x) return a.y < b.y;
	else return a.x > b.x;
}
int main() {
	int n; read(n);
	for (int i = 1; i <= n; i++) {
		ll x, y; read(x), read(y);
		a[i] = (point) {x, y - x * x};
	}
	sort(a + 1, a + n + 1);
	int top = 1;
	for (int i = 2; i <= n; i++) {
		if (a[top].x == a[i].x) top--;
		while (top >= 2 && (a[top] - a[top - 1]) * (a[i] - a[top - 1]) <= 0) top--;
		a[++top] = a[i];
	}
	printf("%d\n", top - 1);
	return 0;
}