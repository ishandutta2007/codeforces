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
	int n; cin >> n;
	while (n--) {
		string s; cin >> s;
		bool has_zero = false;
		int sum = 0, cnt_even = 0;
		for (auto &c : s) {
			has_zero |= (c == '0');
			sum += (c - '0');
			cnt_even += ((c - '0') % 2 == 0);
		}
		if (has_zero and sum % 3 == 0 and cnt_even >= 2) {
			cout << "red\n";
		} else {
			cout << "cyan\n";
		}
	}
}