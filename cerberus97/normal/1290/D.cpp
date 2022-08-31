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

const int N = 1024 + 10;

int lo[N], hi[N];
bool dup[N], done[N][N];

void add_block(int l, int r);
bool add(int c);

int main() {
	fast_cin();
	int n, k;
	cin >> n >> k;
	k = max(1, k / 2);
	int g = n / k;
	for (int i = 0; i < g; ++i) {
		lo[i] = i * k;
		hi[i] = (i + 1) * k;
	}
	for (int i = 0; i < g; ++i) {
		for (int j = i + 1; j < g; ++j) {
			if (!done[i][j]) {
				cout << 'R' << endl;
				int cur = i;
				add_block(lo[i], hi[i]);
				for (int t = i + 1; t < g; ++t) {
					if (!done[cur][t]) {
						done[cur][t] = true;
						add_block(lo[t], hi[t]);
						cur = t;
					}
				}
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		ans += !dup[i];
	}
	cout << "! " << ans << endl;
}

void add_block(int l, int r) {
	for (int i = l; i < r; ++i) {
		if (!dup[i]) {
			dup[i] = add(i);
		}
	}
}

bool add(int c) {
	cout << "? " << c + 1 << endl;
	char ans; cin >> ans;
	return ans == 'Y';
}