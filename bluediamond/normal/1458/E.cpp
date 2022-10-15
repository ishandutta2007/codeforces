#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <map>
#include <set>

using namespace std;

typedef long long ll;

struct Point {
	int x, y;
};

bool operator < (Point a, Point b) {
	if (a.x != b.x) return a.x < b.x;
	return a.y < b.y;
}

struct Offer {
	Point p;
	int times;
};

bool operator < (Offer a, Offer b) {
	return a.p < b.p;
}

int n, q, limit;
vector<Point> shortcuts;
vector<Point> queries;
set<Point> set_shortcuts;
set<int> set_x;
set<int> set_y;
map<int, int> xx, yy;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> q;

	shortcuts.resize(n);
	for (auto& p : shortcuts) {
		cin >> p.x >> p.y;
		limit = max(limit, p.x);
		limit = max(limit, p.y);
		set_x.insert(p.x);
		set_y.insert(p.y);
		if (xx.count(p.x)) xx[p.x] = min(xx[p.x], p.y); else xx[p.x] = p.y;
		if (yy.count(p.y)) yy[p.y] = min(yy[p.y], p.x); else yy[p.y] = p.x;
		set_shortcuts.insert(p);
	}
	queries.resize(q);
	for (auto& p : queries) {
		cin >> p.x >> p.y;
		limit = max(limit, p.x);
		limit = max(limit, p.y);
	}
	limit = limit + 7;
	set_x.insert(limit + 7);
	set_y.insert(limit + 7);

	vector<Offer> offers;

	Point current = { 0, 0 };
	while (max(current.x, current.y) <= limit) {
		if (set_shortcuts.count(current)) {
			current = { current.x + 1, current.y + 1 };
			continue;
		}
		if (xx.count(current.x) && xx[current.x] < current.y) {
			current = { current.x + 1, current.y };
			continue;
		}
		if (yy.count(current.y) && yy[current.y] < current.x) {
			current = { current.x, current.y + 1 };
			continue;
		}
		int times = max(1, min(*set_x.lower_bound(current.x) - current.x, *set_y.lower_bound(current.y) - current.y));
		offers.push_back({ current,  times });
		current = { current.x + times, current.y + times };
	}
	sort(offers.begin(), offers.end());

	for (auto& p : queries) {
		if (set_shortcuts.count(p)) {
			cout << "LOSE\n";
			continue;
		}
		int low = 0, high = (int)offers.size() - 1, pos = -1;
		while (low <= high) {
			int mid = (low + high) / 2;
			if (offers[mid].p.x <= p.x) {
				pos = mid;
				low = mid + 1;
			}
			else {
				high = mid - 1;
			}
		}
		bool found = false;
		if (pos != -1) {
			auto& offer = offers[pos];
			Point o = offer.p;
			int times = offer.times;

			if (0 <= p.x - o.x && p.x - o.x < times && 0 <= p.y - o.y && p.y - o.y < times && p.x - o.x == p.y - o.y) {
				found = true;
			}

		}
		if (found) {
			cout << "LOSE\n";
		}
		else {
			cout << "WIN\n";
		}
	}
}