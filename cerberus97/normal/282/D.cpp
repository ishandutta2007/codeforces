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
#include <bitset>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 300 + 10, B = 520;

bitset<B> val[N][N], diff[N][N];

int main() {
	fast_cin();
	int n; cin >> n;
	vector<int> arr(n);
	int tot = 0;
	for (auto& i : arr) {
		cin >> i;
		tot += i;
	}
	sort(arr.begin(), arr.end());
	int mx = arr.back();
	if (mx == 0) {
		cout << "BitAryo\n";
	} else if (n == 1) {
		cout << "BitLGM\n";
	} else if (n == 2) {
		val[0][0][0] = 1;
		diff[0][0][0] = 1;
		for (int sum = 1; sum <= tot; ++sum) {
			for (int a = 0; a <= sum and a <= mx; ++a) {
				int b = sum - a;
				if (b < a or b > mx) {
					continue;
				}
				bitset<B> tmp = (val[0][a] | val[0][b] | diff[0][b - a]);
				int g = (~tmp)._Find_first();
				val[0][a][g] = 1;
				val[0][b][g] = 1;
				diff[0][b - a][g] = 1;
				if (a == arr[0] and b == arr[1]) {
					if (g) {
						cout << "BitLGM\n";
					} else {
						cout << "BitAryo\n";
					}
					return 0;
				}
			}
		}
	} else {
		val[0][0][0] = 1;
		diff[0][0][0] = 1;
		for (int sum = 1; sum <= tot; ++sum) {
			for (int a = 0; a <= sum and a <= mx; ++a) {
				for (int b = a; a + b <= sum and b <= mx; ++b) {
					int c = sum - a - b;
					if (c < b or c > mx) {
						continue;
					}
					bitset<B> tmp = (val[a][b] | val[b][c] | val[a][c] | diff[b - a][c - b]);
					int g = (~tmp)._Find_first();
					val[a][b][g] = 1;
					val[b][c][g] = 1;
					val[a][c][g] = 1;
					diff[b - a][c - b][g] = 1;
					if (a == arr[0] and b == arr[1] and c == arr[2]) {
						if (g) {
							cout << "BitLGM\n";
						} else {
							cout << "BitAryo\n";
						}
						return 0;
					}
				}
			}
		}
	}
}