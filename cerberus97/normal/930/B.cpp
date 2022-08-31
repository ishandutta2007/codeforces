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
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 10, K = 30;

int ctr[K];

int main() {
	string s; cin >> s;
	int n = s.length();
	s += s;
	ld num = 0, den = n;
	for (char c = 'a'; c <= 'z'; ++c) {
		vector<int> pos;
		memset(ctr, 0, sizeof(ctr));
		ld best = 0, unq = 0;
		for (int i = 0; i < n; ++i) {
			if (s[i] == c) {
				pos.pb(i);
				ctr[s[i] - 'a']++;
				if (ctr[s[i] - 'a'] == 1) {
					++unq;
				} else if (ctr[s[i] - 'a'] == 2) {
					--unq;
				}
			}
		}
		ld m = pos.size();
		if (pos.empty()) {
			continue;
		}
		// cout << "here" << endl;
		for (int i = 0; i < n; ++i) {
			for (auto &j : pos) {
				--ctr[s[j] - 'a'];
				if (ctr[s[j] - 'a'] == 1) {
					++unq;
				} else if (ctr[s[j] - 'a'] == 0) {
					--unq;
				}
				++j;
				++ctr[s[j] - 'a'];
				if (ctr[s[j] - 'a'] == 1) {
					++unq;
				} else if (ctr[s[j] - 'a'] == 2) {
					--unq;
				}
			}
			best = max(best, unq / m);
		}
		// cout << c << ' ' << best << endl;
		num += m * best;
	}
	cout << fixed << setprecision(10) << num / den;
}