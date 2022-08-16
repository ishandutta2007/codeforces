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
#define a first
#define b second

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 7e3 + 10;

pll s[N];
bool pick[N];

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> s[i].a;
	}
	for (int i = 1; i <= n; ++i) {
		cin >> s[i].b;
	}
	sort(s + 1, s + 1 + n);
	ll cnt = 0, sum = 0;
	for (int i = n; i >= 1; --i) {
		if (i > 1 and s[i - 1].a == s[i].a) {
			pick[i] = true;
		} else {
			for (int j = i + 1; j <= n; ++j) {
				if (pick[j] and (s[i].a & s[j].a) == s[i].a) {
					pick[i] = true;
					break;
				}
			}
		}
		if (pick[i]) {
			sum += s[i].b;
			++cnt;
		}
	}
	if (cnt >= 2) {
		cout << sum << endl;
	} else {
		cout << 0 << endl;
	}
}