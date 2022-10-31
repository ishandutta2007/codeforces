#include <bits/stdc++.h>
using namespace std;

using db = long double;

const db eps = 1e-12;
const int N = 220000;

struct pt {
	int x, y;
	pt (int x = 0, int y = 0) : x(x), y(y) {}
};

long long vect(pt p, pt p1, pt p2) {
	return 1ll * (p1.x - p.x) * (p2.y - p.y) * p2.x * p1.y - 1ll * (p2.x - p.x) * (p1.y - p.y) * p1.x * p2.y;
}

vector<pt> cv(vector<pt> vec) {
	if (vec.size() <= 1) return vec;
	int n = vec.size(), k = 0;
	vector<pt> ch(n+2);
	for (int i = 0; i < n; ch[k++] = vec[i++])
		while (k >= 2 && vect(ch[k-2], ch[k-1], vec[i]) < 0) --k;
	while (k >= 2 && ch[k-2].y >= ch[k-1].y) --k;
	ch.resize(k);
	return ch;
}

map<pair<int, int>, vector<int>> M;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int s, r; cin >> s >> r;
		M[make_pair(s, r)].push_back(i+1);
	}
	vector<pt> vec;
	for (auto t : M) {
		vec.emplace_back(t.first.first, t.first.second);
	}
	reverse(vec.begin(), vec.end());
	auto ret = cv(vec);
	set<int> ids;
	for (auto t : ret) {
		for (int x : M[make_pair(t.x, t.y)]) ids.insert(x);
	}
	for (int i : ids) cout << i << ' ';
}