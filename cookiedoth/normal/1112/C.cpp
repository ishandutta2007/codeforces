#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <random>
#include <numeric>
#include <functional>
#include <algorithm>
#include <string>
#include <cstring>
#include <cassert>
#include <iomanip>
#define ll long long
#define ld long double
#define null NULL
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(). a.rend()

using namespace std;

template<class iterator> void output(iterator begin, iterator end, ostream &out = cerr) {
	while (begin != end) {
		out << (*begin) << " ";
		begin++;
	}
	out << endl;
}

template<class T> void output(T &x, ostream &out = cerr) {
	output(x.begin(), x.end(), out);
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

const int mx = 5e5 + 228;
int m, k, n, s, a[mx], b[mx], cnt[2][mx], not_ok, ptr[mx];

int get(int pos) {
	return (cnt[0][pos] < cnt[1][pos]);
}

void upd(int id, int pos, int val) {
	//cerr << "upd " << id << " " << pos << " " << val << endl;
	not_ok -= get(pos);
	cnt[id][pos] += val;
	not_ok += get(pos);
	//cerr << "not_ok = " << not_ok << endl;
}

int main() {
	fast_io();
	cin >> m >> k >> n >> s;
	for (int i = 0; i < m; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < s; ++i) {
		cin >> b[i];
		upd(1, b[i], 1);
	}
	ptr[0] = -1;
	for (int i = 0; i < m; ++i) {
		while (ptr[i] < m - 1 && not_ok) {
			upd(0, a[ptr[i] + 1], 1);
			ptr[i]++;
		}
		if (ptr[i] == m - 1 && not_ok) {
			ptr[i] = m;
		}
		if (i < m - 1) {
			ptr[i + 1] = ptr[i];
			upd(0, a[i], -1);
		}
	}
	for (int i = 0; i < m; ++i) {
		chkmax(ptr[i], i + k - 1);
		if (ptr[i] > m) {
			ptr[i] = m;
		}
	}
	/*cerr << "ptr" << endl;
	output(ptr, ptr + m);*/

	int seg_l, cnt_l, cnt_r, ok = 0;
	for (int i = 0; i < m; ++i) {
		if (ptr[i] == m) {
			continue;
		}
		cnt_l = i / k;
		cnt_r = (m - 1 - ptr[i]) / k;
		if (cnt_l + cnt_r >= n - 1) {
			seg_l = i;
			ok = 1;
			break;
		}
	}

	if (ok == 0) {
		cout << -1 << endl;
		exit(0);
	}
	vector<int> remove;
	if (cnt_l > n - 1) {
		cnt_l = n - 1;
		cnt_r = 0;
	}
	else {
		if (cnt_l + cnt_r > n - 1) {
			cnt_r = n - 1 - cnt_l;
		}
	}
	for (int i = 0; i < seg_l - k * cnt_l; ++i) {
		remove.push_back(i);
	}
	for (int i = ptr[seg_l] + 1 + k * cnt_r; i < m; ++i) {
		remove.push_back(i);
	}

	int to_remove = ptr[seg_l] - seg_l + 1 - k;
	for (int i = seg_l; i <= ptr[seg_l]; ++i) {
		if (cnt[1][a[i]] > 0) {
			cnt[1][a[i]]--;
			continue;
		}
		if (to_remove && cnt[1][a[i]] == 0) {
			remove.push_back(i);
			to_remove--;
		}
	}

	cout << remove.size() << endl;
	for (auto x : remove) {
		cout << x + 1 << " ";
	}
	cout << endl;
}