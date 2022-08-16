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

const int N = 2e3 + 10;

int p[N], par[N];
bool picked[N];

int get_move(int n);

int main() {
	fast_cin();
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= 2 * n; ++i) {
		cin >> p[i];
	}
	for (int i = 1; i <= m; ++i) {
		int a, b;
		cin >> a >> b;
		par[a] = b;
		par[b] = a;
	}
	int t; cin >> t;
	int moves = 2 * n;
	picked[0] = true;
	while (moves--) {
		if (t == 1) {
			int move = get_move(2 * n);
			picked[move] = true;
			cout << move << endl;
		} else {
			int x; cin >> x;
			picked[x] = true;
		}
		t = 3 - t;
	}	
}

int get_move(int n) {
	int best = -1, best_p = -1;
	for (int i = 1; i <= n; ++i) {
		if (picked[i] and !picked[par[i]]) {
			return par[i];
		} else if (!picked[i] and !picked[par[i]]) {
			int temp = abs(p[i] - p[par[i]]);
			if (temp > best) {
				best = temp;
				best_p = ((p[i] >= p[par[i]]) ? i : par[i]);
			}
		}
	}
	if (best >= 0) {
		return best_p;
	}
	for (int i = 1; i <= n; ++i) {
		if (!picked[i] and p[i] > best) {
			best = p[i];
			best_p = i;
		}
	}
	return best_p;
}