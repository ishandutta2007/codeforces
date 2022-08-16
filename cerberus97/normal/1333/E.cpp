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

const int N = 1e5 + 10;

vector<vector<int>> a = {
	{1, 7, 9}, 
	{3, 2, 5}, 
	{4, 8, 6},
};

int main() {
	fast_cin();
	int n; cin >> n;
	if (n <= 2) {
		cout << -1 << '\n';
	} else {
		int m = n * n;
		for (auto &i : a) {
			for (auto& j : i) {
				j += (m - 9);
			}
		}
		a.resize(n);
		for (auto& i : a) {
			i.resize(n, 0);
		}
		int s = m - 9;
		int r = 0, c = 0;
		while (s) {
			for (int j = 0; j < n; ++j) {
				if (!a[r][j]) {
					a[r][j] = s--;
					c = j;
				}
			}
			if (s) {
				a[++r][c] = s--;
			}
		}
		for (auto& i : a) {
			for (auto& j : i) {
				cout << j << ' ';
			}
			cout << '\n';
		}
	}
}