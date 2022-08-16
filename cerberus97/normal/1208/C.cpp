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

const int N = 1e3 + 10;

int a[N][N];

void solve(int n);

int main() {
	fast_cin();
	int n; cin >> n;
	solve(n);
}

void solve(int n) {
	int val = 0;
	for (int i = 0; i < n; i += 4) {
		for (int j = 0; j < n; j += 4) {
			for (int x = i; x < i + 4; ++x) {
				for (int y = j; y < j + 4; ++y) {
					a[x][y] = val++;
				}
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << a[i][j] << ' ';
		}
		cout << '\n';
	}
}