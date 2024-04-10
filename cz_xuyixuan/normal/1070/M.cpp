#include<bits/stdc++.h>
using namespace std;
const int MAXN = 3e3 + 5;
const double pi = acos(-1);
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
point operator + (point a, point b) {return (point) {a.x + b.x, a.y + b.y}; }
point operator - (point a, point b) {return (point) {a.x - b.x, a.y - b.y}; }
point operator * (point a, int b) {return (point) {a.x * b, a.y * b}; }
long long operator * (point a, point b) {return 1ll * a.x * b.y - 1ll * a.y * b.x; }
double PolarAngle(point a) {return atan2(a.y, a.x); }
int n, m, r[MAXN]; point a[MAXN], b[MAXN];
void work(vector <int> sa, vector <pair <int, int>> sb) {
	while (true) {
		if (sa.size() == 1) {
			for (auto x : sb)
				printf("%d %d\n", x.first, sa[0]);
			return;
		}
		if (sb.size() == 1) {
			for (auto x : sa)
				printf("%d %d\n", sb[0].first, x);
			return;
		}
		for (unsigned i = 0; i < sb.size(); i++)
			if (sb[i].second >= sb[0].second) swap(sb[i], sb[0]);
		pair <double, pair <int, int>> tmp[MAXN * 4]; int cnt = 0;
		for (unsigned i = 0; i < sa.size(); i++)
			tmp[++cnt] = make_pair(PolarAngle(a[sa[i]] - b[sb[0].first]), make_pair(sa[i], 0));
		for (unsigned i = 1; i < sb.size(); i++)
			tmp[++cnt] = make_pair(PolarAngle(b[sb[i].first] - b[sb[0].first]), sb[i]);
		sort(tmp + 1, tmp + cnt + 1);
		for (int i = 1; i <= cnt; i++) {
			tmp[cnt + i] = tmp[i];
			tmp[cnt + i].first += 2 * pi;
		}
		for (int i = 1, j = 0, v = 0; i <= cnt; v -= 1 - tmp[i++].second.second) {
			if (v >= 1 && v <= sb[0].second - 1) {
				vector <int> xa;
				vector <pair <int, int>> xb;
				xb.emplace_back(sb[0].first, v);
				sb[0].second = sb[0].second - v;
				sb.resize(1), sa.clear();
				for (int k = i; k <= j; k++)
					if (tmp[k].second.second == 0) xa.push_back(tmp[k].second.first);
					else xb.push_back(tmp[k].second);
				for (int k = j + 1; k <= i + cnt - 1; k++)
					if (tmp[k].second.second == 0) sa.push_back(tmp[k].second.first);
					else sb.push_back(tmp[k].second);
				if (xa.size() + xb.size() > sa.size() + sb.size()) {
					swap(xa, sa);
					swap(xb, sb);
				}
				work(xa, xb);
				break;
			}
			while (tmp[j + 1].first - tmp[i].first <= pi) v += 1 - tmp[++j].second.second;
			if (v >= 1 && v <= sb[0].second - 1) {
				vector <int> xa;
				vector <pair <int, int>> xb;
				xb.emplace_back(sb[0].first, v);
				sb[0].second = sb[0].second - v;
				sb.resize(1), sa.clear();
				for (int k = i; k <= j; k++)
					if (tmp[k].second.second == 0) xa.push_back(tmp[k].second.first);
					else xb.push_back(tmp[k].second);
				for (int k = j + 1; k <= i + cnt - 1; k++)
					if (tmp[k].second.second == 0) sa.push_back(tmp[k].second.first);
					else sb.push_back(tmp[k].second);
				if (xa.size() + xb.size() > sa.size() + sb.size()) {
					swap(xa, sa);
					swap(xb, sb);
				}
				work(xa, xb);
				break;
			}
		}
	}
}
int main() {
	int T; read(T);
	while (T--) {
		read(n), read(m);
		vector <int> sa;
		vector <pair <int, int>> sb;
		for (int i = 1; i <= m; i++)
			read(r[i]);
		for (int i = 1; i <= n; i++) {
			read(a[i].x), read(a[i].y);
			sa.push_back(i);
		}
		for (int i = 1; i <= m; i++) {
			read(b[i].x), read(b[i].y);
			sb.emplace_back(i, r[i]);
		}
		puts("YES");
		work(sa, sb);
	}
	return 0;
}