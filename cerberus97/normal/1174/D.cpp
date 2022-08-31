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

const int N = (1 << 18) + 10;

int a[N];
bool seen[N];

int main() {
	fast_cin();
	int n, x;
	cin >> n >> x;
	seen[0] = seen[x] = true;
	int len = 0, pref_xor = 0;
	for (int i = 0; i < (1 << n); ++i) {
		if (seen[i]) {
			continue;
		}
		a[++len] = pref_xor ^ i;
		pref_xor = i;
		seen[i] = true;
		seen[i ^ x] = true;
	}
	cout << len << '\n';
	for (int i = 1; i <= len; ++i) {
		cout << a[i] << ' ';
	}
}