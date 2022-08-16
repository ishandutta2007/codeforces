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

bool win(int n, int k);

int main() {
	fast_cin();
	int t; cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		if (win(n, k)) {
			cout << "Alice\n";
		} else {
			cout << "Bob\n";
		}
	}
}

bool win(int n, int k) {
	if (n < k or k % 3 != 0) {
		return (n % 3) != 0;
	} else {
		n %= (k + 1);
		return (n == k or n % 3 != 0);
	}
}