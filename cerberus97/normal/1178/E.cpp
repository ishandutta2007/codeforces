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
	int lo = 0, hi = n - 1;
	string t = "";
	while (hi - lo + 1 >= 4) {
		bool done = false;
		for (int i = lo; i <= lo + 1 and !done; ++i) {
			for (int j = hi; j >= hi - 1 and !done; --j) {
				if (s[i] == s[j]) {
					done = true;
					t += s[i];
					lo = i + 1;
					hi = j - 1;
				}
			}
		}
	}
	string rev = t;
	reverse(rev.begin(), rev.end());
	if (lo <= hi) {
		t += s[lo];
	}
	cout << t + rev << endl;
}