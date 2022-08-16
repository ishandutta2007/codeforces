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

const int N = 1e2 + 10;

bool check(int num, int den);

int a[N];

int main() {
	int n; cin >> n;
	int sum = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		sum += a[i];
	}
	sort(a + 1, a + 1 + n);
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		if (check(sum, n)) {
			break;
		}
		++ans;
		sum += 5 - a[i];
	}
	cout << ans;
}

bool check(int num, int den) {
	return (2 * num >= 9 * den);
}