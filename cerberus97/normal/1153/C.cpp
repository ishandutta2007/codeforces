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
	int del = 0, blank = 0;
	for (auto &i : s) {
		if (i == '(') {
			++del;
		} else if (i == ')') {
			--del;
		} else {
			++blank;
		}
	}
	if (abs(n) % 2 == 1) {
		cout << ":(" << endl;
		return 0;
	}
	int op = (blank - del) / 2;
	int cl = (blank + del) / 2;
	if (op < 0 or cl < 0) {
		cout << ":(" << endl;
		return 0;
	}
	del = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '(') {
			++del;
		} else if (s[i] == ')') {
			--del;
		} else {
			if (op) {
				s[i] = '(';
				--op;
				++del;
			} else {
				s[i] = ')';
				--cl;
				--del;
			}
		}
		if (del < 0 or (i < n - 1 and del == 0)) {
			cout << ":(" << endl;
			return 0;
		}
	}
	cout << s << endl;
}