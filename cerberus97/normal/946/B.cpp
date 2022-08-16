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

void solve(ll a, ll b);

int main() {
	ll a, b;
	cin >> a >> b;
	solve(a, b);
}

void solve(ll a, ll b) {
	// cout << a << ' ' << b << endl;
	if (!a or !b) {
		cout << a << ' ' << b;
	} else if (a >= 2 * b) {
		ll k = (a) / (2 * b);
		a -= k * 2 * b;
		solve(a, b);
	} else if (b >= 2 * a) {
		ll k = (b) / (2 * a);
		b -= k * 2 * a;
		solve(a, b);
	} else {
		cout << a << ' ' << b;
	}
}