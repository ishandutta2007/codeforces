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

const int N = 1e5 + 10, P = 110;
const ll inf = 1e15 + 42;

struct Line {
	ll m, c;
};

ll d[N], t[N], h[N], dp[N];

void add_line(deque<Line> &cht, Line l);
ll query(deque<Line> &cht, ll x);
ll eval(Line l, ll x);

int main() {
	fast_cin();
	int n, m, p;
	cin >> n >> m >> p;
	for (int i = 2; i <= n; ++i) {
		cin >> d[i];
		d[i] += d[i - 1];
	}
	ll sum = 0;
	for (int i = 1; i <= m; ++i) {
		cin >> h[i] >> t[i];
		t[i] -= d[h[i]];
		sum += t[i];
	}
	sort(t + 1, t + 1 + m);
	for (int i = 1; i <= m; ++i) {
		dp[i] = inf;
	}
	for (int j = 1; j <= p; ++j) {
		deque<Line> cht;
		add_line(cht, {0, dp[0]});
		for (int i = 1; i <= m; ++i) {
			ll temp = i * t[i] + query(cht, t[i]);
			add_line(cht, {-i, dp[i]});
			dp[i] = temp;
		}
	}
	cout << dp[m] - sum << '\n';
}

void add_line(deque<Line> &cht, Line l) {
	while (cht.size() >= 2) {
		Line l1 = cht[cht.size() - 1];
		Line l2 = cht[cht.size() - 2];
		if ((l.c - l2.c) * (l2.m - l1.m) <= (l1.c - l2.c) * (l2.m - l.m)) {
			cht.pop_back();
		} else {
			break;
		}
	}
	cht.pb(l);
}

ll query(deque<Line> &cht, ll x) {
	while (cht.size() >= 2) {
		if (eval(cht[1], x) <= eval(cht[0], x)) {
			cht.pop_front();
		} else {
			break;
		}
	}
	return eval(cht[0], x);
}

ll eval(Line l, ll x) {
	return l.m * x + l.c;
}