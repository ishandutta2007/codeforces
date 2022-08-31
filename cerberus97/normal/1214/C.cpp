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
	string s; cin >> s;
	int delta = 0;
	for (auto &i : s) {
		delta += (i == '(' ? 1 : -1);
		if (delta < -1) {
			cout << "No\n";
			return 0;
		}
	}
	if (delta == 0) {
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}
}