#include <iostream>
#include <vector> 
#include <algorithm> 
#include <string> 
#include <cassert> 
#include <algorithm> 
#include <set> 
#include <iomanip> 
#include <queue> 
#include <deque> 
#include <unordered_set> 
#include <unordered_map> 
#include <functional> 
#include <cmath> 
#include <map> 
#include <random> 
#include <chrono> 
#include <cstdio> 
#include <bitset> 
#include <numeric> 

bool home = true;
using namespace std;

typedef long long ll;

struct P {
	ll x;
	ll y;
};

ll get_dist_sq(P a, P b) {
	ll dx = a.x - b.x;
	ll dy = a.y - b.y;
	return dx * dx + dy * dy;
}

ll trapez_area(P a, P b) {
	return (a.x - b.x) * (a.y + b.y);
}

ll double_area(P a, P b, P c) {
	return trapez_area(a, b) + trapez_area(b, c) + trapez_area(c, a);
}

bool is_lower_left(P a, P b) {
	if (a.x != b.x) return a.x < b.x;
	return a.y < b.y;
}

P operator + (P a, P b) {
	return { a.x + b.x, a.y + b.y };
}

P operator - (P a, P b) {
	return { a.x - b.x, a.y - b.y };
}

const int N = 10000 + 7;
int n;
ll s;
P pts[N];
P origin;

bool cmp(P a, P b) {
	ll d = double_area(origin, a, b);
	if (d == 0) return get_dist_sq(origin, a) < get_dist_sq(origin, b);
	return d > 0;
}

void print(P a) {
	cout << a.x << " " << a.y << " ";
}
signed main() {
#ifdef ONLINE_JUDGE
	home = 0;
#endif

	if (home) {
		FILE* stream;
		freopen_s(&stream, "iron_man.txt", "r", stdin);
	}
	else {
		ios::sync_with_stdio(0); cin.tie(0);
	}


	cin >> n >> s;


	for (int i = 1; i <= n; i++) {
		cin >> pts[i].x >> pts[i].y;
		if (home) {
			cout << pts[i].x << " " << pts[i].y << "\n";
		}
		if (is_lower_left(pts[i], pts[1])) swap(pts[i], pts[1]);
	}
	origin = pts[1];
	sort(pts + 2, pts + n + 1, cmp);
	
	pts[n + 1] = pts[1];
	
	vector<P> all;
	for (int i = 1; i <= n + 1; i++) {
		while ((int)all.size() >= 2 && double_area(all[(int)all.size() - 2], all[(int)all.size() - 1], pts[i]) < 0) {
			all.pop_back();
		}
		all.push_back(pts[i]);
	}
	all.pop_back();
	n = (int)all.size();

	assert(n >= 3);
	for (int i = 1; i <= n; i++) pts[i] = pts[i + n] = all[i - 1];
	


	ll max_area = 0;
	P a, b, c;

	for (int i = 1; i <= n; i++) {
		int k = i + 2;
		for (int j = i + 1; j < i + n; j++) {
			while (k + 1 < i + n && abs(double_area(pts[i], pts[j], pts[k])) < abs(double_area(pts[i], pts[j], pts[k + 1]))) k++;

			if (abs(double_area(pts[i], pts[j], pts[k])) > max_area) {
				max_area = abs(double_area(pts[i], pts[j], pts[k]));
				a = pts[i];
				b = pts[j];
				c = pts[k];
			}
		}
	}
	P x, y, z;
	x = a + b - c;
	y = a + c - b;
	z = b + c - a;

	if (home) {
		cout << "Segment "; print(x); print(y); cout << "\n";
		cout << "Segment "; print(y); print(z); cout << "\n";
		cout << "Segment "; print(z); print(x); cout << "\n";
	}

	print(x); cout << "\n";
	print(y); cout << "\n";
	print(z); cout << "\n";
}