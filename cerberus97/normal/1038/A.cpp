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

int ctr[30];

int main() {
	fast_cin();
	int n, k;
	cin >> n >> k;
	string s; cin >> s;
	for (auto &i : s) {
		++ctr[i - 'A'];
	}
	int ans = n;
	for (int i = 0; i < k; ++i) {
		ans = min(ans, ctr[i]);
	}
	cout << ans * k << endl;
}