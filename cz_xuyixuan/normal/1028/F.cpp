#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
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
point operator / (point a, int b) {return (point) {a.x / b, a.y / b}; }
long long moo(point a) {return a.x * a.x + a.y * a.y; }
bool operator < (point a, point b) {
	if (a.x == b.x) return a.y < b.y;
	else return a.x < b.x;
}
int gcd(int x, int y) {
	if (y == 0) return x;
	else return gcd(y, x % y);
}
int n, tot, cnt;
map <point, int> ans;
map <long long, int> mp;
vector <point> a[MAXN];
int main() {
	read(n);
	for (int i = 1; i <= n; i++) {
		int opt; point tmp;
		read(opt), read(tmp.x), read(tmp.y);
		if (opt == 1) {
			cnt++;
			long long tnp = moo(tmp);
			if (mp[tnp] == 0) mp[tnp] = ++tot;
			int pos = mp[tnp];
			ans[tmp / gcd(tmp.x, tmp.y)]++;
			for (unsigned j = 0; j < a[pos].size(); j++) {
				point sum = tmp + a[pos][j];
				sum = sum / gcd(sum.x, sum.y);
				ans[sum] += 2;
			}
			a[pos].push_back(tmp);
		}
		if (opt == 2) {
			cnt--;
			long long tnp = moo(tmp);
			if (mp[tnp] == 0) mp[tnp] = ++tot;
			int pos = mp[tnp];
			ans[tmp / gcd(tmp.x, tmp.y)]--;
			for (unsigned j = 0; j < a[pos].size(); j++)
				if (tmp.x == a[pos][j].x && tmp.y == a[pos][j].y) {
					a[pos].erase(a[pos].begin() + j);
					break;
				}
			for (unsigned j = 0; j < a[pos].size(); j++) {
				point sum = tmp + a[pos][j];
				sum = sum / gcd(sum.x, sum.y);
				ans[sum] -= 2;
			}
		}
		if (opt == 3) writeln(cnt - ans[tmp / gcd(tmp.x, tmp.y)]);
	}
	return 0;
}