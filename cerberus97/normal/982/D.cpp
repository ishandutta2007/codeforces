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

const int N = 1e5 + 10, inf = 1e9 + 10;

int a[N], lt[N], rt[N], rev[N];
map<int, int> mp;

int main() {
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		mp[a[i]];
	}
	int nxt = 1;
	for (auto &i : mp) {
		i.second = nxt;
		rev[nxt++] = i.first;
	}
	for (int i = 1; i <= n; ++i) {
		a[i] = mp[a[i]];
	}
	stack<pii> stk;
	stk.push({inf, 0});
	for (int i = 1; i <= n; ++i) {
		while (stk.top().first < a[i]) {
			stk.pop();
		}
		lt[a[i]] = (i - stk.top().second - 1);
		stk.push({a[i], i});
	}
	while (!stk.empty()) {
		stk.pop();
	}
	stk.push({inf, n + 1});
	for (int i = n; i >= 1; --i) {
		while (stk.top().first < a[i]) {
			stk.pop();
		}
		rt[a[i]] = (stk.top().second - i - 1);
		stk.push({a[i], i});
	}
	multiset<int> segments;
	int max_seg = 0, ans = 1;
	for (int k = 2; k <= n + 1; ++k) {
		if (lt[k - 1]) {
			segments.erase(segments.find(lt[k - 1]));
		}
		if (rt[k - 1]) {
			segments.erase(segments.find(rt[k - 1]));
		}
		segments.insert(lt[k - 1] + rt[k - 1] + 1);
		if (*segments.begin() == *segments.rbegin() and segments.size() > max_seg) {
			max_seg = segments.size();
			ans = rev[k - 1] + 1;
		}
	}
	cout << ans;
}