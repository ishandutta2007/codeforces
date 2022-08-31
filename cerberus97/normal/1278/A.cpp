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
	int t; cin >> t;
	while (t--) {
		string p, h;
		cin >> p >> h;
		sort(p.begin(), p.end());
		bool ok = false;
		for (int i = 0; i < h.size(); ++i) {
			string check = h.substr(i, p.size());
			sort(check.begin(), check.end());
			if (p == check) {
				ok = true;
				break;
			}
		}
		if (ok) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
}