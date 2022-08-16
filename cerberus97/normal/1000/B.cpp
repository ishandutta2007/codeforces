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

const int N = 1e5 + 10;

int a[N];

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	a[n + 1] = m;
	int sum = 0, best = 0;
	for (int i = 1; i <= n + 1; i += 2) {
		sum += a[i] - a[i - 1];
	} 
	best = sum;
	int cur = 0;
	for (int i = n; i >= 0; --i) {
		if (i % 2 == 0) {
			if (a[i] < a[i + 1] - 1) {
				best = max(best, sum - cur + m - a[i + 1] - cur - 1);
			}
			cur += a[i + 1] - a[i];
		} else if (a[i] < a[i + 1] - 1) {
			best = max(best, sum - cur + m - cur - a[i] - 1);
		}
	}
	cout << best;
}