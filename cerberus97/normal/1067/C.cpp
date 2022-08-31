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

const int N = 1e3 + 10, D = 4;

int dx[D] = {0, -1, 0, 1};
int dy[D] = {-1, 0, 1, 0};

int main() {
	fast_cin();
	int n; cin >> n;
	vector<pii> ans = {{0, 0}};
	--n;
	for (int i = 1; i < N and n; ++i) {
		for (int d = 0; d < 4 and n; ++d) {
			ans.pb({i * dx[d], i * dy[d]});
			--n;
		}
	}
	for (auto &p : ans) {
		cout << p.first << ' ' << p.second << '\n';
	}
}