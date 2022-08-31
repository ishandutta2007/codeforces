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
	int n; cin >> n;
	vector<int> a(n + 1), b(n + 1), x(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> b[i];
	}
	a[1] = b[1];
	x[1] = 0;
	for (int i = 2; i <= n; ++i) {
		x[i] = max(x[i - 1], a[i - 1]);
		a[i] = x[i] + b[i];
	}
	for (int i = 1; i <= n; ++i) {
		cout << a[i] << ' ';
	}
	cout << endl;
}