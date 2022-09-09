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
struct point {int x, y; };
bool operator == (point a, point b) {return a.x == b.x && a.y == b.y; }
point operator + (point a, point b) {return (point) {a.x + b.x, a.y + b.y}; }
point operator - (point a, point b) {return (point) {a.x - b.x, a.y - b.y}; }
point operator * (point a, int b) {return (point) {a.x * b, a.y * b}; }
long long operator * (point a, point b) {return 1ll * a.x * b.y - 1ll * a.y * b.x; }
long long dist(point a) {return 1ll * a.x * a.x + 1ll * a.y * a.y; }
int n, top; point a[MAXN], s[MAXN];
vector <point> p[MAXN];
bool check(vector <point> a) {
	static point s[MAXN]; int top;
	s[top = 1] = a[0];
	for (unsigned i = 1; i < a.size(); i++) {
		while (top >= 2 + (a[i] == s[1]) && (a[i] - s[top]) * (s[top] - s[top - 1]) >= 0) top--;
		s[++top] = a[i];
	}
	for (int i = 2; i <= top - 1; i++)
		if (s[i].x % 2 || s[i].y % 2) {
			return true;
		}
	return false;
}
int main() {
	read(n);
	bool flg = false;
	for (int i = 1; i <= n; i++) {
		read(a[i].x), read(a[i].y);
		if (a[i].x + a[i].y == 0) flg = true;
	}
	if (!flg) a[++n] = (point) {0, 0};
	sort(a + 1, a + n + 1, [&] (point a, point b) {
		if (a * b == 0) return dist(a) < dist(b);
		else return a * b > 0;
	});
	s[top = 1] = (point) {0, 0};
	for (int i = 2; i <= n + 1; i++) {
		while (top >= 2 + (a[i] == s[1]) && (a[i] - s[top]) * (s[top] - s[top - 1]) >= 0) top--;
		s[++top] = a[i];
	}
	int pos = 1;
	for (int i = 1; i <= n + 1; i++) {
		if (a[i] == s[pos]) pos++;
		else p[pos].push_back(a[i]);
	}
	for (int i = 2; i <= top - 1; i++)
		if (s[i].x % 2 || s[i].y % 2) {
			puts("Ani");
			return 0;
		}
	for (int i = 1, j = 3; j <= top; i++, j++) {
		vector <point> tmp;
		tmp.push_back(s[i]);
		for (auto x : p[j - 1]) tmp.push_back(x);
		for (auto x : p[j]) tmp.push_back(x);
		tmp.push_back(s[j]);
		if (check(tmp)) {
			puts("Ani");
			return 0;
		}
	}
	puts("Borna");
	return 0;
}