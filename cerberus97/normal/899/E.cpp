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

const int N = 2e5 + 10;

int a[N], len[N];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}

	int st = 1;
	set <pii, greater <pii>> s;
	set <int> start;
	for (int i = 2; i <= n; ++i) {
		if (a[i] != a[i - 1]) {
			start.insert(st);
			len[st] = i - st;
			s.insert({len[st], -st});
			st = i;
		}
	}

	start.insert(st);
	len[st] = n - st + 1;
	s.insert({len[st], -st});

	int ans = 0;
	while (!s.empty()) {
		auto cur = s.begin();
		st = -(cur -> second);
		s.erase(s.begin());
		if (start.find(st) == start.end()) {
			continue;
		}

		start.erase(st);
		++ans;
		if (!start.empty()) {
			auto p = start.lower_bound(st);
			if (p != start.begin() and p != start.end()) {
				int rt = *p;
				--p;
				int lt = *p;
				if (a[lt] == a[rt]) {
					len[lt] += len[rt];
					s.insert({len[lt], -lt});
					start.erase(rt);
				}
			}
		}
	}

	cout << ans << endl;
}