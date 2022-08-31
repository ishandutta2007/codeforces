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

const int N = 1e3 + 10, P = 15;

int pos[P], comp[P];
int _t, _c, _q;

void move(vector<int> players);

int main() {
	fast_cin();
#ifdef LOCAL
	cin >> _t >> _c;
	_q = 3 * (_t + _c);
#endif
	int p = 10;
	for (int i = 0; i < p; ++i) {
		comp[i] = 0;
	}
	int c = 0;
	move({0, 1});
	move({1});
	while (true) {
		move({0, 1});
		move({1});
		if (comp[0] == comp[1]) {
			break;
		}
	}
	vector<int> all;
	for (int i = 0; i < p; ++i) {
		all.pb(i);
	}
	while (comp[0] != comp[2]) {
		move(all);
	}
#ifdef LOCAL
	cout << c << endl;
	cout << 3 * (_t + _c) << ' ' << 3 * (_t + _c) - _q << endl;
	assert(_q >= 0);
	for (int i = 0; i < p; ++i) {
		assert(pos[i] >= _t and (pos[i] - _t) % _c == 0);
	}
	cout << "ok" << endl;
#else
	cout << "done" << endl;
#endif
}

void move(vector<int> players) {
	string print = "next ";
	for (auto &i : players) {
		++pos[i];
		print += char(i + '0');
		print += ' ';
	}
#ifdef LOCAL
	--_q;
	int nxt = 0;
	for (int i = 0; i < 10; ++i) {
		comp[i] = -1;
		for (int j = 0; j < i; ++j) {
			if (pos[i] == pos[j]) {
				comp[i] = comp[j];
				break;
			} else if (pos[i] >= _t and pos[j] >= _t and (pos[i] - pos[j]) % _c == 0) {
				comp[i] = comp[j];
				break;
			}
		}
		if (comp[i] == -1) {
			comp[i] = nxt++;
		}
	}
#else
	cout << print << endl;
	int k; cin >> k;
	for (int i = 0; i < k; ++i) {
		string s; cin >> s;
		for (auto &c : s) {
			comp[c - '0'] = i;
		}
	}
#endif
}