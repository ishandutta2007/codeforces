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
	string s, t;
	cin >> s >> t;
	if (s.length() != t.length()) {
		cout << "No\n";
		return 0;
	}
	set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
	int n = s.length();
	for (int i = 0; i < n; ++i) {
		if (vowels.count(s[i]) != vowels.count(t[i])) {
			cout << "No\n";
			return 0;
		}
	}
	cout << "Yes\n";
	return 0;
}