#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

const long long INF = (1LL << 60);
const int N = 111111;
const int CONS_WIDE = 5;

long long ans = INF;

struct Point {
	int x, y;
	Point(int x, int y) : x(x), y(y) {}
	Point() {}
	friend inline int operator <(const Point &a, const Point &b) {
		if (a.x != b.x)
			return a.y < b.y;
		return a.x < b.x;
	}
	long long dist(const Point &o) {
		return 1LL * (x - o.x) * (x - o.x) + 1LL * (y - o.y) * (y - o.y);
	}
};

vector<Point> points;
Point bak[N];
int n;

void divide(int l, int r) {
	if (l == r) {
		return ;
	}
	int mid = (l + r) / 2;
	divide(l, mid);
	divide(mid + 1, r);
	int pl = l, pr = mid + 1, pm = l;
	for(int i = l; i <= r; i++) {
		if (pr > r || (pl <= mid && points[pl].y <= points[pr].y))
			bak[pm++] = points[pl++];
		else
			bak[pm++] = points[pr++];
	}	
	for(int i = l; i <= r; i++) {
		points[i] = bak[i];
	}
	for(int i = l; i <= r; i++) {
		for(int j = max(l, i - CONS_WIDE); j <= min(r, i + CONS_WIDE); j++) {
			if (j != i)
				ans = min(ans, points[i].dist(points[j]));
		}
	}
}

int main() {
	scanf("%d", &n);
	int s = 0;
	for(int i = 1; i <= n; i++) {
		int a;
		scanf("%d", &a);
		s += a;
		points.push_back(Point(i, s));
	}
	sort(points.begin(), points.end());
	divide(0, n - 1);
	cout << ans << endl;
	return 0;
}