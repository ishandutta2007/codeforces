#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

const int MOD = 1e9 + 7;

int n;

class Point {
public:
	long long x, y;
	Point(long long x, long long y) : x(x), y(y) {}
	Point() {}

	inline Point friend operator +(const Point &a, const Point &b) {
		return Point(a.x + b.x, a.y + b.y);
	}

	inline Point friend operator -(const Point &a, const Point &b) {
		return Point(a.x - b.x, a.y - b.y);
	}

	inline Point friend operator *(const Point &a, double k) {
		return Point(a.x * k, a.y * k);
	}
};

inline long long det(const Point &a, const Point &b) {
	return a.x * b.y - a.y * b.x;
}

inline Point mod(const Point &a) {
	return Point(a.x % MOD, a.y % MOD);
}

void add(long long &a, long long b) {
	a += b % MOD;
	a %= MOD;
	if (a < 0) {
		a += MOD;
	}
}

int power(int a, int b) {
	int ret = 1;
	for (; b; b >>= 1) {
		if (b & 1) {
			ret = 1LL * ret * a % MOD;
		}
		a = 1LL * a * a % MOD;
	}
	return ret;
}

long long abs(long long x) {
	if (x < 0) {
		return -x;
	} else {
		return x;
	}
}

int main() {
	scanf("%d", &n);
	vector<Point> points(2 * n);
	for (int i = 0; i < n; i++) {
		int x, y; scanf("%d %d", &x, &y);
		points[i] = Point(x, y);
		points[i + n] = Point(x, y);
	}

	long long bigger = 0, smaller = 0;
	Point smaller_s = Point(0, 0);
	for (int i = 0; i < n; i++) {
		bigger += det(points[i], points[i + 1]);
	}

	//cout << bigger << endl;

	long long answer = 0;
	//-1LL * n * (bigger % MOD) % MOD;
	add(answer, -1LL * n * (bigger % MOD) % MOD);

	long long delta = 0;

	for (int i = 0, j = 0; i < n; i++) {

		//cout << bigger << " " << smaller << endl;

		while (bigger - det(points[j], points[j + 1]) + det(points[i], points[j + 1])
				<= smaller + det(points[j], points[j + 1]) + det(points[j + 1], points[i])) {
				add(delta, smaller);
				add(delta, 1LL * (1 - (j - i)) * (det(points[j], points[j + 1]) % MOD));

				bigger -= det(points[j], points[j + 1]);
				smaller += det(points[j], points[j + 1]);
				smaller_s = smaller_s + points[j + 1];
				++j;
		}
		//cout << "i = " << i << ", j = " << j << endl;

		//cout << "delta = " << delta << endl;
		//cout << "smaller = " << smaller << ", smaller_s.x = " << smaller_s.x << ", smaller_s.y = " << smaller_s.y << endl;
		add(answer, -delta);
		add(answer, -det(mod(smaller_s), points[i]));
		add(answer, det(points[i], mod(smaller_s)));
		add(answer, 1LL * bigger % MOD * (j - i));

		//cout << "answer = " << MOD - answer << endl;

		smaller_s = smaller_s - points[i + 1];
		add(delta, -1LL * (j - i) * (det(points[i], points[i + 1]) % MOD) % MOD);
		smaller = smaller - det(points[i], points[i + 1]);
		add(delta, smaller);
		bigger = bigger + det(points[i], points[i + 1]);
		//cout << "delta = " << delta << endl;
		//cout << "======================== " << endl;
	}


	//answer = answer * power(2, MOD - 2) % MOD;
	//cout << answer << endl;
	cout << (MOD - answer) % MOD << endl;
	return 0;
}