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
	int q; cin >> q;
	while (q--) {
		string s, t, p;
		cin >> s >> t >> p;
		vector<int> ctr(26, 0);
		for (auto &i : s) {
			ctr[i - 'a']++;
		}
		for (auto &i : t) {
			ctr[i - 'a']--;
		}
		for (auto &i : p) {
			ctr[i - 'a']++;
		}
		bool ans = true;
		for (auto &i : ctr) {
			if (i < 0) {
				ans = false;
				break;
			}
		}
		int pos = 0, sz = t.size();
		for (auto &c : s) {
			while (pos < sz and t[pos] != c) {
				++pos;
			}
			if (pos == sz) {
				ans = false;
				break;
			} else {
				++pos;
			}
		}
		if (ans) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
}