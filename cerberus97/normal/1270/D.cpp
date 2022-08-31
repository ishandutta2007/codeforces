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

const int N = 500 + 10;

pii query(int l, int r, int del);

int main() {
	fast_cin();
	int n, k;
	cin >> n >> k;
	auto tmp = query(1, k, -1);
	int i = tmp.first, val = tmp.second;
	int ans = 1;
	bool less = query(1, k + 1, i).second < val;
	for (int j = 1; j <= k; ++j) {
		if (j == i) {
			continue;
		}
		tmp = query(1, k + 1, j);
		if (tmp.first == i) {
			ans += less;
		} else {
			ans += tmp.second > val;
		}
	}
	cout << "! " << ans << endl;
}

pii query(int l, int r, int del) {
	cout << "? ";
	for (int i = l; i <= r; ++i) {
		if (i != del) {
			cout << i << ' ';
		}
	}
	cout << endl;
	int pos, val;
	cin >> pos >> val;
	return {pos, val};
}