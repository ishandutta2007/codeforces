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

const int inf = 1e5;

struct PT {
	int x, y;
};

vector<PT> pts[2];

bool check(vector<PT> sq, PT p);
bool check2(vector<PT> sq, PT p);

int main() {
	for (int sq = 0; sq < 2; ++sq) {
		pts[sq].resize(4);
		for (int i = 0; i < 4; ++i) {
			cin >> pts[sq][i].x >> pts[sq][i].y;
			pts[sq][i].x *= 10;
			pts[sq][i].y *= 10;
		}
	}
	bool intersect = false;
	for (int i = 0; i < 4; ++i) {
		if (check(pts[0], pts[1][i]) or check2(pts[1], pts[0][i])) {
			intersect = true;
			break;
		}
	}
	int min_x = inf, max_x = -inf;
	int min_y = inf, max_y = -inf;
	for (auto &i : pts[0]) {
		min_x = min(min_x, i.x);
		max_x = max(max_x, i.x);
		min_y = min(min_y, i.y);
		max_y = max(max_y, i.y);
	}
	for (int x = min_x; x <= max_x; ++x) {
		for (int y = min_y; y <= max_y; ++y) {
			if (check2(pts[1], {x, y})) {
				intersect = true;
				break;
			}
		}
	}
	if (intersect) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
}

bool check(vector<PT> sq, PT p) {
	int min_x = inf, max_x = -inf;
	int min_y = inf, max_y = -inf;
	for (auto &i : sq) {
		min_x = min(min_x, i.x);
		max_x = max(max_x, i.x);
		min_y = min(min_y, i.y);
		max_y = max(max_y, i.y);
	}
	return (min_x <= p.x and p.x <= max_x and min_y <= p.y and p.y <= max_y);
}

bool check2(vector<PT> sq, PT p) {
	for (auto &i : sq) {
		i.y -= i.x;
		i.x = 2 * i.x + i.y;
	}
	p.y -= p.x;
	p.x = 2 * p.x + p.y;
	return check(sq, p);
}