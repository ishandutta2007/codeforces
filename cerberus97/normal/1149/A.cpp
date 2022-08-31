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

const int N = 1e5 + 10;

int ctr[5];

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		int a; cin >> a;
		++ctr[a];
	}
	if (ctr[2]) {
		cout << 2 << ' ';
		--ctr[2];
	}
	if (ctr[1]) {
		cout << 1 << ' ';
		--ctr[1];
	}
	for (int i = 0; i < ctr[2]; ++i) {
		cout << 2 << ' ';
	}
	for (int i = 0; i < ctr[1]; ++i) {
		cout << 1 << ' ';
	}
	cout << endl;
}