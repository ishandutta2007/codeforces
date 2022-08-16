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
	int n = s.length();
	int ctr = 0, pref = 0;
	for (int i = 0; i <= n; ++i) {
		if (i - ctr <= n - i) {
			pref = i;
		}
		if (i < n and s[i] == 'a') {
			++ctr;
		}
	}
	string t = s.substr(0, pref), cpy = "";
	for (auto &i : t) {
		if (i != 'a') {
			cpy += i;
		}
	}
	if (t + cpy == s) {
		cout << t << endl;
	} else {
		cout << ":(" << endl;
	}
}