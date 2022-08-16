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

struct song_t {
	int t, b;
	bool operator<(const song_t &o) const {
		return b > o.b;
	}
};

song_t a[N];

int main() {
	fast_cin();
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i].t >> a[i].b;
	}
	sort(a + 1, a + 1 + n);
	ll sum = 0, best = 0;
	priority_queue<int, vector<int>, greater<int>> q;
	for (int i = 1; i <= n; ++i) {
		if ((int)q.size() < k) {
			q.push(a[i].t);
			sum += a[i].t;
		} else if (q.top() < a[i].t) {
			sum += a[i].t - q.top();
			q.pop();
			q.push(a[i].t);
		}
		best = max(best, sum * a[i].b);
	}
	cout << best << endl;
}