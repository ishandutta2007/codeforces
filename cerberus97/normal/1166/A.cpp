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

const int N = 1e5 + 10, C = 30;

int ctr[C];

int c2(int x);

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 0; i < n; ++i) {
		string s; cin >> s;
		++ctr[s[0] - 'a'];
	}
	int ans = 0;
	for (int i = 0; i < C; ++i) {
		int x = ctr[i] / 2, y = ctr[i] - x;
		ans += c2(x) + c2(y);
	}
	cout << ans << endl;
}

int c2(int x) {
	return (x * (x - 1)) / 2;
}