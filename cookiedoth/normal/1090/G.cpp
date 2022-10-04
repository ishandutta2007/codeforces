/*

Code for problem G by cookiedoth
Generated 07 Apr 2019 at 06.12 P


 ] 
 
Il] 


>_<
o_O
-_-

*/

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <functional>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <complex>
#include <cassert>
#include <random>
#include <cstring>
#include <numeric>
#define ll long long
#define ld long double
#define null NULL
#define all(a) a.begin(), a.end()
#define debug(a) cerr << #a << " = " << a << endl
#define forn(i, n) for (int i = 0; i < n; ++i)
#define sz(a) (int)a.size()

using namespace std;

template<class T> int chkmax(T &a, T b) {
	if (b > a) {
		a = b;
		return 1;
	}
	return 0;
}

template<class T> int chkmin(T &a, T b) {
	if (b < a) {
		a = b;
		return 1;
	}
	return 0;
}

template<class iterator> void output(iterator begin, iterator end, ostream& out = cerr) {
	while (begin != end) {
		out << (*begin) << " ";
		begin++;
	}
	out << endl;
}

template<class T> void output(T x, ostream& out = cerr) {
	output(x.begin(), x.end(), out);
}

void fast_io() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

struct node {
	int sum, mod, l, r;
	node (int _sum, int _mod, int _l, int _r): sum(_sum), mod(_mod), l(_l), r(_r) {}
};

struct solver {
	vector<node> t;
	int n, v0;

	solver() {}

	int create_empty() {
		t.emplace_back(0, 0, -1, -1);
		return (int)t.size() - 1;
	}

	int create_vertex(int sum, int mod, int l, int r) {
		t.emplace_back(sum, mod, l, r);
		return (int)t.size() - 1;
	}

	int build(int tl, int tr) {
		if (tl == tr) {
			return create_empty();
		}
		int tm = (tl + tr) >> 1;
		int vl = build(tl, tm);
		int vr = build(tm + 1, tr);
		return create_vertex(0, 0, vl, vr);
	}

	solver(int _n) {
		n = _n;
		v0 = build(0, n - 1);
	}

	int update(int v, int l, int r, int val, int tl, int tr) {
		if (l > r) {
			return v;
		}
		if (l == tl && r == tr) {
			return create_vertex(t[v].sum + (tr - tl + 1) * val, t[v].mod + val, t[v].l, t[v].r);
		}
		int tm = (tl + tr) >> 1;
		int vl = update(t[v].l, l, min(r, tm), val, tl, tm);
		int vr = update(t[v].r, max(l, tm + 1), r, val, tm + 1, tr);
		int res = create_vertex(t[vl].sum + t[vr].sum + t[v].mod * (tr - tl + 1), t[v].mod, vl, vr);
		return res;	
	}

	int get_1_pos(int v, int rpos, int tl, int tr, int up_mod) {
		if (tl == tr) {
			if (up_mod + t[v].sum == 1) {
				return tl;
			}
			else {
				return tl - 1;
			}
		}
		up_mod += t[v].mod;
		int tm = (tl + tr) >> 1;
		if (rpos > tm) {
			int rsum = t[t[v].r].sum + up_mod * (tr - tl);
			if (rsum) {
				int rres = get_1_pos(t[v].r, rpos, tm + 1, tr, up_mod);
				if (rres > tm) {
					return rres;
				}
			}
		}
		int lres = get_1_pos(t[v].l, rpos, tl, tm, up_mod);
		return lres;
	}

	int hurt(int v, int pos) {
		//cerr << "hurt " << v << " " << pos << endl;
		if (pos < 0) {
			return -1;
		}
		int pos1 = get_1_pos(v, pos, 0, n - 1, 0);
		//cerr << "pos1 = " << pos1 << endl;
		if (pos1 == -1) {
			return -1;
		}
		else {
			int v1 = update(v, pos1 + 1, pos, 1, 0, n - 1);
			v1 = update(v1, pos1, pos1, -1, 0, n - 1);
			if (t[v1].sum + t[v1].mod == 0) {
				return -1;
			}
			else {
				return v1;
			}
		}
	}

	struct creature {
		int v, hp_len, dmg;
		creature(int _v, int _hp_len, int _dmg): v(_v), hp_len(_hp_len), dmg(_dmg) {}
	};

	vector<creature> a;

	void summon_creature() {
		int v = t.size();
		t.push_back(t[v0]);
		v = update(v, 0, 0, 1, 0, n - 1);
		a.emplace_back(v, 1, 0);
	}

	void blessed_champion(int id) {
		if (a[id].v == -1) {
			return;
		}
		a[id].dmg++;
	}

	void divine_spirit(int id) {
		if (a[id].v == -1) {
			return;
		}
		a[id].hp_len++;
	}

	int molten_reflection(int id) {
		a.push_back(a[id]);
		if (a.back().v == -1) {
			return 1;
		}
		else {
			return 0;
		}
	}

	void hit(int id, int dmg) {
		int pos = a[id].hp_len - 1 - dmg;
		int v1 = hurt(a[id].v, pos);
		a[id].v = v1;
	}

	void print(int v, int tl, int tr, int up_mod, int R) {
		if (v == -1) {
			for (int i = tl; i <= min(tr, R); ++i) {
				cerr << up_mod;
			}
			return;
		}
		if (tl == tr) {
			if (tl <= R) {
				cerr << t[v].sum + up_mod;
			}
		}
		else {
			int tm = (tl + tr) >> 1;
			print(t[v].l, tl, tm, up_mod + t[v].mod, R);
			print(t[v].r, tm + 1, tr, up_mod + t[v].mod, R);
		}
	}

	void print(int id) {
		if (a[id].v == -1) {
			cerr << "dead";
		}
		else {
			print(a[id].v, 0, n - 1, 0, a[id].hp_len - 1);
		}
		cerr << "(" << a[id].v << ")";
	}

	void output() {
		cerr << "{";
		for (int i = 0; i < a.size(); ++i) {
			if (i) {
				cerr << ", ";
			}
			print(i);
		}
		cerr << "}" << endl;
	}

	pair<int, int> attack(int id1, int id2) {
		if (a[id1].v == -1 || a[id2].v == -1) {
			return {0, 0};
		}
		hit(id1, a[id2].dmg);
		hit(id2, a[id1].dmg);
		return {a[id1].v == -1, a[id2].v == -1};
	}
};

signed main() {
	fast_io();
	int q;
	cin >> q;
	vector<int> ans;
	solver s(q + 2);
	for (int i = 0; i < q; ++i) {
		//cerr << "i = " << i << endl;
		//s.output();
		int type;
		cin >> type;
		//cerr << "type = " << type << endl;
		if (type == 1) {
			ans.push_back(-1);
			s.summon_creature();
			continue;
		}
		if (type == 5) {
			int id1, id2;
			cin >> id1 >> id2;
			id1--;
			id2--;
			pair<int, int> pp = s.attack(id1, id2);
			if (pp.first) {
				ans[id1] = i;
			}
			if (pp.second) {
				ans[id2] = i;
			}
			continue;
		}
		int id;
		cin >> id;
		id--;
		if (type == 2) {
			s.blessed_champion(id);
		}
		if (type == 3) {
			s.divine_spirit(id);
		}
		if (type == 4) {
			if (s.molten_reflection(id)) {
				ans.push_back(i);
			}
			else {
				ans.push_back(-1);
			}
		}
	}
	cout << ans.size() << endl;
	for (auto x : ans) {
		if (x != -1) {
			x++;
		}
		cout << x << " ";
	}
	cout << endl;
}