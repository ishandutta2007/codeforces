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

int A[3], b[3], c[3], ctr[3][10];
vector<int> factors[N];
bool seen[8][8][8];

void sieve();
inline bool set_bit(int num, int bit);
inline int ch2(int x);
inline int ch3(int x);
// int brute_force();

int main() {
	fast_cin();
	sieve();
	int t; cin >> t;
	while (t--) {
		int ans = 0;
		for (int i = 0; i < 3; ++i) {
			cin >> A[i];
			// ans *= factors[A[i]].size();
		}
		memset(ctr, 0, sizeof(ctr));
		for (int i = 0; i < 3; ++i) {
			for (auto &j : factors[A[i]]) {
				int mask = 0;
				for (int k = 0; k < 3; ++k) {
					if (A[k] % j == 0) {
						mask |= (1 << k);
					}
				}
				++ctr[i][mask];
				// cout << i << ' ' << mask << endl;
			}
		}
		memset(seen, 0, sizeof(seen));
		for (b[0] = 0; b[0] < 8; ++b[0]) {
			if (!set_bit(b[0], 0)) {
				continue;
			}
			for (b[1] = 0; b[1] < 8; ++b[1]) {
				if (!set_bit(b[1], 1)) {
					continue;
				}
				for (b[2] = 0; b[2] < 8; ++b[2]) {
					if (!set_bit(b[2], 2)) {
						continue;
					}
					bool good = true;
					for (int i = 0; i < 3; ++i) {
						c[i] = ctr[i][b[i]];
						if (!c[i]) {
							good = false;
							break;
						}
					}
					if (!good) {
						continue;
					}
					vector<int> check = {b[0], b[1], b[2]};
					sort(check.begin(), check.end());
					if (seen[check[0]][check[1]][check[2]]) {
						continue;
					} else {
						seen[check[0]][check[1]][check[2]] = true;
					}
					// cout << endl;
					if (b[0] == b[1] and b[1] == b[2]) {
						ans += ch3(c[0]) + 2 * ch2(c[1]) + c[2];
					} else if (b[0] == b[1]) {
						ans += c[2] * (ch2(c[0]) + c[0]);
					} else if (b[1] == b[2]) {
						ans += c[0] * (ch2(c[1]) + c[1]);
					} else if (b[0] == b[2]) {
						ans += c[1] * (ch2(c[0]) + c[0]);
					} else {
						ans += c[0] * c[1] * c[2];
					}
				}
			}
		}
		cout << ans << '\n';
	}
}

void sieve() {
	for (int i = 1; i < N; ++i) {
		for (int j = i; j < N; j += i) {
			factors[j].pb(i);
		}
	}
}

inline bool set_bit(int num, int bit) {
	return num & (1 << bit);
}

inline int ch2(int x) {
	if (x < 2) {
		return 0;
	}
	return (x * (x - 1)) / 2;
}

inline int ch3(int x) {
	if (x < 3) {
		return 0;
	}
	return (x * (x - 1) * (x - 2)) / 6;
}

// int brute_force() {
// 	set<vector<int>> s;
// 	for (auto &a : factors[A[0]]) {
// 		for (auto &b : factors[A[1]]) {
// 			for (auto &c : factors[A[2]]) {
// 				vector<int> temp = {a, b, c};
// 				sort(temp.begin(), temp.end());
// 				s.insert(temp);
// 			}
// 		}
// 	}
// 	// for (auto &v : s) {
// 	// 	for (auto &i : v) {
// 	// 		cout << i << ' ';
// 	// 	}
// 	// 	cout << endl;
// 	// }
// 	return s.size();
// }