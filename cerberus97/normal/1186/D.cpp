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

int b[N];
bool inc[N];

int main() {
	fast_cin();
	int n; cin >> n;
	ll sum = 0;
	for (int i = 1; i <= n; ++i) {
		string s; cin >> s;
		int p = s.find('.');
		b[i] = stoi(s.substr(0, p));
		if (stoi(s.substr(p + 1, 5)) != 0) {
			inc[i] = true;
		}
		if (s[0] == '-' and inc[i]) {
			--b[i];
		}
		sum += b[i];
	}
	for (int i = 1; i <= n; ++i) {
		if (sum < 0 and inc[i]) {
			++b[i]; ++sum;
		}
		cout << b[i] << '\n';
	}
}