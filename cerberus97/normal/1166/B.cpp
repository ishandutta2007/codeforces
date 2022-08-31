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

char vowel[5] = {'a', 'e', 'i', 'o', 'u'};

int main() {
	fast_cin();
	int k; cin >> k;
	for (int i = 1; i <= k; ++i) {
		if (k % i == 0) {
			if (i >= 5 and k / i >= 5) {
				int n = i, m = k / i;
				for (int r = 0; r < n; ++r) {
					for (int c = 0; c < m; ++c) {
						cout << vowel[(r + c) % 5];
					}
				}
				cout << endl;
				return 0;
			}
		}
	}
	cout << -1 << endl;
}