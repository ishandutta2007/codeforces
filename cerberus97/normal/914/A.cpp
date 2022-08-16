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

const int N = 1e5 + 10, inf = 1e7;

bool check(int x);

int main() {
	int n, ans = -inf;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		if (check(x) and x > ans) {
			ans = x;
		}
	}

	cout << ans;
}

bool check(int x) {
	int test = sqrt(x);
	for (int i = test - 2; i <= test + 2; ++i) {
		if (i * i == x) {
			return false;
		}
	}

	return true;
}