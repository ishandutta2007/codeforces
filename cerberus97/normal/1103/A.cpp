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
	string s; cin >> s;
	int v = 0, h = 0;
	for (auto &i : s) {
		if (i == '0') {
			if (!v) {
				cout << "1 1\n";
			} else {
				cout << "3 1\n";
			}
			v = 1 - v;
		} else {
			if (!h) {
				cout << "4 3\n";
			} else {
				cout << "4 1\n";
			}
			h = 1 - h;
		}
	}
}