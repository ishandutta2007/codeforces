/**** Hyperhydrochloric Acid ****\
|                H    H          |
|                 \  /           |
|             H    Cl            |
|              \  /              |
|   H           Cl               |
|    \          |                |
|     Cl        Cl        H      |
|    /  \      /  \      /       |
|   H    Cl--Cl    Cl--Cl    H   |
|       /      \  /      \  /    |
|      H        Cl        Cl     |
|               |           \    |
|               H            H   |
\********************************/
#include <bits/stdc++.h>
using namespace std;
#define SZ(x)               ((int)(x).size())
#define all(x)              (x).begin(), (x).end()
#define loop(i, n)          for(int i = 0; i < (n); ++i)
#define cont(i, n)          for(int i = 1; i <= (n); ++i)
#define circ(i, a, b)       for(int i = (a); i <= (b); ++i)
#define range(i, a, b, c)   for(int i = (a); ((c) > 0 ? i <= (b) : i >= (b)); i += (c))
#define foreach(it, v)      for(__typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define y0          y0O0OO00OO0OO0OO0OOO00OO0OO0O0O000OO0
#define y1          y1II11II11III11I1III11II111IIII1II1I1
#define pub         push_back
#define pob         pop_back
#define mak         make_pair
typedef long long   ll;
typedef long double lf;
const int   Inf = 0x3f3f3f3f;
const ll    INF = 0x3f3f3f3f3f3f3f3fll;
/* Source code starts here */

struct point {
	ll x, y;
	int c, id;
	point() {}
	point(ll x, ll y, int c = -1, int id = -1): x(x), y(y), c(c), id(id) {}
	inline point operator-() const {return point(-x, -y);}
	inline point operator+(const point &pt) const {return point(x + pt.x, y + pt.y);}
	inline point operator-(const point &pt) const {return point(x - pt.x, y - pt.y);}
	inline point operator*(const ll &a) const {return point(x * a, y * a);}
	inline point operator/(const ll &a) const {return point(x / a, y / a);}
	inline ll operator*(const point &pt) const {return x * pt.y - y * pt.x;}
	inline bool operator<(const point &p) const {return mak(x, y) < mak(p.x, p.y);}
};

int n;
point ps[1005];

vector<int> get_hull() {
	vector<int> res;
	loop(i, n) {
		while(SZ(res) > 1 && (ps[i] - ps[res[SZ(res) - 2]]) * (ps[res.back()] - ps[res[SZ(res) - 2]]) >= 0) {
			res.pob();
		}
		res.pub(i);
	}
	res.pob();
	vector<int> res2 = res; res.clear();
	range(i, n - 1, 0, -1) {
		while(SZ(res) > 1 && (ps[i] - ps[res[SZ(res) - 2]]) * (ps[res.back()] - ps[res[SZ(res) - 2]]) >= 0) {
			res.pob();
		}
		res.pub(i);
	}
	res.pob(); res2.insert(res2.end(), all(res));
	return res2;
}

// Whether X in triangle ABC
bool inTriangle(int x, int a, int b, int c) {
	int jab = (ps[a] - ps[x]) * (ps[b] - ps[x]) > 0;
	int jbc = (ps[b] - ps[x]) * (ps[c] - ps[x]) > 0;
	int jca = (ps[c] - ps[x]) * (ps[a] - ps[x]) > 0;
	return jab == jbc && jbc == jca;
}

vector<pair<int, int> > egs;

//  ABC 
void TriangleConnect(int a, int b, int c, vector<int> &pt) {
	int d = -1, ls = ps[a].c ^ ps[b].c ^ ps[c].c;
	loop(i, SZ(pt)) {
		if(ps[pt[i]].c == ls) {
			d = pt[i]; break;
		}
	}
	if(!~d) {
		// if no point d found...
		int co = ps[a].c == ls ? b : a;
		loop(i, SZ(pt)) egs.pub(mak(co, pt[i]));
		return;
	}
	egs.pub(mak(d, ps[a].c != ls ? (ps[b].c != ls ? c : b) : a));
	vector<int> pab, pbc, pca;
	loop(i, SZ(pt)) {
		if(pt[i] == d) continue;
		if(inTriangle(pt[i], a, b, d)) pab.pub(pt[i]);
		else if(inTriangle(pt[i], b, c, d)) pbc.pub(pt[i]);
		else pca.pub(pt[i]);
	}
	TriangleConnect(a, b, d, pab);
	TriangleConnect(b, c, d, pbc);
	TriangleConnect(c, a, d, pca);
}

int main() {
	scanf("%d", &n);
	loop(i, n) {
		scanf("%lld%lld%d", &ps[i].x, &ps[i].y, &ps[i].c);
		ps[i].id = i;
	}
	if(n == 1) return puts("0"), 0;
	sort(ps, ps + n);
	vector<int> h = get_hull();
	// loop(i, SZ(h)) cerr<<ps[h[i]].x<<' '<<ps[h[i]].y<<' '<<ps[h[i]].c<<endl;
	int se = 0;
	loop(i, SZ(h)) if(ps[h[i]].c != ps[h[(i + 1) % SZ(h)]].c) ++se;
	if(se > 2) return puts("Impossible"), 0;
	if(!se) {
		int d = -1;
		loop(i, n) if(ps[i].c != ps[h[0]].c) {
			d = i; break;
		}
		if(!~d) {
			printf("%d\n", n - 1);
			cont(i, n - 1) printf("%d %d\n", 0, i);
			return 0;
		}
		loop(i, SZ(h) - 1) egs.pub(mak(h[i], h[i + 1]));
		loop(i, SZ(h)) {
			int a = h[i], b = h[(i + 1) % SZ(h)];
			vector<int> pts;
			loop(j, n) if(inTriangle(j, a, b, d)) pts.pub(j);
			TriangleConnect(h[i], h[(i + 1) % SZ(h)], d, pts);
		}
	} else {
		int f0 = -1, f1 = -1;
		loop(i, SZ(h)) if(ps[h[i]].c != ps[h[(i + 1) % SZ(h)]].c) {
			if(ps[h[i]].c) f1 = i;
			else f0 = i;
		}
		loop(i, SZ(h)) {
			int a = h[i], b = h[(i + 1) % SZ(h)], c;
			if(ps[a].c != ps[b].c) continue;
			egs.pub(mak(a, b));
			if(ps[a].c) c = h[f0];
			else c = h[f1];
			vector<int> pts;
			loop(j, n) if(inTriangle(j, a, b, c)) pts.pub(j);
			TriangleConnect(h[i], h[(i + 1) % SZ(h)], c, pts);
		}
	}
	// Don't forget to map ids back while outputting
	printf("%d\n", SZ(egs));
	loop(i, SZ(egs)) printf("%d %d\n", ps[egs[i].first].id, ps[egs[i].second].id);
	return 0;
}

/**
 * 10:15-11:00, 45min
 * 11:00-11:45, 13:40-14:25, 1.5h
 * 
 *  
 *    0  1 
 *    0
 *    
 *     1 
 *   
 *    
 *    
 *  
 *    ABC  1
 *     1  0 
 *     1  D 1 
 *      ABDBCDACD 
 */