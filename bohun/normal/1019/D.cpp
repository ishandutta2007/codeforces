#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define all(x) x.begin(), x.end()
 
using namespace std;

struct pt {
	int x, y, id;
	pt () {}
	pt (int _x, int _y, int _id) {
		x = _x; y = _y; id = _id;
	}
	pt operator +(pt a) {
		pt c;
		c.x = x + a.x;
		c.y = y + a.y;
		c.id = a.id;
		return c;
	}
	pt operator -(pt a) {
		pt c;
		c.x = x - a.x;
		c.y = y - a.y;
		c.id = id;
		return c;
	}
	bool operator <(pt a) {
		return mp(x, y) < mp(a.x, a.y);
	}
	void qw() {
		printf ("pt = ( %d %d )\n", x, y);
	}
};

ll wek(pt a, pt b) {
	return (ll) a.x * b.y - (ll) a.y * b.x;
}

ll pole(pt a, pt b, pt c) { // 2 * pole
	return abs(wek(a, b) + wek(b, c) + wek(c, a));
}

const int nax = 2100;

int n, x, y;
ll s;

vector <pt> points;
int pos[nax];

struct gao {
	int a, b;
	pt c;
	gao() {}
	gao(int _a, int _b, pt _c) {
		a = _a; b = _b; c = _c;
	}
};

vector <gao> v;

void ans(int a, int b, int c) {
	printf ("Yes\n");
	printf ("%d %d\n", points[a].x, points[a].y);
	printf ("%d %d\n", points[b].x, points[b].y);
	printf ("%d %d\n", points[c].x, points[c].y);
	exit(0);
}

int main() {
	scanf ("%d %lld", &n, &s);
	rep(i, 0, n - 1) {
		scanf ("%d%d", &x, &y);
		points.pb(pt(x, y, i));
	}
	
	sort(all(points));
	rep(i, 0, n - 1) 
		pos[points[i].id] = i;
	
	rep(i, 0, n - 1)
		rep(j, 0, i - 1)
			v.pb({points[j].id, points[i].id, points[i] - points[j]});
	
	sort(all(v), [](gao a, gao b) {
		return wek(a.c, b.c) < 0;
	});
	
	for (auto it : v) {
		int a = it.a;
		int b = it.b;
		
		//points[a].qw();
		//points[b].qw();
		//printf ("%d %d\n", pos[a], pos[b]);
		assert(pos[a] + 1 == pos[b]);
		
		int low = pos[b] + 1, high = n - 1;
		while (low <= high) {
			int mid = (low + high) / 2;
			ll p = pole(points[pos[a]], points[pos[b]], points[mid]);
			if (p == 2 * s) ans(pos[a], pos[b], mid);
			if (p < 2 * s) low = mid + 1;
			else high = mid - 1;
		}
		
		low = 0, high = pos[a] - 1;
		while (low <= high) {
			int mid = (low + high) / 2;
			ll p = pole(points[pos[a]], points[pos[b]], points[mid]);
			if (p == 2 * s) ans(pos[a], pos[b], mid);
			if (p < 2 * s) high = mid - 1;
			else low = mid + 1;
		}
		
		swap(points[pos[a]], points[pos[b]]);
		swap(pos[a], pos[b]);
	}
	printf ("No\n");
	
	
	return 0;
}