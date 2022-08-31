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

const int N = 1e5 + 10;

vector <int> g[N];
bool seen[N], type[N];
int t[N];

int solve(int cur);

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> type[i];
	}

	while (m--) {
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
	}

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		ans = max(ans, solve(i));
	}

	cout << ans << endl;
}

int solve(int cur) {
	if (seen[cur]) {
		return t[cur];
	}

	seen[cur] = true;
	t[cur]    = type[cur];
	for (auto &i : g[cur]) {
		if (type[cur] == 1 and type[i] == 0) {
			t[cur] = max(t[cur], solve(i) + 1);
		} else {
			t[cur] = max(t[cur], solve(i));
		}
	}

	return t[cur];
}