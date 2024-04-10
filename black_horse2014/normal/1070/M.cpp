#include <bits/stdc++.h>
using namespace std;

const int N = 4400;
using DB = double;
const DB PI = acos(-1);

int r[N];
DB ang[N];

struct PT {
	int x, y, k, id;
	PT(int x = 0, int y = 0, int k = 0, int id = 0) : x(x), y(y), k(k), id(id) {}
};

void solve(vector<PT> V) {
	int ma = 0, id;
	for (int i = 0; i < V.size(); i++) {
		if (ma < V[i].k) {
			ma = V[i].k;
			id = i;
		}
	}
	assert(ma);
	if (ma == 1) {
		vector<int> paran;
		for (auto t : V) {
			if (t.k == 0) paran.push_back(t.id);
		}
		assert(paran.size() == 1);
		for (auto t : V) {
			if (t.id == paran[0] && t.k == 0) continue;
			cout << t.id << ' ' << paran[0] << endl;
		}
		return;
	}
	swap(V[id], V.back());
	int vn = V.size() - 1;
	id = vn;
	vector<pair<DB, int>> EV;
	int all = 0;
	for (int i = 0; i < vn; i++) {
		all += (V[i].k - 1);
		DB ang = atan2(V[i].y - V[id].y, V[i].x - V[id].x);
		DB nxt = ang + PI;
		if (nxt > PI) nxt -= PI * 2;
		EV.emplace_back(ang, i+1);
		EV.emplace_back(nxt, -i-1);
	}
	assert(all + V[id].k == 0);
	sort(EV.begin(), EV.end());
	deque<int> DQ;
	int cur = 0;
	for (auto e : EV) {
		if (e.second > 0 && e.first > 1e-12) {
			DQ.push_back(e.second - 1);
			cur += (V[e.second - 1].k - 1);
		}
	}
	int flg = 0;
	for (auto e : EV) {
		if (cur <= -1 && (all - cur) <= -1) {
			flg = 1;
			break;
		}
		if (e.second > 0) {
			DQ.push_back(e.second - 1);
			cur += (V[e.second - 1].k - 1);
		} else {
			DQ.pop_front();
			cur -= (V[-e.second - 1].k - 1);
		}
	}
	assert(flg);
	bool b[vn] = {0};
	for (int x : DQ) {
		b[x] = 1;
	}
	vector<PT> P, Q;
	int uvx = 0;
	for (int i = 0; i < vn; i++) {
		if (b[i]) P.push_back(V[i]), uvx += V[i].k - 1;
		else Q.push_back(V[i]);
	}
	assert(uvx == cur);
	assert(cur < 0);
	assert(cur > all);
	P.emplace_back(V[id].x, V[id].y, -cur, V[id].id);
	Q.emplace_back(V[id].x, V[id].y, cur - all, V[id].id);
	solve(P);
	solve(Q);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios::sync_with_stdio(0);
	int ncase;
	for (cin >> ncase; ncase--; ) {
		int a, b; cin >> a >> b;
		vector<PT> VT;
		for (int i = 1; i <= b; i++) cin >> r[i];
		for (int i = 1; i <= a; i++) {
			int x, y; cin >> x >> y;
			VT.emplace_back(x, y, 0, i);
		}
		for (int i = 1; i <= b; i++) {
			int x, y; cin >> x >> y;
			VT.emplace_back(x, y, r[i], i);
		}
		cout << "YES" << endl;
		solve(VT);
	}
	return 0;
}