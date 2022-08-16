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

ll m[N], l[N], r[N];

int main() {
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> m[i];
	}
	ll ans = 0, d = 0;
	stack<int> choices;
	for (int i = 2; i <= n; ++i) {
		d += m[i - 1] - m[i];
		choices.push(i);
		ans += d;
		while (d < 0) {
			ans += i - choices.top() + 1;
			choices.pop();
			++d;
		}
	}
	cout << ans;
}