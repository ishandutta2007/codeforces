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
struct point {int x, y; } a, b, c;
vector <point> ans;
bool operator != (point a, point b) {return a.x != b.x || a.y != b.y; }
int main() {
	read(a.x), read(a.y);
	read(b.x), read(b.y);
	read(c.x), read(c.y);
	while (a != b || b != c || a != c) {
		if (a.x < b.x && a.x < c.x) {
			ans.push_back(a);
			a.x++;
		} else if (a.x > b.x && a.x > c.x) {
			ans.push_back(a);
			a.x--;
		} else if (a.y < b.y && a.y < c.y) {
			ans.push_back(a);
			a.y++;
		} else if (a.y > b.y && a.y > c.y) {
			ans.push_back(a);
			a.y--;
		} else {
			point d = a;
			a = b, b = c, c = d;
		}
	}
	ans.push_back(a);
	writeln(ans.size());
	for (auto x : ans)
		printf("%d %d\n", x.x, x.y);
	return 0;
}