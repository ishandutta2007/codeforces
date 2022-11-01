 #include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cassert>
#include <iostream>
using namespace std;

const int N = 111111, K = 55 * 2;
const int MOD = 1000000007;

vector<pair<pair<int, int>, int> > linked;
int n, k;
int exist[2][N], f[N], g[N], dp[2 << 20], tree[K * 2][K * 2][2];
vector<int> nodes[2], total;
int size[N << 1], pre[N];
vector<pair<pair<int, int>, int> > edges;
int father[N << 1], deleted[N << 1], from[N << 1];
vector<pair<int, int> > e[N << 1];

__inline void add(int &a, int b) {
	if ((a += b) >= MOD) {
		a -= MOD;
	}
	if (a < 0) {
		a += MOD;
	}
}

void dfs(int dir, int id) {
	if (exist[dir][id] != 1) {
		return;
	}
	nodes[dir].push_back(id);
	exist[dir][id] = 2;
	for(int i = 0; i < (int)linked.size(); i++) {
		if (dir == 0 && linked[i].first.first == id) {
			edges.push_back(linked[i]);
			dfs(dir ^ 1, linked[i].first.second);
		} else if (dir == 1 && linked[i].first.second == id) {
			edges.push_back(linked[i]);
			dfs(dir ^ 1, linked[i].first.first);
		}
	}
}

int treeDP(int x, int from) {
	int real = lower_bound(total.begin(), total.end(), x) - total.begin();
	memset(tree[real], 0, sizeof(tree[real]));
	tree[real][0][0] = 1;
	size[real] = 1;
	deleted[x] = true;
	for(int i = 0; i < (int)e[x].size(); i++) {
		int y = e[x][i].first;
		if (y == from || deleted[y]) {
			continue;
		}
		y = treeDP(y, x);
		for(int w = size[real]; w >= 0; w--)
			for(int s = 1; s >= 0; s--) {
				int temp = tree[real][w][s];
				tree[real][w][s] = 0;
				for(int ww = size[y]; ww >= 0; ww--)
					for(int ss = 1; ss >= 0; ss--) {
						add(tree[real][w + ww][s], 1LL * temp * tree[y][ww][ss] % MOD);
						if (s == 0 && ss == 0) {
							add(tree[real][w + ww + 1][1], 1LL * temp * tree[y][ww][ss] % MOD * e[x][i].second % MOD);
						}
					}
			}
		size[real] += size[y];
	}
	
	return real;
}

void combine(int f[], int g[]) {
	for(int i = 53; i >= 0; i--) {
		if (f[i] == 0) {
			continue;
		}
		int temp = f[i];
		f[i] = 0;
		for(int j = 53 - i; j >= 0; j--) {
			add(f[i + j], 1LL * temp * g[j] % MOD);
		}
	}
}

int getFather(int x) {
	return father[x] == x ? x : father[x] = getFather(father[x]);
}

void debug(vector<int> nodes) {
	for(int i = 0; i < (int)nodes.size(); i++) {
		printf("%d ", nodes[i]);
	}
	printf("\n");
}

void solve() {
	sort(edges.begin(), edges.end());
	edges.erase(unique(edges.begin(), edges.end()), edges.end());
	sort(nodes[0].begin(), nodes[0].end());
	sort(nodes[1].begin(), nodes[1].end());
	//debug(nodes[0]);
	//debug(nodes[1]);
	memset(g, 0, sizeof(g));
	int tot = edges.size();
	/*printf("!!! %d\n", tot);
	for(int i = 0; i < tot; i++) {
		printf("%d %d %d\n", edges[i].first.first, edges[i].first.second, edges[i].second);
	}*/
	if (min(nodes[0].size(), nodes[1].size()) <= tot / 3 + 1) {
		//cout << "type 1" << endl;
		if (nodes[0].size() < nodes[1].size()) {
			swap(nodes[0],  nodes[1]);
			for(int i = 0; i < tot; i++) {
				swap(edges[i].first.first, edges[i].first.second);
			}
		}
		int nn = nodes[1].size();
		for(int i = 0; i < (1 << nn); i++) {
			dp[i] = 0;
		}
		dp[0] = 1;
		for(int i = 0; i < (int)nodes[0].size(); i++) {
			int x = nodes[0][i];
			vector<pair<int, int> > ee;
			for(int j = 0; j < tot; j++) {
				if (edges[j].first.first == x) {
					int it = lower_bound(nodes[1].begin(), nodes[1].end(), edges[j].first.second) - nodes[1].begin();
					ee.push_back(make_pair(it, edges[j].second));
				}
			}
			for(int j = (1 << nn) - 1; j >= 0; j--) {
				for(int k = 0; k < (int)ee.size(); k++) {
					int y = ee[k].first;
					if (j >> y & 1) {
						continue;
					}
					add(dp[j ^ (1 << y)], 1LL * dp[j] * ee[k].second % MOD);
				}
			}
		}
		for(int mask = 0; mask < (1 << nn); mask++) {
			int cnt = 0;
			for(int j = 0; j < nn; j++) {
				cnt += (mask >> j & 1);
			}
			add(g[cnt], dp[mask]);
		}
	} else {
		//cout << "type 2" << endl;
		vector<pair<pair<int, int>, int> > rest;
		for(int i = 0; i < tot; i++) {
			int a = edges[i].first.first, b = edges[i].first.second;
			father[a] = a;
			father[b + n] = b + n;
			e[a].clear();
			e[b + n].clear();
		}
		for(int i = 0; i < tot; i++) {
			int a = edges[i].first.first, b = edges[i].first.second;
			int number = edges[i].second;
			if (getFather(a) != getFather(b + n)) {
				father[getFather(a)] = getFather(b + n);
				e[a].push_back(make_pair(b + n, number));
				e[b + n].push_back(make_pair(a, number));
			} else {
				rest.push_back(edges[i]);
			}
		}
		//assert(rest.size() <= tot / 3 + 1);
		for(int mask = 0; mask < (1 << (int)rest.size()); mask++) {
			for(int i = 0; i < 2; i++)
				for(int j = 0; j < (int)nodes[i].size(); j++) {
					deleted[nodes[i][j] + i * n] = false;
				}
			int legal = true, base = 1, choosed = 0;
			for(int i = 0; i < (int)rest.size() && legal; i++) {
				if (mask >> i & 1) {
					int a = rest[i].first.first, b = rest[i].first.second, c = rest[i].second;
					if (deleted[a] || deleted[b + n]) {
						legal = false;
					} else {
						deleted[a] = deleted[b + n] = true;
					}
					base = 1LL * base * c % MOD;
					choosed++;
				}
			}
			if (!legal) {
				continue;
			}
			
			total.clear();
			for(int i = 0; i < 2; i++)
				for(int j = 0; j < (int)nodes[i].size(); j++) {
					if (!deleted[nodes[i][j] + i * n]) {
						total.push_back(nodes[i][j] + i * n);
					}
				}
			sort(total.begin(), total.end());
			for(int i = 0; i <= total.size(); i++) {
				pre[i] = (i == choosed ? base : 0);
			}
			int ss = choosed;
			for(int i = 0; i < (int)total.size(); i++) {
				if (!deleted[total[i]]) {
					int x = treeDP(total[i], -1);
					for(int j = ss; j >= 0; j--) {
						int temp = pre[j];
						pre[j] = 0;
						for(int k = 0; k <= size[x]; k++) {
							add(pre[j + k], 1LL * temp * tree[x][k][0] % MOD);
							add(pre[j + k], 1LL * temp * tree[x][k][1] % MOD);
						}
					}
					ss += size[x];
				}
			}
			for(int i = 0; i <= ss; i++) {
				add(g[i], pre[i]);
			}
		}
	}
	/*
	printf("g: \n");
	for(int i = 0; i <= 5; i++) {
		printf("%d ", g[i]);
	}
	printf("\n");*/
	combine(f, g);
}

int main() {
	scanf("%d %d", &n, &k);
	for(int i = 0; i < k; i++) {
		int a, b, w;
		scanf("%d %d %d", &a, &b, &w);
		--w;
		//assert(w >= 0);
		linked.push_back(make_pair(make_pair(a, b), w));
		exist[0][a] = exist[1][b] = 1;
		
	}
	f[0] = 1;
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < 2; j++) {
			if (exist[j][i] != 1) {
				continue;
			}
			nodes[0].clear();
			nodes[1].clear();
			edges.clear();
			dfs(j, i);
			solve();
		}
	}
	
	int base = 1, answer = 0;
	for(int i = 0; i <= n; i++) {
		answer += 1LL * base * f[n - i] % MOD;
		answer %= MOD;
		base = 1LL * base * (i + 1) % MOD;
	}
	cout << answer << endl;
	return 0;
}