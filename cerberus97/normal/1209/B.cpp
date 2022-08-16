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

const int N = 1e2 + 10, M = 500;

int ctr[M];

int main() {
	fast_cin();
	int n; string s;
	cin >> n >> s;
	for (int i = 0; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		int cur = (s[i] == '1');
		for (int j = 0; j < M; ++j) {
			if (j >= b and j % a == b % a) {
				cur = 1 - cur;
			}
			ctr[j] += cur;
		}
	}
	int ans = 0;
	for (int i = 0; i < M; ++i) {
		ans = max(ans, ctr[i]);
	}
	cout << ans << endl;
}