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

const int N = 3e5 + 10;

int a[N], lo[N], hi[N];

int main() {
	fast_cin();
	int q; cin >> q;
	while (q--) {
		int n; cin >> n;
		for (int i = 1; i <= n; ++i) {
			lo[i] = n + 1;
			hi[i] = 0;
		}
		set<int> elems;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
			elems.insert(a[i]);
			lo[a[i]] = min(lo[a[i]], i);
			hi[a[i]] = i;
		}
		int cur = 0, best = 0;
		int pr = n + 1;
		for (auto &val : elems) {
			if (lo[val] > pr) {
				++cur;
			} else {
				cur = 1;
			}
			best = max(best, cur);
			pr = hi[val];
		}
		cout << elems.size() - best << '\n';
	}
}