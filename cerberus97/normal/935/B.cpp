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

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 10;

int main() {
	int n; string s;
	cin >> n >> s;
	int k = 0, ans = 0, x = 0, y = 0;
	for (auto &c : s) {
		if (c == 'U') {
			++y;
		} else {
			++x;
		}
		if (x < y) {
			if (k == 2) {
				++ans;
			}
			k = 1;
		} else if (x > y) {
			if (k == 1) {
				++ans;
			}
			k = 2;
		}
	}
	cout << ans;
}