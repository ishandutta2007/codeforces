/* cerberus97 - Hanit Banga */

#include <iostream>
#include <iomanip>
#include <cassert>
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
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 5e4 + 10;

struct PT {
	int x, y, z, id;
	bool operator<(const PT &o) const {
		return tie(x, y, z) < tie(o.x, o.y, o.z);
	}
};

void process(vector<PT> &pts, bool eq(PT, PT));

int main() {
	fast_cin();
	int n; cin >> n;
	vector<PT> pts;
	for (int i = 1; i <= n; ++i) {
		int x, y, z;
		cin >> x >> y >> z;
		pts.pb({x, y, z, i});
	}
	sort(pts.begin(), pts.end());
	process(pts, [] (PT a, PT b) {
		return tie(a.x, a.y) == tie(b.x, b.y);
	});
	process(pts, [] (PT a, PT b) {
		return a.x == b.x;
	});
	process(pts, [] (PT a, PT b) {
		return true;
	});
}

void process(vector<PT> &pts, bool eq(PT, PT)) {
	vector<PT> temp;
	for (auto &pt : pts) {
		if (!temp.empty() and eq(pt, temp.back())) {
			cout << pt.id << ' ' << temp.back().id << '\n';
			temp.pop_back();
		} else {
			temp.pb(pt);
		}
	}
	pts = temp;
}