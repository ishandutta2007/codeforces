#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
typedef long long ll;
typedef __int128 int128;
template <typename T> void chkmax(T &x, T y) {x = max(x, y); }
template <typename T> void chkmin(T &x, T y) {x = min(x, y); } 
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
struct point {ll x, y; };
struct info {ll a, b, c, s; };
int128 operator * (point a, point b) {return (int128) a.x * b.y - (int128) a.y * b.x; };
bool where(point a) {
	return a.x > 0 || (a.x == 0 && a.y > 0);
}
bool operator < (point a, point b) {
	if (where(a) == where(b)) return a * b > 0;
	else return where(a) < where(b);
}
void getinfo(info &x) {
	read(x.a), read(x.b), read(x.c);
	x.s = x.a + x.b + x.c;
}
point a[MAXN];
int n, cntz, cntg; ll cntc;
map <point, int> mp;
point makepoint(info a, info b) {
	ll x = b.a * a.s - b.s * a.a;
	ll y = b.b * a.s - b.s * a.b;
	if (x == 0 && y == 0) return (point) {x, y};
	if (x == 0) return (point) {x, y / abs(y)};
	if (y == 0) return (point) {x / abs(x), y};
	ll g = __gcd(abs(x), abs(y));
	return (point) {x / g, y / g};
}
void addpoint(point x) {
	point r = (point) {-x.x, -x.y};
	if (mp.count(r)) cntc += mp[r];
	if (mp.size() == 0) cntg = 1;
	else if (mp[x] == 0) {
		auto tmp = mp.lower_bound(x);
		auto suf = tmp, pre = tmp; suf++;
		if (suf == mp.end()) suf = mp.begin();
		if (pre == mp.begin()) {pre = mp.end(); } pre--;
		if (pre == suf || (*pre).first * (*suf).first < 0) cntg--;
		if ((*pre).first * (*tmp).first < 0) cntg++;
		if ((*tmp).first * (*suf).first < 0) cntg++;
	}
	mp[x]++;
}
void delpoint(point x) {
	point r = (point) {-x.x, -x.y};
	if (mp.count(r)) cntc -= mp[r];
	if (--mp[x] == 0) {
		if (mp.size() == 1) {
			mp.clear();
			cntg = 0;
		} else {
			auto tmp = mp.lower_bound(x);
			auto suf = tmp, pre = tmp; suf++;
			if (suf == mp.end()) suf = mp.begin();
			if (pre == mp.begin()) {pre = mp.end(); } pre--;
			if (pre == suf || (*pre).first * (*suf).first < 0) cntg++;
			if ((*pre).first * (*tmp).first < 0) cntg--;
			if ((*tmp).first * (*suf).first < 0) cntg--;
			mp.erase(tmp);
		}
	}
}
int main() {
	info k; getinfo(k);
	int T; read(T);
	while (T--) {
		char opt = getchar();
		while (opt != 'A' && opt != 'R') opt = getchar();
		if (opt == 'A') {
			info t; getinfo(t);
			a[++n] = makepoint(k, t);
			if (a[n].x == 0 && a[n].y == 0) cntz++;
			else addpoint(a[n]);
		} else {
			int x; read(x);
			if (a[x].x == 0 && a[x].y == 0) cntz--;
			else delpoint(a[x]);
		}
		if (cntz) puts("1");
		else if (cntc) puts("2");
		else if (cntg || mp.size() == 0) puts("0");
		else puts("3");
	}
	return 0;
}