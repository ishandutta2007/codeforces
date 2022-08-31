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

vector <int> g[N];
bool visited[N], seen[N][2];
int back[N][2], color[N];

void solve(int i, bool p, int prev);
bool has_cycle(int s);

int main() {
	fast_cin();
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		int c; cin >> c;
		while (c--) {
			int j; cin >> j;
			g[i].pb(j);
		}
	}
	int s; cin >> s;
	solve(s, 0, -1);
	bool is_cycle = has_cycle(s);
	for (int i = 1; i <= n; ++i) {
		if (g[i].empty() and seen[i][1]) { // win
			cout << "Win\n";
			stack <int> st;
			int u = i; bool p = 1;
			while (u != -1) {
				st.push(u);
				u = back[u][p];
				p = !p;
			}
			while (!st.empty()) {
				cout << st.top() << ' ';
				st.pop();
			}
			return 0;
		}
	}
	if (is_cycle) {
		cout << "Draw";
	} else {
		cout << "Lose";
	}
}

void solve(int i, bool p, int prev) {
	seen[i][p] = true;
	back[i][p] = prev;
	p = !p;
	for (auto &u : g[i]) {
		if (!seen[u][p]) {
			solve(u, p, i);
		}
	}
}

bool has_cycle(int s) {
	color[s] = 1;
	bool ans = false;
	for (auto &i : g[s]) {
		if (color[i] == 1) {
			return true;
		} else if (color[i] == 0) {
			ans = ans or has_cycle(i);
		}
	}
	color[s] = 2;
	return ans;
}