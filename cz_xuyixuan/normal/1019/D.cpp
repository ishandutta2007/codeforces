#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2005;
const int MAXM = 4e6 + 5;
const double pi = acos(-1);
const double eps = 1e-9;
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
struct info {double angle; int x, y; };
long long s; int n, home[MAXN]; 
posi a[MAXN]; info b[MAXM];
void solve(int x, int y) {
	point delta = a[home[y]].pos - a[home[x]].pos;
	int l = home[y] + 1, r = n;
	while (l <= r) {
		int mid = (l + r) / 2;
		long long tmp = abs(delta * (a[mid].pos - a[home[x]].pos));
		if (tmp == s) {
			printf("Yes\n");
			printf("%d %d\n", a[home[x]].pos.x, a[home[x]].pos.y);
			printf("%d %d\n", a[home[y]].pos.x, a[home[y]].pos.y);
			printf("%d %d\n", a[mid].pos.x, a[mid].pos.y);
			exit(0);
		}
		if (tmp < s) l = mid + 1;
		else r = mid - 1;
	}
}
void Swap(int x, int y) {
	if (home[x] != home[y] - 1) {
		printf("Wrong!\n");
		exit(0);
	}
	swap(home[x], home[y]);
	swap(a[home[x]], a[home[y]]);
}
bool cmp(posi a, posi b) {
	return a.pos < b.pos;
}
bool cnp(info a, info b) {
	return a.angle < b.angle;
}
int main() {
	read(n), read(s); s *= 2;
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
			b[++tot] = (info) {atan2(tmp.y, tmp.x), i, j};
		}
	sort(b + 1, b + tot + 1, cnp);
	for (int i = 1, tmp; i <= tot; i = tmp) {
		tmp = i;
		while (tmp <= tot && fabs(b[tmp].angle - b[i].angle) <= eps) tmp++;
		for (int j = i; j <= tmp - 1; j++)
			solve(b[j].y, b[j].x);
		for (int j = i; j <= tmp - 1; j++)
			Swap(b[j].y, b[j].x);
	}
	printf("No\n");
	return 0;
}