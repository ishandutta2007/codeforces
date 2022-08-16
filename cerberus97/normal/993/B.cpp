/*
Cerberus97
Hanit Banga
*/

#include <iostream>
#include <iomanip>
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

#define f first
#define s second

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 20;

pii p[3][N];

int common_ctr(pii p1, pii p2);
int common(pii p1, pii p2);

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> p[1][i].f >> p[1][i].s;
	}
	for (int i = 1; i <= m; ++i) {
		cin >> p[2][i].f >> p[2][i].s;
	}
	vector<pair<pii, pii>> answers;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (common_ctr(p[1][i], p[2][j]) == 1) {
				answers.pb({p[1][i], p[2][j]});
			}
		}
	}
	set<int> temp;
	for (auto &ans : answers) {
		temp.insert(common(ans.f, ans.s));
	}
	if (temp.size() == 1) {
		cout << *temp.begin();
		return 0;
	}
	bool know = true;
	for (auto &ans : answers) {
		pii p1 = ans.f;
		set<int> cand_common;
		for (int i = 1; i <= m; ++i) {
			if (common_ctr(p1, p[2][i]) == 1) {
				cand_common.insert(common(p1, p[2][i]));
			}
		}
		if (cand_common.size() > 1) {
			know = false;
			break;
		}
		cand_common.clear();
		pii p2 = ans.s;
		for (int i = 1; i <= n; ++i) {
			if (common_ctr(p2, p[1][i]) == 1) {
				cand_common.insert(common(p2, p[1][i]));
			}
		}
		if (cand_common.size() > 1) {
			know = false;
			break;
		}
	}
	if (know) {
		cout << 0;
	} else {
		cout << -1;
	}
}

int common_ctr(pii p1, pii p2) {
	int ans = 0;
	if (p1.f == p2.f or p1.f == p2.s) {
		++ans;
	}
	if (p1.s == p2.f or p1.s == p2.s) {
		++ans;
	}
	return ans;
}

int common(pii p1, pii p2) {
	if (p1.f == p2.f or p1.f == p2.s) {
		return p1.f;
	}
	return p1.s;
}