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
#include <numeric>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 10, mod = 998244353;

int add(int a, int b) {
	a += b;
	if (a >= mod) {
		a -= mod;
	}
	return a;
}

int sub(int a, int b) {
	a -= b;
	if (a < 0) {
		a += mod;
	}
	return a;
}

int mul(ll a, int b) {
	return (a * b) % mod;
}

int pwr(int x, int e) {
	int res = 1;
	while (e) {
		if (e & 1) {
			res = mul(res, x);
		}
		x = mul(x, x);
		e /= 2;
	}
	return res;
}

struct tournament {
	vector<int> p;
	int h = 0, i;
};

vector<tournament> get_pairs(int a, int l, int r);

int main() {
	fast_cin();
	int k, a, h;
	cin >> k >> a >> h;

	// vector<int> places = {5, 3, 5, 2, 1, 5, 5, 3};
	// int sum = 0;
	// for (int i = 1; i <= 8; ++i) {
	// 	sum = add(sum, mul(i, pwr(a, places[i - 1])));
	// }
	// cout << sum << endl;

	vector<tournament> v1, v2;
	v1 = get_pairs(a, 1, (1 << (k - 1)));
	v2 = get_pairs(a, (1 << (k - 1)) + 1, (1 << k));

	// vector<int> p1 = {5, 3, 5, 0}; // losing
	// vector<int> p2 = {0, 5, 5, 3}; // winning

	// int sz = v1.size();
	// assert(sz == v2.size());
	// for (int i = 0; i < sz; ++i) {
	// 	for (int j = 0; j < sz; ++j) {
	// 		if (v1[i].p == p1 and v2[j].p == p2) {
	// 			cout << i << ' ' << j << endl;
	// 			cout << v1[i].h << ' ' << v1[i].i << endl;
	// 			cout << v2[j].h << ' ' << v2[j].i << endl;
	// 			int check1 = 0, check2 = 0;
	// 			for (int i = 0; i < 4; ++i) {
	// 				if (p1[i]) {
	// 					check1 = add(check1, mul(i + 1, pwr(a, p1[i])));
	// 				}
	// 				if (p2[i]) {
	// 					check2 = add(check2, mul(i + 4 + 1, pwr(a, p2[i])));
	// 				}
	// 			}
	// 			cout << check1 << endl << check2 << endl;
	// 			int check = add(check1, check2);
	// 			check = add(check, mul(v1[i].i, pwr(a, 2)));
	// 			check = add(check, mul(v2[j].i, pwr(a, 1)));
	// 			cout << check << endl;
	// 		}
	// 	}
	// }

	for (int tc = 0; tc < 2; ++tc) {
		int sz = v1.size();
		map<int, int> mp;
		for (int i = 0; i < sz; ++i) {
			mp[sub(h, add(v1[i].h, mul(v1[i].i, a)))] = i;
		}
		for (int i = 0; i < sz; ++i) {
			int val = add(v2[i].h, mul(v2[i].i, mul(a, a)));
			if (mp.find(val) != mp.end()) {
				int ti = mp[val], tj = i;
				int winner = v1[ti].i;
				int second = v2[tj].i;
				if (tc == 1) {
					swap(ti, tj);
				}
				vector<int> ans = v1[ti].p;
				for (auto& pos : v2[tj].p) {
					ans.pb(pos);
				}
				ans[winner - 1] = 1;
				ans[second - 1] = 2;
				for (auto& pos : ans) {
					cout << pos << ' ';
				}
				cout << '\n';
				return 0;
			}
		}
		swap(v1, v2);
	}
	cout << -1 << '\n';
}

vector<tournament> get_pairs(int a, int l, int r) {
	int n = (r - l + 1), tot = (1 << (n - 1));
	vector<int> ids(n);
	vector<tournament> ans;
	iota(ids.begin(), ids.end(), l);
	for (int ch = 0; ch < tot; ++ch) {
		int mask = ch;
		tournament t;
		t.p.resize(n, 0);
		queue<int> q;
		for (int i = 0; i < n; ++i) {
			q.push(i);
		}
		int cur_rank = n + 1, rank_cnt = n / 2;
		while (q.size() > 1) {
			int p1 = q.front(); q.pop();
			int p2 = q.front(); q.pop();
			if (mask & 1) {
				t.p[p2] = cur_rank;
				t.h = add(t.h, mul(ids[p2], pwr(a, cur_rank)));
				q.push(p1);
			} else {
				t.p[p1] = cur_rank;
				t.h = add(t.h, mul(ids[p1], pwr(a, cur_rank)));
				q.push(p2);
			}
			mask /= 2;
			--rank_cnt;
			if (rank_cnt == 0) {
				cur_rank = ((cur_rank - 1) / 2) + 1;
				rank_cnt = (cur_rank - 1) / 2;
			}
		}
		t.i = ids[q.front()];
		ans.pb(t);
	}
	return ans;
}