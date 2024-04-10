#include <bits/stdc++.h>
using namespace std;

using db = long double;

const db eps = 1e-10;
const db inf = 1e101;

struct pt{
	db x, y;
	pt () {}
	pt (db x, db y) : x(x), y(y) {}
	bool operator < (const pt &p) const {
		if (fabs(x - p.x) > eps) return x < p.x;
		return y < p.y - eps;
	}
	bool operator == (const pt &p) const {
		return fabs(x - p.x) < eps && fabs(y - p.y) < eps;
	}
};

const int N = 110000;

struct line {
	db a, b, c;
	line (db a = 0, db b = 0, db c = 0) : a(a), b(b), c(c) {}
	void in() {
		int _a, _b, _c;
		cin >> _a >> _b >> _c;
		a = _a, b = _b, c = _c;
	}
	db getValue(pt pts) {
		return a * pts.x + b * pts.y + c;
	}
} L[N];

pt inter(int i, int j) {
	db m = L[i].a * L[j].b - L[j].a * L[i].b;
	if (fabs(m) < eps) return pt(inf, inf);
	return pt((L[j].c * L[i].b - L[i].c * L[j].b) / m, (L[i].c * L[j].a - L[j].c * L[i].a) / m);
}

int rnd() {
	return (rand() << 14) | rand();
}

const vector<pair<int, int>> no = {make_pair(-1, -1)};

vector<pair<int, int>> dfs(vector<int> vec, int k) {
	if (vec.empty()) return {};
	if (k == 0) return no;
	if (vec.size() == 1) return {make_pair(vec[0], -1)};
	if (k == 1) {
		auto pts = inter(vec[0], vec[1]);
		if (pts.x == inf) return no;
		for (int i : vec) {
			if (fabs(L[i].getValue(pts)) > eps) return no;
		}
		return {make_pair(vec[0], vec[1])};
	}
	if (vec.size() > 30) {
		for (int times = 0; times < 40; times++) {
			int x = rnd() % vec.size(), y = rnd() % vec.size();
			if (x == y) continue;
			pt pts = inter(vec[x], vec[y]);
			if (pts.x == inf) continue;
			int cnt = 0;
			bool chk[vec.size()] = {0};
			memset(chk, 0, sizeof chk);
			for (int j = 0; j < vec.size(); j++) {
				if (fabs(L[vec[j]].getValue(pts)) < eps) {
					chk[j] = 1;
					cnt++;
				}
			}
			if (cnt > k) {
				vector<int> tmp;
				for (int j = 0; j < vec.size(); j++) {
					if (chk[j]) continue;
					tmp.push_back(vec[j]);
				}
				auto ret = dfs(tmp, k-1);
				if (ret == no) return ret;
				ret.emplace_back(vec[x], vec[y]);
				return ret;
			}
		}
		return no;
	}
	map<pt, set<int>> M;
	for (int i = 0; i < vec.size(); i++) {
		for (int j = 0; j < i; j++) {
			pt pts = inter(vec[i], vec[j]);
			if (pts.x == inf) continue;
			M[pts].insert(vec[i]);
			M[pts].insert(vec[j]);
		}
	}
	if (M.empty()) {
		if (vec.size() > k) return no;
		vector<pair<int, int>> ret;
		for (int i : vec) ret.emplace_back(i, -1);
		return ret;
	}
	for (auto &t : M) {
		vector<int> tmp;
		for (int i = 0; i < vec.size(); i++) {
			if (!t.second.count(vec[i])) tmp.push_back(vec[i]);
		}
		auto ret = dfs(tmp, k-1);
		if (t.second.size() > k && ret == no) return ret;
		if (ret != no) {
			int x = *t.second.begin();
			int y = (t.second.size() > 1) ? *t.second.rbegin() : -1;
			assert(x != y);
			ret.emplace_back(x, y);
			return ret;
		}
	}
	return no;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, k; cin >> n >> k;
	vector<int> vec;
	for (int i = 1; i <= n; i++) {
		vec.push_back(i);
		L[i].in();
	}
	auto ret = dfs(vec, k);
	if (ret == no) cout << "NO" << endl;
	else {
		cout << "YES" << endl;
		cout << ret.size() << endl;
		bool chk[N] = {0};
		for (auto t : ret) {
			cout << t.first << ' ' << t.second << endl;
		}
	}
}