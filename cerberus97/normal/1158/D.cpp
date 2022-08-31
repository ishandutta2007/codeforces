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

const int N = 2e3 + 10;
const ll inf = 1e9 + 42;

pll pt[N];
int ans[N];
bool done[N];

ll cross(pll A, pll B, pll C);

int main() {
	fast_cin();
	int n; cin >> n;
	int p = 1;
	for (int i = 1; i <= n; ++i) {
		cin >> pt[i].first >> pt[i].second;
		if (pt[i] < pt[p]) {
			p = i;
		}
	}
	string s; cin >> s;
	done[p] = true;
	ans[1] = p;
	int nxt = 2;
	pll c_pt = pt[p];
	for (auto &c : s) {
		pll t_pt = c_pt;
		int id = -1;
		for (int i = 1; i <= n; ++i) {
			if (done[i]) {
				continue;
			} else if (id == -1) {
				t_pt = pt[i];
				id = i;
			} else if (c == 'L' and cross(c_pt, t_pt, pt[i]) <= 0) {
				id = i;
				t_pt = pt[i];
			} else if (c == 'R' and cross(c_pt, t_pt, pt[i]) >= 0) {
				id = i;
				t_pt = pt[i];
			}
		}
		done[id] = true;
		ans[nxt++] = id;
		c_pt = t_pt;
	}
	for (int i = 1; i <= n; ++i) {
		if (!done[i]) {
			ans[nxt++] = i;
		}
	}
	for (int i = 1; i <= n; ++i) {
		cout << ans[i] << ' ';
	}
	cout << endl;
}

ll cross(pll A, pll B, pll C) {
	return (B.first - A.first) * (C.second - A.second) - (B.second - A.second) * (C.first - A.first);
}