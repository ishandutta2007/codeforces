#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <iostream>
#include <set>
using namespace std;

const int INF = 1111111111;

struct Point {
	long long x, y;
	Point(long long x = 0, long long y = 0) : x(x), y(y) {}
	friend inline bool operator <(const Point &a, const Point &b) {
		return a.x < b.x;
	}

};

	void show(Point o) {
		cout << o.x << " " << o.y << endl;
	}

long long det(Point a, Point b, Point c) {
	return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}

vector<Point> points;
int n;

struct Convex {
	set<Point> points;
	int opt;
	void init(int val) {
		opt = val;
		points.clear();
	}
	
	bool contain(Point o) {
		set<Point> :: iterator it = points.lower_bound(o);
		if (it == points.end() || (it == points.begin() && o.x < it->x))
			return false;
		if (it->x == o.x) {
			return (it->y - o.y) * opt >= 0;
		} else {
			set<Point> :: iterator it2 = it;
			it2--;
			return det(*it2, *it, o) * opt <= 0;
		}
	}
	
	void insert(Point o) {
		if (contain(o))
			return ;
		set<Point> :: iterator it = points.lower_bound(o);
		if (it != points.end() && it->x == o.x && (o.y - it->y) * opt >= 0) {
			points.erase(it);
		}
		for(; ;) {
			set<Point> :: iterator it = points.lower_bound(o), it2;
			if (it == points.end())
				break;
			it2 = it;
			++it2;
			if (it2 == points.end())
				break;
			if (det(o, *it, *it2) * opt >= 0) {
				points.erase(it);
			} else {
				break;
			}
		}
		for(; ;) {
			set<Point> :: iterator it = points.lower_bound(o), it2;
			if (it == points.begin())
				break;
			--it;
			it2 = it;
			if (it2 == points.begin())
				break;
			it2--;
			if (det(*it2, *it, o) * opt >= 0) {
				points.erase(it);
			} else {
				break;
			}
		}
		points.insert(o);
	}
	void show() {
		for(set<Point> :: iterator it = points.begin(); it != points.end(); ++it) {
			cout << it->x << " " << it->y << endl;
		}
	}
}lower, upper;


int main() {
	int queryNum;
	lower.init(-1);
	upper.init(1);
	scanf("%d", &queryNum);
	for(int i = 1; i <= queryNum; i++) {
		int x, y, type;
		scanf("%d %d %d", &type, &x, &y);
		Point w = Point(x, y);
		if (type == 1) {
			lower.insert(w);
			upper.insert(w);
		} else {
			//printf("%d %d\n", lower.contain(w), upper.contain(w));
			if (lower.contain(w) && upper.contain(w)) {
				puts("YES");
			} else {
				puts("NO");
			}
		}/*
		lower.show();
		cout << "----------" << endl;
		upper.show();
		cout << endl;*/
	}
	
	return 0;
}