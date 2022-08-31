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

int main() {
	fast_cin();
	int n, m;
	cin >> n >> m;
	vector<string> v1(n), v2(m);
	for (auto& s : v1) {
		cin >> s;
	}
	for (auto& s : v2) {
		cin >> s;
	}
	int q; cin >> q;
	while (q--) {
		int y; cin >> y;
		--y;
		cout << v1[y % n] + v2[y % m] << '\n';
	}
}