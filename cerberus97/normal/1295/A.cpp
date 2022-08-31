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

int main() {
	fast_cin();
	vector<int> segments = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int len = n / 2;
		for (int i = len; i > 0; --i) {
			for (int d = 9; d >= 0; --d) {
				if (n >= segments[d] and (n - segments[d]) / 2 >= i - 1) {
					n -= segments[d];
					cout << d;
					break;
				}
			}
		}
		cout << '\n';
	}
}