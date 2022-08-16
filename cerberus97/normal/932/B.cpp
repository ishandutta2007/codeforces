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

const int N = 1e5 + 10, M = 1e6 + 100;

ll g[M];
ll ctr[M][10];

ll get_g(int n);
ll f(int n);

int main() {
	fast_cin();
	for (int i = 1; i < M; ++i) {
		g[i] = get_g(i);
		for (int j = 0; j <= 9; ++j) {
			ctr[i][j] = ctr[i - 1][j];
		}
		ctr[i][g[i]]++;
	}

	int q;
	cin >> q;
	while (q--) {
		int l, r, k;
		cin >> l >> r >> k;
		cout << ctr[r][k] - ctr[l - 1][k] << endl;
	}
}

ll get_g(int n) {
	if (n < 10) {
		return n;
	} else {
		return get_g(f(n));
	}
}

ll f(int n) {
	ll ans = 1;
	while (n) {
		int temp = n % 10;
		n /= 10;
		if (temp) {
			ans *= temp;
		}
	}
	return ans;
}