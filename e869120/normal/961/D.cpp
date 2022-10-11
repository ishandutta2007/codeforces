#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <functional>
#include <cmath>
#include <map>
#include <vector>
using namespace std;

struct Point {
	long long px, py;
};

long long n; Point P[100009], Q1, Q2; bool flag = false; vector<Point>vec;

bool isline(Point a1, Point a2, Point a3) {
	Point v1 = { a2.px - a1.px,a2.py - a1.py };
	Point v2 = { a3.px - a1.px,a3.py - a1.py };
	if (v1.px*v2.py == v1.py*v2.px) return true;
	return false;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> P[i].px >> P[i].py;
	if (n <= 4) {
		cout << "YES" << endl;
		return 0;
	}
	for (int i = 1; i <= 10000; i++) {
		int a1 = rand() % n + 1;
		int a2 = rand() % n + 1;
		int a3 = rand() % n + 1;
		if (a1 == a2 || a2 == a3 || a3 == a1) continue;

		if (isline(P[a1], P[a2], P[a3]) == true) {
			Q1 = P[a1];
			Q2 = P[a2];
			flag = true;
			break;
		}
	}
	if (flag == false) {
		cout << "NO" << endl;
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		if (isline(Q1, Q2, P[i]) == false) vec.push_back(P[i]);
	}
	if (vec.size() <= 2) {
		cout << "YES" << endl;
		return 0;
	}
	bool OK = false;
	for (int i = 0; i < vec.size(); i++) {
		if (isline(vec[0], vec[1], vec[i]) == false) OK = true;
	}
	if (OK == false) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}