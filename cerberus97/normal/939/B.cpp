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

int main() {
	ll n, k;
	cin >> n >> k;
	ll best = 0, best_t = 1, best_c = 0;
	for (int i = 1; i <= k; ++i) {
		ll a;
		cin >> a;
		ll temp = n - (n % a);
		if (temp > best) {
			best = temp;
			best_t = i;
			best_c = (n / a);
		}
	}
	cout << best_t << ' ' << best_c << endl;
}