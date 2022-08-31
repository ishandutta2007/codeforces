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

const int N = 5e5 + 10;
const ll inf = 2e18;

int a[N];
ll cur[N], temp[N];

int main() {
	int n, r; ll k;
	scanf("%d%d%lld", &n, &r, &k);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		int pl = max(1, i - r);
		int pr = min(n, i + r);
		cur[pl] += a[i];
		cur[pr + 1] -= a[i];
	}
	ll lo = 1, hi = inf;
	while (lo <= hi) {
		ll mid = (lo + hi) / 2, left = k;
		for (int i = 0; i <= n; ++i) {
			temp[i] = cur[i];
		}
		bool check = true;
		for (int i = 1; i <= n; ++i) {
			temp[i] += temp[i - 1];
			if (temp[i] < mid) {
				ll diff = mid - temp[i];
				if (diff > left) {
					check = false;
					break;
				}
				left -= diff;
				int p = min(n, i + r);
				int pr = min(n, p + r);
				temp[i] += diff;
				temp[pr + 1] -= diff;
			}
		}
		if (check) {
			lo = mid + 1;
		} else {
			hi = mid - 1;
		}
	}
	printf("%lld", lo - 1);
}