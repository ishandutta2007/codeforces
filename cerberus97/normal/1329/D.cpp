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

const int N = 2e5 + 10, A = 26;

int tree[4 * N];
set<pii> where[A][A];

void del(int p, int len, int& cur_len, int n, vector<pii>& ans);
void update(int i, int l, int r, int p, int x);
int query(int i, int l, int r, int ql, int qr);

int main() {
	fast_cin();
	int t; cin >> t;
	while (t--) {
		string s; cin >> s;
		for (auto& c : s) {
			c -= 'a';
		}
		int n = s.length();
		s = 'a' + s;
		memset(tree, 0, sizeof(tree[0]) * 4 * (n + 1));
		for (int x = 0; x < A; ++x) {
			for (int y = 0; y < A; ++y) {
				where[x][y].clear();
			}
		}
		set<pii> pairs;
		vector<int> cnt(A, 0), lpartner(n + 1, 0), rpartner(n + 1, 0);
		for (int i = 1; i < n; ++i) {
			if (s[i] == s[i + 1]) {
				pairs.insert({i, i + 1});
				rpartner[i] = i + 1;
				lpartner[i + 1] = i;
				++cnt[s[i]];
			}
		}
		if (pairs.size() >= 2) {
			auto prv = pairs.begin();
			auto it = next(prv);
			while (it != pairs.end()) {
				int c1 = s[prv->first], c2 = s[it->first];
				where[c1][c2].insert({prv->second, it->first});
				where[c2][c1].insert({prv->second, it->first});
				++prv; ++it;
			}
		}
		vector<pii> ans;
		int cur_len = n;
		while (cur_len) {
			if (pairs.empty()) {
				ans.pb({1, cur_len});
				break;
			} else if (pairs.size() == 1) {
				int p = (pairs.begin())->first;
				del(1, p, cur_len, n, ans);
				pairs.clear();
			} else {
				int maj = 0;
				for (int i = 0; i < A; ++i) {
					if (cnt[i] > cnt[maj]) {
						maj = i;
					}
				}
				int type = (cnt[maj] == pairs.size()) ? 1 : 2;
				// cout << char(maj + 'a') << ' ' << type << endl;
				for (int j = 0; j < A; ++j) {
					if (type == 2 and j == maj) {
						continue;
					} else if (!where[j][maj].empty()) {
						// cout << char(j + 'a') << ' ' << char(maj + 'a') << endl;
						auto cur = *where[j][maj].begin();
						where[j][maj].erase(where[j][maj].begin());
						where[maj][j].erase(cur);
						int q1 = cur.first, p2 = cur.second;
						int p1 = lpartner[q1], q2 = rpartner[p2];
						// cout << "partners: " << p1 << ' ' << q1 << ' ' << p2 << ' ' << q2 << endl;
						// cout << pairs.size() << endl;
						pairs.erase({p1, q1});
						pairs.erase({p2, q2});
						// cout << pairs.size() << endl;
						del(q1, p2, cur_len, n, ans);
						--cnt[j]; --cnt[maj];
						if (j == maj) {
							++cnt[j];
							pairs.insert({p1, q2});
							rpartner[p1] = q2;
							lpartner[q2] = p1;
						} else {
							auto it = pairs.lower_bound({q2, 0});
							int x = -1, y = -1;
							if (it != pairs.end()) {
								int c = s[it->first];
								where[s[q2]][c].erase({q2, it->first});
								where[c][s[q2]].erase({q2, it->first});
								y = it->first;
							}
							if (it != pairs.begin()) {
								it = prev(it);
								int c = s[it->second];
								where[s[p1]][c].erase({it->second, p1});
								where[c][s[p1]].erase({it->second, p1});
								x = it->second;
							}
							// cout << "haha " << x << ' ' << y << endl;
							if (x != -1 and y != -1) {
								where[s[x]][s[y]].insert({x, y});
								where[s[y]][s[x]].insert({x, y});
							}
						}
						break;
					}
				}
			}
		}
		cout << ans.size() << '\n';
		for (auto& p : ans) {
			cout << p.first << ' ' << p.second << '\n';
		}
		// cout << endl;
	}
}

void del(int p, int q, int& cur_len, int n, vector<pii>& ans) {
	int l = p - query(1, 1, n, 1, p);
	int r = q - query(1, 1, n, 1, q);
	// cout << p << ' ' << q << ' ' << l << ' ' << r << endl;
	int len = r - l + 1;
	ans.pb({l, r});
	// cout << l << ' ' << r << endl;
	update(1, 1, n, p, len);
	cur_len -= len;
}

void update(int i, int l, int r, int p, int x) {
	if (p < l or p > r) {
		return;
	} else if (l == r) {
		tree[i] += x;
	} else {
		int mid = (l + r) / 2, lc = 2 * i, rc = lc + 1;
		update(lc, l, mid, p, x);
		update(rc, mid + 1, r, p, x);
		tree[i] = tree[lc] + tree[rc];
	}
}

int query(int i, int l, int r, int ql, int qr) {
	if (l > qr or ql > r) {
		return 0;
	} else if (ql <= l and r <= qr) {
		return tree[i];
	} else {
		int mid = (l + r) / 2, lc = 2 * i, rc = lc + 1;
		return query(lc, l, mid, ql, qr) + query(rc, mid + 1, r, ql, qr);
	}
}