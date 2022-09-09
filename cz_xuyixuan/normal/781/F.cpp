#include<bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
const double eps = 1e-15;
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
struct point {double x, y; };
point operator + (point a, point b) {return (point) {a.x + b.x, a.y + b.y}; }
point operator - (point a, point b) {return (point) {a.x - b.x, a.y - b.y}; }
point operator * (point a, double b) {return (point) {a.x * b, a.y * b}; }
double operator * (point a, point b) {return a.x * b.y - a.y * b.x; }
double operator / (point a, point b) {
	if (abs(b.x) > eps) return a.x / b.x;
	else return a.y / b.y;
}
double moo(point a) {return sqrt(a.x * a.x + a.y * a.y); }
point unit(point a) {return a * (1.0 / moo(a)); }
double dist(point a, point b) {return moo(b - a); }
point p[MAXN];
int n, m; double c;
void advance(int &from, int &to, point &pos, double dis) {
	if (dist(pos, p[to]) < eps) from++, to++;
	while (dis > eps) {
		point dir = unit(p[to] - p[from]);
		double len = min(dis, dist(p[to], pos));
		pos = pos + dir * len;
		if (dist(pos, p[to]) < eps) from++, to++;
		dis -= len;
	}
}
bool check(double dis) {
	static vector <pair <double, int> > ans;
	ans.clear();
	int fromx = 1, tox = 2; point x = p[1];
	int fromy = 1, toy = 2; point y = p[1];
	advance(fromy, toy, y, c);
	double nxtshift = c;
	while (fromx != n + 1) {
		double len = min(nxtshift, min(dist(x, p[tox]), dist(y, p[toy])));
		point s = y - x;
		advance(fromx, tox, x, len);
		advance(fromy, toy, y, len);
		point t = y - x;
		double l = (c - nxtshift) / c;
		double r = (c - nxtshift + len) / c;
		if (len > eps) {
			if (dist(s, t) < eps) {
				if (moo(s) <= dis) {
					ans.push_back(make_pair(l + eps, 1));
					ans.push_back(make_pair(r - eps, -1));
				}
			} else {
				if (moo(s) <= dis && moo(t) <= dis) {
					ans.push_back(make_pair(l + eps, 1));
					ans.push_back(make_pair(r - eps, -1));
				} else {
					point o = (point) {0, 0}, v = t - s;
					swap(v.x, v.y); v.x *= -1;
					double e = (s - o) * (t - o);
					double f = (t - v) * (s - v);
					point pos = (o * f + v * e) * (1 / (e + f));
					double postoline = moo(pos);
					if (postoline < dis) {
						double tmp = sqrt(dis * dis - postoline * postoline);
						point posl = pos + unit(s - t) * tmp;
						point posr = pos + unit(t - s) * tmp;
						double vl = (posl - s) / (t - s);
						double vr = (posr - s) / (t - s);
						chkmax(vl, 0.0);
						chkmax(vr, 0.0);
						chkmin(vl, 1.0);
						chkmin(vr, 1.0);
						ans.push_back(make_pair(l + (r - l) * vl + eps, 1));
						ans.push_back(make_pair(l + (r - l) * vr - eps, -1));
					}
				}
			}
		}
		nxtshift -= len;
		if (nxtshift < eps) nxtshift = c;
	}
	sort(ans.begin(), ans.end());
	int sum = 0;
	for (unsigned i = 0; i < ans.size(); i++) {
		sum += ans[i].second;
		if (sum == m) return true;
	}
	return false;
}
int main() {
	//freopen("F.in", "r", stdin);
	//freopen("F.out", "w", stdout);
	read(n), read(m);
	for (int i = 1; i <= n; i++) {
		read(p[i].x), read(p[i].y);
		p[i + n] = p[i];
	}
	for (int i = 1; i <= n; i++)
		c += dist(p[i], p[i + 1]);
	c /= m;
	double l = 0, r = c;
	while (l + 1e-10 < r) {
		double mid = (l + r) / 2;
		if (check(mid)) r = mid;
		else l = mid;
	}
	printf("%.10lf\n", (l + r) / 2);
	return 0;
}