#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
const double eps = 1e-12;
const double INF = 1e+10;
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
struct point {double x, y; };
point operator + (point a, point b) {return (point) {a.x + b.x, a.y + b.y}; }
point operator - (point a, point b) {return (point) {a.x - b.x, a.y - b.y}; }
point operator * (point a, double b) {return (point) {a.x * b, a.y * b}; }
double operator * (point a, point b) {return a.x * b.y - a.y * b.x; }
point unit(point a) {
	double moo = sqrt(a.x * a.x + a.y * a.y);
	a.x /= moo, a.y /= moo;
	return a;
}
double dist(point a, point b) {
	a = a - b;
	return sqrt(a.x * a.x + a.y * a.y);
}
int n; bool res; pair <point, point> a[MAXN];
point c[MAXN], d[MAXN]; double v[MAXN];
bool check(pair <point, point> a, pair <point, point> b) {
	if (abs((a.second - a.first) * (b.second - b.first)) <= eps) {
		return fabs((a.second - a.first) * (b.first - a.first)) <= eps
		    && dist(a.first, b.first) + dist(a.second, b.second) - dist(a.first, b.second) - dist(a.second, b.first) < -eps;
	} else {
		return ((a.first - b.first) * (a.second - b.first)) * ((a.first - b.second) * (a.second - b.second)) <= eps
		    && ((b.first - a.first) * (b.second - a.first)) * ((b.first - a.second) * (b.second - a.second)) <= eps;
	}
}
double timer;
struct info {int home; };
double gety(int i, double x) {
	return a[i].first.y + (x - a[i].first.x) / (a[i].second.x - a[i].first.x) * (a[i].second.y - a[i].first.y);
}
bool operator < (info a, info b) {
	double tx = gety(a.home, timer);
	double ty = gety(b.home, timer);
	if (fabs(tx - ty) <= eps) return a.home < b.home;
	else return tx < ty;
}
set <info> st;
bool cmp(int x, int y) {
	double tx = (x > 0) ? a[x].first.x : a[-x].second.x;
	double ty = (y > 0) ? a[y].first.x : a[-y].second.x;
	if (fabs(tx - ty) <= eps) return x < y;
	else return tx < ty;
}
bool check() {
	res = false;
	static int event[MAXN];
	for (int i = 1; i <= n; i++) {
		if (a[i].first.x > a[i].second.x) swap(a[i].first, a[i].second);
		event[i] = i, event[i + n] = -i;
	}
	sort(event + 1, event + n * 2 + 1, cmp);

	timer = 0, st.clear();
	for (int i = 1; i <= n * 2 && !res; i++) {
		int cur = event[i];
		if (cur > 0) {
			timer = a[cur].first.x;
			auto tmp = st.insert((info) {cur}).first;
			if (tmp != st.begin()) {
				auto pre = tmp; pre--;
				res |= check(a[(*pre).home], a[(*tmp).home]);
			}
			auto suf = tmp; suf++;
			if (suf != st.end()) {
				res |= check(a[(*suf).home], a[(*tmp).home]);
			}
		} else {
			cur = -cur;
			timer = a[cur].second.x;
			auto tmp = st.lower_bound((info) {cur});
			if (tmp == st.end() || (*tmp).home != cur) return true;
			if (tmp != st.begin()) {
				auto pre = tmp; pre--;
				auto suf = tmp; suf++;
				if (suf != st.end()) {
					res |= check(a[(*suf).home], a[(*pre).home]);
				}
			}
			st.erase(tmp);
		}
	}
	return res;
}
int main() {
	read(n);
	for (int i = 1; i <= n; i++) {
		read(c[i].x), read(c[i].y);
		read(d[i].x), read(d[i].y);
		d[i] = unit(d[i]), read(v[i]);
	}
	double l = 0, r = INF + 1;
	for (int t = 1; t <= 100; t++) {
		double mid = (l + r) / 2;
		for (int i = 1; i <= n; i++) {
			a[i].first = c[i];
			a[i].second = c[i] + d[i] * (v[i] * mid);
		}
		if (check()) r = mid;
		else l = mid;
	}
	if (l > INF) puts("No show :(");
	else printf("%.10lf\n", (l + r) / 2);
	return 0;
}