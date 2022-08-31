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

const int N = 70, SHUFFLE_COUNT = 0;

void make_graph();
string id_to_s(int i);
int s_to_id(string s);
int bfs(int s);

vector<int> g[N];
bool have[N], bak_have[N];
int dist[N], back[N];

int main() {
	fast_cin();
	srand(time(0));
	make_graph();
	bool invert = false;

	// int k = 63;
	// for (int i = 0; i < 64; ++i) {
	// 	have[i] = true;
	// }
	// have[62] = false;

	int k; cin >> k;
	for (int i = 1; i <= k; ++i) {
		string s; cin >> s;
		have[s_to_id(s)] = true;
	}

	if (k >= 32) {
		invert = true;
		for (int i = 0; i < 64; ++i) {
			have[i] = !have[i];
		}
		for (int i = 0; i < 63 - i; ++i) {
			swap(have[i], have[63 - i]);
		}
		k = 64 - k;
	}

	for (int i = 0; i < 64; ++i) {
		bak_have[i] = have[i];
	}

	int tries = 0;
	while (true) {
		++tries;
		vector<pii> ans;
		for (int i = 0; i < 64; ++i) {
			have[i] = bak_have[i];
		}
		for (int i = 0; i < SHUFFLE_COUNT; ++i) {
			bool done = false;
			while (!done) {
				int u = rand() % 64;
				if (!have[u]) {
					continue;
				}
				int v = g[u][rand() % g[u].size()];
				if (!have[v]) {
					swap(have[u], have[v]);
					ans.pb({u, v});
					done = true;
				}
			}
		}
		bool ok = true;
		for (int i = 0; i < k; ++i) {
			if (have[i]) {
				continue;
			}
			int t = bfs(i);
			if (t == -1) {
				ok = false;
				break;
			}
			have[t] = false;
			have[i] = true;
			while (dist[t]) {
				ans.pb({t, back[t]});
				t = back[t];
			}
		}
		if (tries % 1000 == 0) {
			cout << tries / 1000 << endl;
		}
		if (ans.size() > 1500) {
			ok = false;
		}
		if (!ok) {
			continue;
		}
		cout << ans.size() << endl;
		for (auto &i : ans) {
			if (invert) {
				swap(i.first, i.second);
				i.first = 63 - i.first;
				i.second = 63 - i.second;
			}
			cout << id_to_s(i.first) << '-' << id_to_s(i.second) << '\n';
		}
		break;
	}
}

void make_graph() {
	for (int i = 0; i < 64; ++i) {
		for (int j = 0; j < 64; ++j) {
			string s1 = id_to_s(i);
			string s2 = id_to_s(j);
			if (abs(s1[0] - s2[0]) == 2 and abs(s1[1] - s2[1]) == 1) {
				g[i].pb(j);
			}
			if (abs(s1[0] - s2[0]) == 1 and abs(s1[1] - s2[1]) == 2) {
				g[i].pb(j);
			}
		}
	}
}

string id_to_s(int i) {
	string s = "  ";
	s[0] = char((i % 8) + 'a');
	s[1] = char((i / 8) + '1');
	return s;
}

int s_to_id(string s) {
	return (s[0] - 'a') + 8 * (s[1] - '1');
}

int bfs(int s) {
	for (int i = 0; i < 64; ++i) {
		dist[i] = 100;
	}
	dist[s] = 0;
	queue<int> q;
	q.push(s);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		if (u != s and have[u]) {
			return u;
		}
		for (auto &v : g[u]) {
			if (v < s or dist[v] <= dist[u] + 1) {
				continue;
			} else {
				dist[v] = dist[u] + 1;
				back[v] = u;
				q.push(v);
			}
		}
	}
	return -1;
}