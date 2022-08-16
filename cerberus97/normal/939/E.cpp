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
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 5e5 + 10;

ld a[N];

int main() {
	fast_cin();
	int q;
	cin >> q;
	ld best = 0, sum = 0;
	int n = 0, i = 0;
	while (q--) {
		int t;
		cin >> t;
		if (t == 1) {
			cin >> a[++n];
			best = ((a[n] * i - sum) / (i + 1));
			while (i + 1 < n) {
				if (a[n] >= ((i + 1) * a[i + 1] - sum)) {
					++i;
					sum += a[i];
					best = ((a[n] * i - sum) / (i + 1));
				} else {
					break;
				}
			}
		} else {
			cout << fixed << setprecision(9) << best << '\n';
		}
	}
}