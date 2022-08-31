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
	int n; string s;
	cin >> n >> s;
	int d1 = 0, d2 = 0;
	for (auto &i : s) {
		if (i == '(') {
			if (d1 <= d2) {
				++d1;
				cout << '0';
			} else {
				++d2;
				cout << '1';
			}
		} else {
			if (d1 <= d2) {
				--d2;
				cout << '1';
			} else {
				--d1;
				cout << '0';
			}
		}
	}
}