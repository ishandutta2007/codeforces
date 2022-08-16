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
#include <numeric>

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
	int n, m;
	cin >> n >> m;
	multiset<string> all;
	int ans = 0;
	string h1, h2;
	for (int i = 1; i <= n; ++i) {
		string s; cin >> s;
		string t = string(s.rbegin(), s.rend());
		if (all.find(t) != all.end()) {
			h2 += s;
			h1 = t + h1;
			all.erase(all.find(t));
			ans += 2;
		} else {
			all.insert(s);
		}
	}
	for (auto& s : all) {
		string t = string(s.rbegin(), s.rend());
		if (s == t) {
			h1 += s;
			++ans;
			break;
		}
	}
	cout << ans * m << endl;
	cout << h1 + h2 << endl;
}