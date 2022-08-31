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
#include <bitset>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 10, Q = 1e6 + 10, V = 7e3 + 10;

bitset<V> b[N], factors[V], s_multiples[V];
bool sfree[V];

void pre();

int main() {
	fast_cin();
	pre();
	int n, q;
	cin >> n >> q;
	while (q--) {
		int t, x, y, z, v;
		cin >> t;
		if (t == 1) {
			cin >> x >> v;
			b[x] = factors[v];
		} else if (t == 2) {
			cin >> x >> y >> z;
			b[x] = b[y] ^ b[z];
		} else if (t == 3) {
			cin >> x >> y >> z;
			b[x] = b[y] & b[z];
		} else {
			cin >> x >> v;
			cout << ((s_multiples[v] & b[x]).count() & 1);
		}
	}
}

void pre() {
	for (int i = 1; i < V; ++i) {
		int temp = i, sq = sqrt(i);
		sfree[i] = true;
		for (int j = 2; j <= sq; ++j) {
			if (temp % j == 0) {
				temp /= j;
				if (temp % j == 0) {
					sfree[i] = false;
					break;
				}
			}
		}
	}
	for (int i = 1; i < V; ++i) {
		for (int j = 1; j <= i; ++j) {
			if (i % j == 0) {
				factors[i][j] = 1;
				if (sfree[i / j]) {
					s_multiples[j][i] = 1;
				}
			}
		}
	}
}