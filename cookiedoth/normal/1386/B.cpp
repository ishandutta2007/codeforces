/*

Code for problem B by cookiedoth
Generated 22 Jul 2020 at 05.34 PM


_____________
_____________
_____________
_____________ ______
_____________
_____________
___________ ________

-_-
~_^
=_=

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
#define i128 __int128
#define ll long long
#define ld long double
#define null NULL
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
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

const int dim = 3;

const vector<ll> BAD = {-1, -1, -1};
const vector<ll> GOOD = {-2, -2, -2};

vector<ll> target;
int q;
vector<vector<ll> > a;
vector<int> is_zero;
vector<pair<int, int> > Q;

int check_good(const vector<ll> &vec) {
	i128 x1 = vec[1] * target[0];
	i128 y1 = vec[2] * target[0];
	i128 tx = target[1] * vec[0];
	i128 ty = target[2] * vec[0];
	return (x1 == tx && y1 == ty);
}

void read() {
	int dim0 = -1;
	target.resize(dim);
	for (int i = 0; i < dim; ++i) {
		cin >> target[i];
		if (target[i] && dim0 == -1) {
			dim0 = i;
		}
	}
	swap(target[dim0], target[0]);
	cin >> q;
	vector<ll> new_vec(dim);
	for (int i = 0; i < q; ++i) {
		char c;
		cin >> c;
		if (c == 'A') {
			int cur_is_zero = 0;
			for (int j = 0; j < dim; ++j) {
				cin >> new_vec[j];
			}
			swap(new_vec[dim0], new_vec[0]);
			if (new_vec[0] == 0) {
				cur_is_zero = 1;
				new_vec[0] = 1;
			}
			int bad = 0;
			for (int j = 0; j < dim; ++j) {
				if (target[j] == 0 && new_vec[j] != 0) {
					bad = 1;
				}
			}
			int good = 0;
			if (bad == 0 && cur_is_zero == 0) {
				good = check_good(new_vec);
			}
			Q.emplace_back(a.size(), 0);
			a.push_back(bad ? BAD : (good ? GOOD : new_vec));
			is_zero.push_back(cur_is_zero);
		} else {
			int id;
			cin >> id;
			id--;
			Q.emplace_back(id, 1);
		}
	}
}

void print_stupid(int id) {
	if (a[id] == BAD) {
		cerr << "bad" << endl;
		return;
	}
	if (a[id] == GOOD) {
		cerr << "good" << endl;
		return;
	}
	ld x1 = (ld)a[id][1] / (ld)a[id][0];
	ld y1 = (ld)a[id][2] / (ld)a[id][0];
	ld tx = (ld)target[1] / (ld)target[0];
	ld ty = (ld)target[2] / (ld)target[0];
	if (is_zero[id] == 0) {
		x1 -= tx;
		y1 -= ty;
	}
	cerr << x1 << " " << y1 << endl;
}

int sign(i128 a) {
	return (a < 0 ? -1 : (a > 0));
}

int cross_sign(int id1, int id2) {
	i128 x1 = a[id1][1] * target[0] * a[id2][0];
	i128 y1 = a[id1][2] * target[0] * a[id2][0];
	i128 x2 = a[id2][1] * target[0] * a[id1][0];
	i128 y2 = a[id2][2] * target[0] * a[id1][0];
	i128 tx = target[1] * a[id1][0] * a[id2][0];
	i128 ty = target[2] * a[id1][0] * a[id2][0];
	if (is_zero[id1] == 0) {
		x1 -= tx;
		y1 -= ty;
	}
	if (is_zero[id2] == 0) {
		x2 -= tx;
		y2 -= ty;
	}
	i128 cross = (x1 * y2 - x2 * y1);
	return sign(cross);
}

int dot_sign(int id1, int id2) {
	i128 x1 = a[id1][1] * target[0] * a[id2][0];
	i128 y1 = a[id1][2] * target[0] * a[id2][0];
	i128 x2 = a[id2][1] * target[0] * a[id1][0];
	i128 y2 = a[id2][2] * target[0] * a[id1][0];
	i128 tx = target[1] * a[id1][0] * a[id2][0];
	i128 ty = target[2] * a[id1][0] * a[id2][0];
	if (is_zero[id1] == 0) {
		x1 -= tx;
		y1 -= ty;
	}
	if (is_zero[id2] == 0) {
		x2 -= tx;
		y2 -= ty;
	}
	i128 dot = (x1 * x2 + y1 * y2);
	return sign(dot);
}

pair<int, int> get_coord_signs(int id) {
	i128 x1 = a[id][1] * target[0];
	i128 y1 = a[id][2] * target[0];
	i128 tx = target[1] * a[id][0];
	i128 ty = target[2] * a[id][0];
	if (!is_zero[id]) {
		x1 -= tx;
		y1 -= ty;
	}
	return {sign(x1), sign(y1)};
}

bool cmp(int id1, int id2) {
	return cross_sign(id1, id2) == 1;
}

int good_cnt = 0;

int is_upper(pair<int, int> S) {
	return (S.first > 0 || (S.first == 0 && S.second > 0));
}

bool polar_cmp(int id1, int id2) {
	int t1 = is_upper(get_coord_signs(id1));
	int t2 = is_upper(get_coord_signs(id2));
	if (t1 > t2) {
		return 0;
	}
	if (t1 < t2) {
		return 1;
	}
	return cross_sign(id1, id2) == 1;
}

vector<int> order, classId, classRep, revClass, cnt;

void build() {
	int AP = a.size();
	// cerr << "build" << endl;
	// cerr << "AP = " << AP << endl;
	// for (int i = 0; i < AP; ++i) {
	// 	print_stupid(i);
	// }
	// cerr << "signs" << endl;
	// for (int i = 0; i < AP; ++i) {
	// 	if (a[i] != GOOD && a[i] != BAD) {
	// 		pair<int, int> pp = get_coord_signs(i);
	// 		cerr << pp.first << " " << pp.second << endl;
	// 	}
	// }
	for (int i = 0; i < AP; ++i) {
		if (a[i] != GOOD && a[i] != BAD) {
			order.push_back(i);
		}
	}
	// output(all(order));
	sort(all(order), polar_cmp);
	// cerr << "done sort" << endl;
	// output(all(order));
	int cur_class_id = 0;
	classId.resize(AP);
	for (int i = 1; i < order.size(); ++i) {
		if (polar_cmp(order[i - 1], order[i])) {
			cur_class_id++;
		}
		classId[order[i]] = cur_class_id;
	}
	classRep.resize(cur_class_id + 1);
	for (auto x : order) {
		classRep[classId[x]] = x;
	}
	// cerr << "/build" << endl;

	int classCnt = cur_class_id + 1;
	revClass.resize(classCnt);
	for (int i = 0; i < classCnt; ++i) {
		int l = 1, r = classCnt;
		while (l < r) {
			int mid = (l + r) >> 1;
			if (cross_sign(classRep[i], classRep[(i + mid) % classCnt]) != 1) {
				r = mid;
			} else {
				l = mid + 1;
			}
		}
		if (l != classCnt && cross_sign(classRep[i], classRep[(i + l) % classCnt]) == 0) {
			revClass[i] = (i + l) % classCnt;
		} else {
			revClass[i] = -1;
		}
	}

	cnt.resize(classCnt);
}

multiset<int> upper, lower;
ll pair2;

void make_change(int id, int type) {
	if (a[id] == BAD) {
		return;
	}
	if (a[id] == GOOD) {
		good_cnt += (type == 0 ? 1 : -1);
	}
	int cl = classId[id];
	if (type == 0) {
		if (revClass[cl] != -1) {
			pair2 += cnt[revClass[cl]];
		}
		cnt[cl]++;
		if (is_upper(get_coord_signs(id))) {
			upper.insert(classId[id]);
		} else {
			lower.insert(classId[id]);
		}
	} else {
		if (revClass[cl] != -1) {
			pair2 -= cnt[revClass[cl]];
		}
		cnt[cl]--;
		if (is_upper(get_coord_signs(id))) {
			upper.erase(upper.find(classId[id]));
		} else {
			lower.erase(lower.find(classId[id]));
		}
	}
}

int get() {
	if (good_cnt) {
		return 1;
	}
	if (pair2) {
		return 2;
	}
	if (!upper.empty() && !lower.empty()) {
		int t1 = classRep[(*upper.begin())];
		int t2 = classRep[(*prev(upper.end()))];
		int t3 = classRep[(*lower.begin())];
		int t4 = classRep[(*prev(lower.end()))];
		if (cross_sign(t4, t1) == 1 && cross_sign(t2, t3) == 1) {
			return 3;
		}
	}
	// for (int t1 = 0; t1 < cur.size(); ++t1) {
	// 	for (int t2 = 0; t2 < cur.size(); ++t2) {
	// 		for (int t3 = 0; t3 < cur.size(); ++t3) {
	// 			if (t1 != t2 && t1 != t3 && t2 != t3 && cross_sign(cur[t1], cur[t2]) == 1 && cross_sign(cur[t2], cur[t3]) == 1 && cross_sign(cur[t3], cur[t1]) == 1) {
	// 				return 3;
	// 			}
	// 		}
	// 	}
	// }
	return 0;
}

void process() {
	for (int i = 0; i < q; ++i) {
		make_change(Q[i].first, Q[i].second);
		int res = get();
		cout << res << '\n';
	}
}

signed main() {
	fast_io();
	cerr << setprecision(4) << fixed;
	read();
	build();
	process();
}