#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

const int N = 1e5 + 7;
const int LOG = 18;
const int INF = 1e9;

int father[N][LOG];
int tag = 0;
int n, dfs_order[N], out[N], total, depth[N];
vector<int> e[N];

void dfs(int x, int fa) {
	father[x][0] = fa;
	dfs_order[x] = ++total;
	depth[x] = depth[fa] + 1;
	for (int i = 0; i < (int)e[x].size(); i++) {
		int y = e[x][i];
		if (y == fa) {
			continue;
		} else {
			dfs(y, x);
		}
	}
	out[x] = total;
}

int find(int a, int b) {
	if (depth[b] > depth[a]) {
		swap(a, b);
	}
	for (int i = LOG - 1; i >= 0; i--) {
		if (depth[a] - (1 << i) >= depth[b]) {
			a = father[a][i];
		}
	}
	if (a == b) {
		return a;
	}
	for (int i = LOG - 1; i >= 0; i--) {
		if (father[a][i] != father[b][i]) {
			a = father[a][i];
			b = father[b][i];
		}
	}
	return father[a][0];
}

vector<int> cities;

bool cmp(int a, int b) {
	return dfs_order[a] < dfs_order[b];
}

vector<int> sons[N];
vector<int> vers;
int important[N], answer, visit[N];

int go(int x) {
	//cout << "go " << x << endl;
	int cnt = (important[x] == tag);
	for (int i = 0; i < sons[x].size(); i++) {
		int y = sons[x][i];
		if (go(y)) {
			if (important[x] == tag) {
				if (depth[y] - depth[x] == 1 && important[y] == tag) {
					//cout << x << " " << y << endl;
					answer = INF;
					return 0;
				} else {
					answer++;
				}
			} else {
				cnt++;
			}
		}
	}
	//cout << "x = " << x << " cnt = " << cnt << endl;
	if (cnt > 1) {
		answer++;
		cnt = 0;
	}
	if (important[x] == tag || cnt) {
		return 1;
	} else {
		return 0;
	}
}

int solve(vector<int> cities) {
	++tag;
	for (int i = 0; i < (int)cities.size(); i++) {
		important[cities[i]] = tag;
		//cout << "city #" << i << ": " << cities[i] << endl;
	}

	sort(cities.begin(), cities.end(), cmp);
	{
		int n = (int)cities.size();
		for (int i = 0; i + 1 < n; i++) {
			cities.push_back(find(cities[i], cities[i + 1]));
		}
		sort(cities.begin(), cities.end(),cmp);
	}

	static vector<int> stack;
	stack.clear();
	vers.clear();

	stack.push_back(cities[0]);
	sons[cities[0]].clear();
	for (int i = 1; i < (int)cities.size(); i++) {
		int x = cities[i], pre = -1;
		while (stack.size() && out[stack.back()] < dfs_order[x]) {
			stack.pop_back();
		}
		sons[stack.back()].push_back(x);
		sons[x].clear();
		stack.push_back(x);
	}
	answer = 0;
	go(stack[0]);
	return answer >= INF / 2 ? -1 : answer;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		e[a].push_back(b);
		e[b].push_back(a);
	}
	dfs(1, 0);
	for (int j = 0; j + 1 < LOG; j++) {
		for (int i = 1; i <= n; i++) {
			father[i][j + 1] = father[father[i][j]][j];
		}
	}
	int q; scanf("%d", &q);
	while (q--) {
		cities.clear();
		int k; scanf("%d", &k);
		for (int j = 1; j <= k; j++) {
			int x;
			scanf("%d", &x);
			cities.push_back(x);
		}
		printf("%d\n", solve(cities));
	}
	return 0;
}