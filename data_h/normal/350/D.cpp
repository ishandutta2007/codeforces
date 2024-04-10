#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <iostream>
#include <iostream>
#include <cmath>
using namespace std;

const int N = 333333, M = 2222;

struct Point {
	int x, y;
	Point(int x = 0, int y = 0) : x(x), y(y) {}
	void scan() {
		scanf("%d %d", &x, &y);
		x *= 2;
		y *= 2;
	}
	inline friend Point operator +(const Point &a, const Point &b) {
		return Point(a.x + b.x, a.y + b.y);
	}
	inline friend Point operator -(const Point &a, const Point &b) {
		return Point(a.x - b.x, a.y - b.y);
	}
	inline friend Point operator /(const Point &a, double k) {
		return Point(a.x / k, a.y / k);
	}
	inline friend Point operator *(const Point &a, double k) {
		return Point(a.x * k, a.y * k);
	}
	inline friend bool operator ==(const Point &a, const Point &b) {
		return a.x == b.x && a.y == b.y;
	}
	inline friend bool operator !=(const Point &a, const Point &b) {
		return a.x != b.x || a.y != b.y;
	}
	void norm() {
		if (x < 0 || x == 0 && y < 0) {
			x = -x;
			y = -y;
		}
		if (x == 0) {
			y = 1;
		} else if (y == 0) {
			x = 1;
		} else {
			int g = __gcd(abs(x), abs(y));
			x /= g;
			y /= g;
		}
	}
	void rotate() {
		swap(x, y);
		x = -x;
	}
	inline friend int operator <(const Point &a, const Point &b) {
		if (a.x != b.x) {
			return a.x < b.x;
		} else {
			return a.y < b.y;
		}
	}
	int hdist(const Point &o) {
		return x * o.y - o.x * y;
	}
	
	int dist(const Point &o) {
		return o.x * x + o.y * y;
	}
	int dist2(const Point &o) {
		return (x - o.x) * (x - o.x) + (y - o.y) * (y - o.y);
	}
};

struct Event {
	Point o;
	int hpos;
	int pos, val;
	Event(Point o = Point(0, 0), int hpos = 0, int pos = 0, int val = 0) : o(o), hpos(hpos), pos(pos), val(val) {}
	friend inline int operator <(const Event &a, const Event &b) {
		if (a.o != b.o) {
			return a.o < b.o;
		} else if (a.hpos != b.hpos) {
			return a.hpos < b.hpos;
		} else if (a.pos != b.pos) {
			return a.pos < b.pos;
		} else {
			return a.val > b.val;
		}
	}
};

int n, m;
Point center[M];
int radius[N];
vector<Event> events;
 
int main() {
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++) {
		Point a, b;
		a.scan();
		b.scan();
		Point vec = (b - a);
		vec.norm();
		if (a.dist(vec) > b.dist(vec)) {
			swap(a, b);
		}
		events.push_back(Event(vec, a.hdist(vec), a.dist(vec), 1));
		events.push_back(Event(vec, b.hdist(vec), b.dist(vec), -1));
	}
	for(int i = 0; i < m; i++) {
		center[i].scan();
		scanf("%d", &radius[i]);
		radius[i] *= 2;
		for(int j = 0; j < i; j++) {
			Point o = (center[i] + center[j]) / 2;
			if (radius[i] == radius[j] && center[i].dist2(center[j]) > 4 * radius[i] * radius[i]) {
				Point vec = (center[j] - center[i]);
				vec.rotate();
				vec.norm();
				events.push_back(Event(vec, o.hdist(vec), o.dist(vec), 0));
			}
		}
	}
	
	long long ans = 0;
	sort(events.begin(), events.end());
	for(int i = 0, j; i < (int)events.size(); i = j) {
		int cur = 0;
		for(j = i; j < (int)events.size() && events[i].o == events[j].o && events[i].hpos == events[j].hpos; j++) {
			if (events[j].val == 0) {
				ans += cur;
			} else {
				cur += events[j].val;
			}
		}
	}
	cout << ans << endl;
	return 0;
}