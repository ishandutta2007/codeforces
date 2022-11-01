#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdio> 

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define mp(i, j) make_pair(i, j)
#define rs(j) resize((j))
#define pb push_back
#define pp pop_back
#define len(s) (int)s.length()
#define sz(a) (int)a.size()
#define re  return
#define fi first
#define se second

typedef long long ll;
typedef long double ld;
using namespace std;

const ll mod = 998244353;
const ld eps = 1e-9;
struct point{
    ld x, y;
};

struct circle{
	point o;
	ld r;
};

const ld pi = 2.0 * acos(0);

vector<circle> qq;
vector<pair<ld, ld> > aa;
circle pp;

ld dist(point a, point b) {
	re sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

void myassert() {
	while(true);
}

bool func(circle a, circle b) {
	ld D = dist(a.o, b.o);
	if (D + eps > a.r + b.r) re false;
	if (D + b.r < a.r + eps) {
		//aa.push_back(mp(pi, pi + eps));
		//aa.push_back(mp(pi, pi + eps));
		re true;
	} 
	if (D + a.r < b.r + eps) {
		re false;
	}
//	if (abs(D) < eps) myassert();
	ld p = (a.r * a.r - b.r * b.r) / D;
	ld d1 = (D + p) / 2.0;
	ld alpha = acos(d1 / a.r), alpha1 = atan2(b.o.y - a.o.y, (b.o.x - a.o.x));
	ld l = alpha1 - alpha, r = alpha1 + alpha;
	if (l < 0) l += 2.0 * pi, r += 2.0 * pi;
	if (l > r) r += 2.0 * pi;
	if (r - l > pi) {
		swap(l, r);
		if (l > r) r += 2.0 * pi;
		if (l >= 2.0 * pi) l -= 2.0 * pi, r -= 2.0 * pi; 
	}
	r += eps;
	aa.push_back(mp(l, r));
	aa.push_back(mp(l + 2.0  * pi, r + 2.0 * pi));
	re false;
}

ld a;
bool ccc;

bool ok(ld mid) {
	aa.resize(0);
	pp = {{a, 0}, mid};
	forn (i, sz(qq)) {
		bool o = func(pp, qq[i]);
		if (o) re true;
	} 
	vector<pair<ld, int> > q;
	forn (i, sz(aa)) {
		q.push_back(mp(aa[i].fi, i + 1));
		q.push_back(mp(aa[i].se, -i - 1));
	}
	sort(q.begin(), q.end());
	vector<int> cc;
	forn (i, sz(q)) {
		//if (i && abs(q[i].fi - q[i - 1].fi) < eps / 2.0 && abs(q[i].se) != abs(q[i - 1].se)) re true;
		if (q[i].se > 0) {
			cc.push_back(q[i].se);
			continue;
		}
		if (cc[sz(cc) - 1] != -q[i].se) re true;
		cc.pop_back();
	}
	re false;
		
}

int main() {
    iostream::sync_with_stdio(0); cin.tie(0);
    //freopen("input.txt", "r",  stdin);
    //freopen("bridge.out", "w", stdout);
    int n;
    cin >> n >> a;
    vector<int> x(n), y(n);
    forn (i, n) {
    	cin >> x[i] >> y[i];
    	qq.push_back({{x[i], y[i]}, sqrt(ld((x[i] + a) * (x[i] + a) + y[i] * y[i]))});
	}
	ld l = 0, r = 2. * a;
	forn (i, 40) {
		ld mid = (l + r) / 2.;
		if (ok(mid)) r = mid;
		else l = mid;
		
	}
	cout.precision(30);
	cout << fixed << r;
    return 0;
}