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

int main() {
	fast_cin();
	int b, k;
	cin >> b >> k;
	ll num = 0;
	for (int i = 1; i <= k; ++i) {
		ll a; cin >> a;
		num = (num * b) + a;
		num %= 2;
	}
	if (num % 2) {
		cout << "odd\n";
	} else {
		cout << "even\n";
	}
}