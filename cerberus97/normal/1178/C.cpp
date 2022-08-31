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

const int N = 1e5 + 10, mod = 998244353;

ll p2[N];

int main() {
	fast_cin();
	int w, h;
	cin >> w >> h;
	p2[0] = 1;
	for (int i = 1; i <= w + h; ++i) {
		p2[i] = (2 * p2[i - 1]) % mod;
	}
	cout << p2[w + h] << endl;
}