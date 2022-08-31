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
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> x(n), y(n);
		for (auto& i : x) {
			cin >> i;
		}
		for (auto& i : y) {
			cin >> i;
		}
		sort(x.begin(), x.end());
		sort(y.begin(), y.end());
		for (auto& i : x) {
			cout << i << ' ';
		}
		cout << endl;
		for (auto& i : y) {
			cout << i << ' ';
		}
		cout << endl;
	}
}