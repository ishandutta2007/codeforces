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
	fast_cin();
	int n;
	cin >> n;
	int ans = 0;
	set <char> s;
	for (char c = 'a'; c <= 'z'; ++c) {
		s.insert(c);
	}

	while (n--) {
		char t;
		cin >> t;
		if (t == '.') {
			string st;
			cin >> st;
			for (auto &i : st) {
				s.erase(i);
			}
		} else if (t == '!') {
			if (s.size() == 1) {
				++ans;
			}

			string st;
			cin >> st;
			bool seen[26] = {0};
			for (auto &i : st) {
				seen[i - 'a'] = true;
			}

			for (int i = 0; i < 26; ++i) {
				if (!seen[i]) {
					s.erase(i + 'a');
				}
			}
		} else {
			char c;
			cin >> c;
			if (s.size() == 1 and *s.begin() != c) {
				++ans;
			} else {
				s.erase(c);
			}
		}
	}

	cout << ans;
}