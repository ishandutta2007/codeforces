#include <iostream>
#include <map>
#include <set>
using namespace std;
#pragma warning (disable: 4996)

long long gcd(long long a, long long b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

struct Point {
	long long px, py;
};

bool operator<(const Point &p1, const Point &p2) {
	if (p1.px < p2.px) return true;
	if (p1.px > p2.px) return false;
	if (p1.py < p2.py) return true;
	if (p1.py > p2.py) return false;
	return false;
}

bool operator==(const Point &a1, const Point &a2) {
	if (a1.px == a2.px && a1.py == a2.py) return true;
	return false;
}

long long dist(Point V) {
	return V.px * V.px + V.py * V.py;
}

Point hosei(Point E) {
	long long F = gcd(E.px, E.py);
	return Point{ E.px / F, E.py / F };
}

map<long long, set<Point>> Map;
map<Point, int> X;

void add(Point E) {
	long long T = dist(E);
	set<Point> Set = Map[T];

	auto itr = Set.begin();
	while (itr != Set.end()) {
		Point R = *itr;
		Point R2 = Point{ E.px + R.px, E.py + R.py };
		R2 = hosei(R2); X[R2] += 2;
		itr++;
	}
	Map[T].insert(E);

	E = hosei(E); X[E]++;
}

void lose(Point E) {
	long long T = dist(E); Map[T].erase(E);
	set<Point> Set = Map[T];

	auto itr = Set.begin();
	while (itr != Set.end()) {
		Point R = *itr;
		Point R2 = Point{ E.px + R.px, E.py + R.py };
		R2 = hosei(R2); X[R2] -= 2;
		itr++;
	}

	E = hosei(E); X[E]--;
}

int main() {
	long long Q; scanf("%lld", &Q);

	long long cnt = 0;
	for (int i = 1; i <= Q; i++) {
		long long ty; Point I;
		scanf("%lld%lld%lld", &ty, &I.px, &I.py);
		if (ty == 1) { cnt++; add(I); }
		if (ty == 2) { cnt--; lose(I); }
		if (ty == 3) {
			I = hosei(I);
			printf("%lld\n", cnt - X[I]);
		}
	}
	return 0;
}