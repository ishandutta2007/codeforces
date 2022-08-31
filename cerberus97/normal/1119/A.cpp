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

const int N = 3e5 + 10;

int c[N];

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> c[i];
	}
	int best = 0;
	for (int i = n; i >= 1; --i) {
		if (c[i] != c[1]) {
			best = max(best, i - 1);
		}
	}
	int l = 2;
	while (c[l] == c[l - 1]) {
		++l;
	}
	for (int i = n; i >= l; --i) {
		if (c[i] != c[l]) {
			best = max(best, i - l);
		}
	}
	cout << best << endl;
}