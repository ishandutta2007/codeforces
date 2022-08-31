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
	int n; string s;
	cin >> n >> s;
	int best = n;
	for (int i = 1; 2 * i <= n; ++i) {
		if (s.substr(0, i) == s.substr(i, i)) {
			best = min(best, i + 1 + n - 2 * i);
		}
	}
	cout << best;
}