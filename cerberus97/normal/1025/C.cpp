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
	string s; cin >> s;
	int n = s.length();
	int best = 1, cur = 1;
	for (int i = 1; i < n; ++i) {
		if (s[i] != s[i - 1]) {
			++cur;
			best = max(best, cur);
		} else {
			cur = 1;
		}
	}
	if (s[0] != s[n - 1]) {
		int pref = 0, suff = 0;
		for (int i = 1; i < n; ++i) {
			if (s[i] == s[i - 1]) {
				pref = i;
				break;
			}
		}
		reverse(s.begin(), s.end());
		for (int i = 1; i < n; ++i) {
			if (s[i] == s[i - 1]) {
				suff = i;
				break;
			}
		}
		if (pref + suff <= n) {
			best = max(best, pref + suff);
		}
	}
	cout << best << endl;
}