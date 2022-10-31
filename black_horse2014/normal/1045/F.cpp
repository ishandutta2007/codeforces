#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct pt {
	ll x, y;
	int id;
	pt () {}
	pt (ll x, ll y) : x(x), y(y) {}
	bool odd() { return (x & 1) || (y & 1); }
	bool operator < (const pt &p) const {
		return make_pair(x, y) < make_pair(p.x, p.y);
	}
};

ll vect(pt p, pt p1, pt p2) {
	return (p1.x - p.x) * (p2.y - p.y) - (p1.y - p.y) * (p2.x - p.x);
}

ll scal(pt p, pt p1, pt p2) {
	return (p1.x - p.x) * (p2.x - p.x) + (p1.y - p.y) * (p2.y - p.y);
}

bool bad(pt p1, pt p2, pt p3) {
	ll v = vect(p1, p2, p3), s = scal(p3, p1, p2);
	return make_pair(v, s) <= make_pair(0ll, 0ll);
}

vector<pt> ps, ch;

void check(pt pts) {
	if (pts.odd()) puts("Ani"), exit(0);
}

void convex() {
	for (int T :{0, 1}) {
		for (pt p : ps) {
			while (ch.size() >= 2 && bad(p, ch[ch.size()-2], ch.back())) ch.pop_back();
			ch.push_back(p);
		}
		reverse(ps.begin(), ps.end());
	}
	ch.pop_back();
	for (pt p : ch) check(p);
}

void upt(vector<pt> &cur, int fid, int tid, int ban) {
	if (tid > fid) {
		for (int i = fid; i <= tid; i++) {
			if (i == ban) continue;
			while (cur.size() >= 2 && bad(ps[i], cur[cur.size() - 2], cur.back())) cur.pop_back();
			cur.push_back(ps[i]);
		}
	} else {
		for (int i = fid; i >= tid; i--) {
			if (i == ban) continue;
			while (cur.size() >= 2 && bad(ps[i], cur[cur.size() - 2], cur.back())) cur.pop_back();
			cur.push_back(ps[i]);
		}
	}
}

void check(int id) {
	vector<pt> cur;
	pt prv = ch[(id-1+ch.size())%ch.size()], now = ch[id], nxt = ch[(id + 1)%ch.size()];
	upt(cur, prv.id, now.id, now.id);
	upt(cur, now.id, nxt.id, now.id);
	for (pt p : cur) check(p);
}

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;
		ps.emplace_back(x, y);
	}
	ps.emplace_back(0, 0);
	sort(ps.begin(), ps.end());
	for (int i = 0; i < ps.size(); i++) ps[i].id = i;
	convex();
	for (int i = 1; i < ch.size(); i++) check(i);
	puts("Borna");
}