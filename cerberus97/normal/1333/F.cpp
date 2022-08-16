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
	int n; cin >> n;
	vector<int> max_div(n + 1, 1), sum(n + 1, 0);
	for (int i = 1; i <= n; ++i) {
		++sum[max_div[i]];
		for (int j = i; j <= n; j += i) {
			max_div[j] = i;
		}
	}
	vector<int> ans(n + 1, n);
	int nxt = 1, cur = 0;
	for (int i = 1; i <= n; ++i) {
		cur += sum[i];
		while (nxt <= cur) {
			ans[nxt++] = i;
		}
	}
	for (int i = 2; i <= n; ++i) {
		cout << ans[i] << ' ';
	}
	cout << endl;
}