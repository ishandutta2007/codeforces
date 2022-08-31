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
#include <bitset>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e4 + 10, M = 60;

bitset<N> have[M];

int main() {
	fast_cin();
	int m, n;
	cin >> m >> n;
	for (int i = 1; i <= m; ++i) {
		int s; cin >> s;
		for (int j = 0; j < s; ++j) {
			int c; cin >> c;
			have[i][c] = 1;
		}
	}
	for (int i = 1; i <= m; ++i) {
		for (int j = i + 1; j <= m; ++j) {
			if ((have[i] & have[j]) == 0) {
				cout << "impossible\n";
				return 0;
			}
		}
	}
	cout << "possible\n";
}