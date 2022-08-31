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

const int N = 1e5 + 10, LOG = 30;

int main() {
	fast_cin();
	int n; cin >> n;
	vector<int> a(n);
	for (auto& i : a) {
		cin >> i;
	}
	for (int j = LOG; j >= 0; --j) {
		int cnt = 0, p = -1;
		for (int i = 0; i < n; ++i) {
			if ((a[i] >> j) & 1) {
				++cnt;
				p = i;
			}
		}
		if (cnt == 1) {
			swap(a[0], a[p]);
			break;
		}
	}
	for (auto& i : a) {
		cout << i << ' ';
	}
	cout << endl;
}