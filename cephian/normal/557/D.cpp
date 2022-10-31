#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

typedef long long ll;

int n, m;
vector<vector<int> > G;
bool odd_cyc = false;
bool visit[100000];
int col[100000];

ll co[2];

int color(int v, int c) {
	if (visit[v]) {
		odd_cyc = odd_cyc | (c != col[v]);
		return 0;
	}
//	printf("visiting %d\n", v + 1);
	visit[v] = true;
	++co[c];
	col[v] = c;
	int sz = 1;
	for (int i = 0; i < G[v].size(); ++i) {
		sz += color(G[v][i], 1 - c);
	}
	return sz;
}

ll ch3(ll n) {
	return (n * (n - 1) * (n - 2)) / (6);
}

ll ch2(ll n) {
	return (n * (n - 1)) / 2;
}

int main() {
	ios::sync_with_stdio(0);

	scanf("%d %d", &n, &m);

	if (m == 0) {
		printf("3 %I64d\n", ch3(n));
		return 0;
	}

	for (int i = 0; i < n; ++i)
		G.push_back(vector<int>());
	for (int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		--a;
		--b;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	fill(visit, visit + n, 0);
	int mx_sz = 0;
	int cyc_2 = 0;
	int cyc_tot = 0;

	ll ans_gen = 0;

	for (int i = 0; i < n; ++i) {
		if (!visit[i]) {
			odd_cyc = false;
			co[0] = co[1] = 0;
			int sz = color(i, 1);

//			printf("%I64d %I64d\n", co[0], co[1]);

			if (odd_cyc) {
				printf("0 1\n");
				return 0;
			}

			ans_gen += ch2(co[0]) + ch2(co[1]);

			mx_sz = max(sz, mx_sz);
			if (sz == 2)
				++cyc_2;
			++cyc_tot;

		}
	}
	if (mx_sz == 2) {
		printf("2 %I64d\n", ((ll) cyc_2) * (n - 2));
		return 0;
	}

	printf("1 %I64d\n", ans_gen);

	return 0;
}