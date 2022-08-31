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

const int N = 2e3 + 10;

int solve(int l, int r);
int a[N], c1[N], c2[N];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		c1[i] = c1[i - 1] + (a[i] == 1);
		c2[i] = c2[i - 1] + (a[i] == 2);
	}
	for (int i = 1; i <= n; ++i) {
		ans = max(ans, solve(1, i) + solve(i + 1, n));
	}
	cout << ans;
}

int solve(int l, int r) {
	if (l > r) {
		return 0;
	}
	int ans = 0;
	for (int i = l - 1; i <= r; ++i) {
		int temp = c1[i] - c1[l - 1] + c2[r] - c2[i - 1];
		ans = max(ans, temp);
	}
	return ans;
}