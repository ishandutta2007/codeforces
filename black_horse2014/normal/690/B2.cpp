#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <climits>
#include <cctype>
#include <utility>
#include <queue>
#include <cmath>
#include <complex>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
typedef pair<LL, LL> PLL;
typedef pair<int, LL> PIL;
typedef pair<LL, int> PLI;
typedef double DB;

#define pb push_back
#define mset(a, b) memset(a, b, sizeof a)
#define all(x) (x).begin(), (x).end()
#define bit(x) (1 << (x))
#define bitl(x) (1LL << (x))
#define sz(x) ((int)(x.size()))
#define cnti(x) (__builtin_popcount(x))
#define cntl(x) (__builtin_popcountll(x))
#define clzi(x) (__builtin_clz(x))
#define clzl(x) (__builtin_clzll(x))
#define ctzi(x) (__builtin_ctz(x))
#define ctzl(x) (__builtin_ctzll(x))

#define X first
#define Y second

#define Error(x) cout << #x << " = " << x << endl

template <typename T, typename U> 
inline void chkmax(T& x, U y) {
	if (x < y) x = y;
}

template <typename T, typename U>
inline void chkmin(T& x, U y) {
	if (y < x) x = y;
}


typedef double DB;
const DB PI = acos(DB(-1));
const DB INF = 1e12;
const DB EPS = 1e-10;

inline DB sqr(DB x) {
	return x * x;
}

struct PT {
	DB x, y;
	
	PT() {}
	PT(DB x, DB y) : x(x), y(y) {}
} P[820000], Q[820000];

bool operator<(const PT& p1, const PT& p2) {
	if (fabs(p1.x - p2.x) > EPS) return p1.x < p2.x;
	return p1.y + EPS < p2.y;
}

bool operator==(const PT& p1, const PT& p2) {
	return fabs(p1.x - p2.x) < EPS && fabs(p1.y - p2.y) < EPS;
}

PT operator+(PT p1, PT p2) {
	return PT(p1.x + p2.x, p1.y + p2.y);
}

PT operator-(PT p1, PT p2) {
	return PT(p1.x - p2.x, p1.y - p2.y);
}

PT operator*(PT p, DB c) {
	return PT(p.x * c, p.y * c);
}

DB vect(PT p1, PT p2) {
	return p1.x * p2.y - p2.x * p1.y;
}

DB vect(PT p, PT p1, PT p2) {
	return vect(p1 - p, p2 - p);
}

int convex_hull(PT *p, int n, PT *q) {
	int i, k, m;
	
	sort(p, p + n);
	n = unique(p, p + n) - p;
	if (n == 1) {
		q[0] = p[0];
		return 1;
	}
	m = 0;
	for (i = 0; i < n; i++) {
		while (m > 1 && vect(q[m - 2], q[m - 1], p[i]) < EPS) m--;
		q[m++] = p[i];
	}
	k = m;
	for (i = n - 2; i >= 0; i--) {
		while (m > k && vect(q[m - 2], q[m - 1], p[i]) < EPS) m--;
		q[m++] = p[i];
	}
	return --m;
}

int dx[5] = {1, -1, 0, 0};
int dy[5] = {0, 0, 1, -1};
char c[555][555];

int main() {
	
	int n, m;
	while (scanf("%d", &n) and n) {
		gets(c[0]);
		for (int i = n - 1; i >= 0; i--) gets(c[i]);
		int k = 0;
		int x, y;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (c[i][j] == '4' or c[i][j] == '0') continue;
				y = i + 1, x = j + 1;
				P[k++] = PT(x, y);
				P[k++] = PT(x - 1, y);
				P[k++] = PT(x - 1, y - 1);
				P[k++] = PT(x, y - 1);
			}
		}
		m = convex_hull(P, k, Q);
		k = 0;
		for (int i = 0; i < m; i++) {
			int id = 0;
			double x, y;
			for(int j = 0; j < 4; j++) {
				x = Q[i].x + dx[j], y = Q[i].y + dy[j];
				PT pp = PT(x, y);
				if (vect(Q[i], Q[(i + 1) % m], pp) > -EPS and 
					vect(Q[(i + m - 1) % m], Q[i], pp) > -EPS) id |= bit(j);
			}
			x = Q[i].x, y = Q[i].y;
			for (int j = 0; j < 4; j++) {
				if (id & bit(j)) {
					x += dx[j];
					y += dy[j];
				}
			}
			P[k++] = PT(x, y);
		}
		m = convex_hull(P, k, Q);
		int mx = 1111111, my = 1111111, id = -1;
		
		for (int i = 0; i < m; i++) {
			if (Q[i].x < mx) mx = Q[i].x, my = Q[i].y, id = i;
			else if ((int) Q[i].x == mx and Q[i].y < my) my = Q[i].y, id = i;
		}
		cout<<m<<endl;
		for (int i = m; i > 0; i--) {
			printf("%d %d\n", (int)(Q[(i + id) % m].x), (int)(Q[(i + id) % m].y));
		}
	}
				
	return 0;
}