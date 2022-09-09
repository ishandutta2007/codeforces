#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2005;
const int MAXM = 4e6 + 5;
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
point operator + (point a, point b) {return (point) {a.x + b.x, a.y + b.y}; }
point operator - (point a, point b) {return (point) {a.x - b.x, a.y - b.y}; }
point operator * (point a, int b) {return (point) {a.x * b, a.y * b}; }
long long operator * (point a, point b) {return 1ll * a.x * b.y - 1ll * a.y * b.x; }
bool operator < (point a, point b) {
	if (a.y == b.y) return a.x > b.x;
	else return a.y < b.y;
}
struct posi {point pos; int num; };
struct info {long double angle; int x, y; };
long long ans; int n, home[MAXN]; 
posi a[MAXN]; info b[MAXM];
void Swap(int x, int y) {
	long long tmp = home[x] - 1;
	long long tnp = n - home[y];
	ans += tmp * (tmp - 1) / 2 * tnp * (tnp - 1) / 2;
	swap(home[x], home[y]);
}
bool cmp(posi a, posi b) {
	return a.pos < b.pos;
}
bool cnp(info a, info b) {
	return a.angle < b.angle;
}
int main() {
	read(n);
	for (int i = 1; i <= n; i++)
		read(a[i].pos.x), read(a[i].pos.y);
	sort(a + 1, a + n + 1, cmp);
	for (int i = 1; i <= n; i++)
		a[i].num = i, home[i] = i;
	int tot = 0;
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= n; j++)
		if (i != j) {
			point tmp = a[j].pos - a[i].pos;
			b[++tot] = (info) {atan2l(tmp.y, tmp.x), i, j};
		}
	sort(b + 1, b + tot + 1, cnp);
	for (int i = 1; i <= tot; i++)
		Swap(b[i].y, b[i].x);
	writeln(ans / 2);
	return 0;
}