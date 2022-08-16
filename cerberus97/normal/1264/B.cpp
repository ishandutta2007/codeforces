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

const int N = 1e5 + 10;

int cnt[4], used[4];

void solve(int p, int n);

int main() {
	fast_cin();
	int n = 0;
	for (int i = 0; i < 4; ++i) {
		cin >> cnt[i];
		n += cnt[i];
	}
	solve(0, n);
	solve(1, n);
	cout << "NO\n";
}

void solve(int p, int n) {
	memset(used, 0, sizeof(used));
	vector<int> ans(n, -1);
	for (auto &i : ans) {
		for (int j = p; j < 4; j += 2) {
			if (used[j] < cnt[j]) {
				++used[j];
				i = j;
				break;
			}
		}
		if (i == -1) {
			return;
		}
		p ^= 1;
	}
	for (int i = 0; i < n - 1; ++i) {
		if (abs(ans[i] - ans[i + 1]) != 1) {
			return;
		}
	}
	cout << "YES\n";
	for (auto &i : ans) {
		cout << i << ' ';
	}
	cout << endl;
	exit(0);
}