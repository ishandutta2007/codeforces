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

inline ll gcd(ll x, ll y);

int main() {
	fast_cin();
	int n; cin >> n;
	while (n--) {
		ll p, q, b;
		cin >> p >> q >> b;
		q /= gcd(p, q);
		ll temp = gcd(q, b);
		while (temp > 1) {
			if (q % temp == 0) {
				q /= temp;
			} else {
				temp = gcd(q, temp);
			}
		}
		if (q == 1) {
			cout << "Finite\n";
		} else {
			cout << "Infinite\n";
		}
	}
}

inline ll gcd(ll x, ll y) {
	if (!y) {
		return x;
	} else {
		return gcd(y, x % y);
	}
}