#include<bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
const int INF = 1e9;
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
struct point {int x, y; };
point min(point a, point b) {return (point) {min(a.x, b.x), min(a.y, b.y)}; }
point max(point a, point b) {return (point) {max(a.x, b.x), max(a.y, b.y)}; }
point l[MAXN], r[MAXN], prel[MAXN], prer[MAXN], sufl[MAXN], sufr[MAXN];
int n;
int main() {
	read(n);
	for (int i = 1; i <= n; i++) {
		read(l[i].x), read(l[i].y);
		read(r[i].x), read(r[i].y);
	}
	prel[0] = sufl[n + 1] = (point) {-INF, -INF};
	prer[0] = sufr[n + 1] = (point) {INF, INF};
	for (int i = 1; i <= n; i++) {
		prel[i] = max(prel[i - 1], l[i]);
		prer[i] = min(prer[i - 1], r[i]);
	}
	for (int i = n; i >= 1; i--) {
		sufl[i] = max(sufl[i + 1], l[i]);
		sufr[i] = min(sufr[i + 1], r[i]);
	}
	for (int i = 1; i <= n; i++) {
		point tl = max(prel[i - 1], sufl[i + 1]);
		point tr = min(prer[i - 1], sufr[i + 1]);
		if (tl.x <= tr.x && tl.y <= tr.y) {
			printf("%d %d\n", tl.x, tl.y);
			return 0;
		}
	}
	return 0;
}