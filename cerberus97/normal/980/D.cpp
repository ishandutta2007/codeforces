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

const int N = 5e3 + 10;

ll a[N];
int id[N], ans[N];
bool seen[N];

inline bool compatible(ll a, ll b);

int main() {
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	int nxt_id = 1;
	for (int i = 1; i <= n; ++i) {
		if (a[i]) {
			for (int j = 1; j < n; ++j) {
				if (a[j] and compatible(a[i], a[j])) {
					id[i] = id[j];
					break;
				}
			}
			if (!id[i]) {
				id[i] = nxt_id++;
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		memset(seen, 0, sizeof(seen));
		int k = 0;
		for (int j = i; j <= n; ++j) {
			if (id[j] and !seen[id[j]]) {
				++k;
			}
			seen[id[j]] = true;
			++ans[max(k, 1)];
		}
	}
	for (int i = 1; i <= n; ++i) {
		cout << ans[i] << ' ';
	}
}

inline bool compatible(ll a, ll b) {
	if (a * b < 0) {
		return false;
	}
	ll sq = sqrt(a * b) + 0.5;
	return (sq * sq == a * b);
}