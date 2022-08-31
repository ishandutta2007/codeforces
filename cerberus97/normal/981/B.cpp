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

map<int, int> mp;

int main() {
	fast_cin();
	int n; cin >> n;
	ll sum = 0;
	int a, x;
	for (int i = 1; i <= n; ++i) {
		cin >> a >> x;
		mp[a] = x;
		sum += x;
	}
	int m; cin >> m;
	for (int i = 1; i <= m; ++i) {
		cin >> a >> x;
		if (x > mp[a]) {
			sum += x - mp[a];
		}
	}
	cout << sum;
}