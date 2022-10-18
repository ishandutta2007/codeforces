#include <bits/stdc++.h>
#define ef else if
#define mp(x, y) make_pair(x, y)

using namespace std;

typedef long long _;
typedef string str;
typedef pair<_, _> _p;
typedef vector<_> v_;
typedef const long long constant;

constant maxn = 2E5+8;

_ n, m, a[maxn], b[maxn], o[maxn], cx, cy, px[maxn], py[maxn];
_p c[maxn];
vector<_p> g, h;
struct qr {
	_ x, id;
	bool operator < (const qr &b) const {
		return x < b.x;
	}
} d[maxn];

bool cmp(_p x, _p y);
int main() {

	scanf("%lld", &n);
	for(_ i = 1; i <= n; ++i) scanf("%lld", &a[i]);
	for(_ i = 1; i <= n; ++i) scanf("%lld", &b[i]);
	scanf("%lld", &m);
	for(_ i = 1; i <= m; ++i) {
		scanf("%lld", &d[i].x);
		d[i].id = i;
	}
	sort(d+1, d+1+m);
	for(_ i = 1; i <= n; ++i) c[i].first = a[i];
	for(_ i = 1; i <= n; ++i) {
		c[i].first -= a[1];
		c[i].second = 1;
	}
	g.push_back(mp(-a[1], 1));
	for(_ i = 2; i <= n; ++i) {
		_p dl = c[i];
//		printf("dl = %lld %lld\n", dl.first, dl.second);
		dl.first *= -1;
		dl.second *= -1;
		dl.first += b[i];
		g.push_back(dl);
		for(_ j = i; j <= n; j += i) {
			c[j].first += dl.first;
			c[j].second += dl.second;
		}
	}
	for(_p & i : g) if(i.second < 0) {
		i.first *= -1;
		i.second *= -1;
	}
//	for(_p i : g) printf("g has %lld %lld\n", i.first, i.second);
	h.push_back(mp(-1, -1));
	for(_p i : g) if(i.first >= 0) {
		cx += i.first;
		cy += i.second;
	} ef(i.second == 0) cx -= i.first;
	else {
		i.first *= -1;
		h.push_back(i);
	}
//	printf("cx = %lld, cy = %lld\n", cx, cy);
	sort(h.begin()+1, h.end());
//	for(_p i : h) printf("h has %lld %lld\n", i.first, i.second);
	for(_ i = 1; i < (_)h.size(); ++i) {
		px[i] = px[i-1]+h[i].first;
		py[i] = py[i-1]+h[i].second;
//		printf("i = %lld, px = %lld, py = %lld\n", i, px[i], py[i]);
	}
	_ p = 0;
	for(_ i = 1; i <= m; ++i) {
//		printf("treating i = %lld, id = %lld, x = %lld\n", i, d[i].id, d[i].x);
		o[d[i].id] += cx+cy*d[i].x;
		for(; p+1 < (_)h.size() && -h[p+1].first+d[i].x*h[p+1].second >= 0; ) ++p;
//		printf("p = %lld\n", p);
		if(p) o[d[i].id] += -px[p]+py[p]*d[i].x;
		if(p != (_)h.size()-1) o[d[i].id] += px[(_)h.size()-1]-px[p]-(py[(_)h.size()-1]-py[p])*d[i].x;
	}
	for(_ i = 1; i <= m; ++i) printf("%lld\n", o[i]);

	return 0;
}

bool cmp(_p x, _p y) {
	return x.second*y.first < y.second*x.first;
}