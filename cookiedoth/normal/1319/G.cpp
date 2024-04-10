#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <string>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <cmath>
#include <queue>
#include <deque>
#include <numeric>
#include <random>
#include <ctime>
#define ll long long
#define ld long double
#define null NULL
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

using namespace std;

template<class iterator> void output(iterator begin, iterator end, ostream& out = cerr) {
	while (begin != end) {
		out << (*begin) << " ";
		begin++;
	}
	out << endl;
}

template<class T> void output(const T &x, ostream &out = cerr) {
	output(all(x), out);
}

template<class T> int chkmin(T &a, const T &b) {
	if (b < a) {
		a = b;
		return 1;
	}
	return 0;
}

template<class T> int chkmax(T &a, const T &b) {
	if (b > a) {
		a = b;
		return 1;
	}
	return 0;
}

void fast_io() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

mt19937 rng(time(NULL));

struct hasher {
	int MOD, p = 0;

	hasher(int _MOD) {
		MOD = _MOD;
		while (p < 1000) {
			p = rng() % MOD;
		}
	}

	int n;
	vector<int> deg, h;

	int mul(int a, int b) {
		return (1LL * a * b) % MOD;
	}

	void load(vector<int> v) {
		n = v.size();
		deg.resize(n + 1);
		h.resize(n + 1);
		deg[0] = 1;
		for (int i = 1; i <= n; ++i) {
			deg[i] = mul(deg[i - 1], p);
		}
		for (int i = n - 1; i >= 0; --i) {
			h[i] = (mul(h[i + 1], p) + v[i]) % MOD;
		}
	}

	int get_hash(int l, int r) {
		return (h[l] - mul(h[r + 1], deg[r - l + 1]) + MOD) % MOD;
	}
};

const ll MOD1 = 1e9 + 7;
const ll MOD2 = 998244353;
const int mx = 2e5 + 228;
int n, s[mx], r0[mx], l0[mx], zero_id[mx], zero_pos_by_id[mx];
vector<int> mid_data;
hasher H1(MOD1), H2(MOD2);

pair<int, int> get_hash(int l, int r) {
	return {H1.get_hash(l, r), H2.get_hash(l, r)};
}

void read() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		char c;
		cin >> c;
		s[i] = c - '0';
	}
}

void gen_lr0() {
	int last_0 = -1;
	for (int i = 0; i < n; ++i) {
		if (s[i] == 0) {
			last_0 = i;
		}
		l0[i] = last_0;
	}
	last_0 = n;
	for (int i = n - 1; i >= 0; --i) {
		if (s[i] == 0) {
			last_0 = i;
		}
		r0[i] = last_0;
	}
	fill(zero_id, zero_id + n, -1);
	int cur_zero = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] == 0) {
			zero_pos_by_id[cur_zero] = i;
			zero_id[i] = cur_zero++;
		}
	}
	for (int i = 1; i < cur_zero; ++i) {
		mid_data.push_back((zero_pos_by_id[i] - zero_pos_by_id[i - 1] - 1) % 2);
	}
	H1.load(mid_data);
	H2.load(mid_data);
}

struct data {
	int l, r, b1, b2;
};

data get(int l, int r) {
	int left_0 = r0[l], right_0 = l0[r];
	if (left_0 > right_0) {
		return {0, -2, (r - l + 1) % 2, (r - l + 1) % 2};
	} else {
		return {zero_id[left_0], zero_id[right_0] - 1, (left_0 - l) % 2, (r - right_0) % 2};
	}
}

int equal(data a, data b) {
	if (a.b1 != b.b1 || a.b2 != b.b2) {
		return 0;
	}
	if (a.r - a.l != b.r - b.l) {
		return 0;
	}
	if (a.r - a.l == -2 || a.r - a.l == -1) {
		return 1;
	}
	return get_hash(a.l, a.r) == get_hash(b.l, b.r);
}

void process() {
	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		int l1, r1, l2, r2, len;
		cin >> l1 >> l2 >> len;
		l1--;
		l2--;
		r1 = l1 + len - 1;
		r2 = l2 + len - 1;
		data d1 = get(l1, r1);
		data d2 = get(l2, r2);
		int res = equal(d1, d2);
		cout << (res ? "Yes" : "No") << "\n";
	}
}

signed main() {
	fast_io();
	read();
	gen_lr0();
	process();
}