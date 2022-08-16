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

const int N = 2e5 + 10, M = 55;

int factor[N];
int grundy[N];
bitset<N> can_reach[M];

int main() {
	fast_cin();
	int n, f;
	cin >> n >> f;
	for (int i = 1; i < N; ++i) {
		factor[i] = i;
	}
	for (int i = 2; i < N; ++i) {
		if (factor[i] == i) {
			for (int j = 2 * i; j < N; j += i) {
				factor[j] = min(factor[j], i);
			}
		}
	}
	bitset<N> moves = 0;
	for (int i = 2; i < N; ++i) {
		int p = factor[i];
		if (i != f and factor[p] == p and factor[i / p] == i / p) {
			moves[i] = 1;
		}
	}
	// // Brute force grundy values
	// for (int i = 0; i < N; ++i) {
	// 	for (auto &j : act_moves) {
	// 		if (j > i) {
	// 			break;
	// 		}
	// 		temp[i][grundy[i - j]] = true;
	// 	}
	// 	while (temp[i][grundy[i]]) {
	// 		++grundy[i];
	// 	}
	// }
	for (int i = 0; i < N; ++i) {
		while (can_reach[grundy[i]][i]) {
			++grundy[i];
		}
		can_reach[grundy[i]] |= (moves << i);
	}
	int ans = 0;
	while (n--) {
		int b, w, r;
		cin >> b >> w >> r;
		ans ^= grundy[r - w - 1] ^ grundy[w - b - 1];
	}
	string a1 = "Alice\n", a2 = "Bob\n";
	if (!ans) {
		swap(a1, a2);
	}
	cout << a1 << a2;
}