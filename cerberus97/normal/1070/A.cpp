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

const int D = 510, S = 5010, inf = 1e9;

int dist[D][S];
pii back[D][S];

int main() {
	fast_cin();
	int d, sum;
	cin >> d >> sum;
	for (int m = 0; m < d; ++m) {
		for (int s = 0; s <= sum; ++s) {
			dist[m][s] = inf;
		}
	}
	dist[0][0] = 0;
	queue<pii> q;
	q.push({0, 0});
	while (!q.empty()) {
		int m, s;
		tie(m, s) = q.front();
		q.pop();
		for (int digit = 0; digit < 10 and s + digit <= sum; ++digit) {
			int new_m = ((10 * m) + digit) % d;
			int new_s = s + digit;
			if (dist[m][s] + 1 < dist[new_m][new_s]) {
				dist[new_m][new_s] = dist[m][s] + 1;
				back[new_m][new_s] = {m, s};
				q.push({new_m, new_s});
			}
		}
	}
	int m = 0, s = sum;
	if (dist[m][s] == inf) {
		cout << -1;
	} else {
		string ans = "";
		while (m != 0 or s != 0) {
			ans += (s - back[m][s].second) + '0';
			tie(m, s) = back[m][s];
		}
		reverse(ans.begin(), ans.end());
		cout << ans << endl;
	}
}