/*
Cerberus97
Hanit Banga
*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 10;

struct P {
	int x, y;
	bool operator<(const P &o) const {
		return y < o.y;
	}
} p[3];

int dist(int x1, int y1, int x2, int y2);

int main() {
	for (int i = 0; i < 3; ++i) {
		cin >> p[i].x >> p[i].y;
	}
	sort(p, p + 3);
	int ans = 0;
	set<pii> pts;
	if (p[0].y != p[1].y) {
		ans += p[1].y - p[0].y;
		for (int y = p[0].y; y <= p[1].y; ++y) {
			pts.insert({p[0].x, y});
		}
		p[0].y = p[1].y;
	}
	// ans += abs(p[0].x == p[1].x);
	// for (int )
	int temp = N, best_x = -1;
	for (int x = min(p[0].x, p[1].x); x <= max(p[0].x, p[1].x); ++x) {
		pts.insert({x, p[0].y});
		if (dist(x, p[0].y, p[2].x, p[2].y) < temp) {
			temp = dist(x, p[0].y, p[2].x, p[2].y);
			best_x = x;
		}
	}
	while (p[1].y <= p[2].y) {
		pts.insert({best_x, p[1].y});
		p[1].y++;
	}
	while (true) {
		pts.insert({best_x, p[2].y});
		if (best_x == p[2].x) {
			break;
		} else if (best_x < p[2].x) {
			++best_x;
		} else {
			--best_x;
		}
	}
	cout << pts.size() << endl;
	for (auto &i : pts) {
		cout << i.first << ' ' << i.second << endl;
	}
}

int dist(int x1, int y1, int x2, int y2) {
	return abs(x1 - x2) + abs(y1 - y2);
}