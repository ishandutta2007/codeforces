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

const int N = 2e5 + 10, M = N;

int a[N];
ll suff[N], s[N + M];

int main() {
	fast_cin();
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n, greater<int>());
	for (int i = n; i >= 1; --i) {
		suff[i] = a[i] + suff[i + 1];
		s[i] = suff[i] + s[i + m];
	}
	for (int k = 1; k <= n; ++k) {
		cout << s[n - k + 1] << ' ';
	}
}