#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <vector>
#include <iostream>
#include <cassert>
using namespace std;

const int N = 111111;
const int INF = (1 << 30);


int n, center, size[N], father[N];
long long dist[N];
vector<pair<int, int> > e[N];

int getCenter() {
	vector<int> q;
	q.push_back(1);
	father[1] = 0;
	for(int head = 0; head < (int)q.size(); head++) {
		int x = q[head];
		for(int i = 0; i < (int)e[x].size(); i++) {
			int y = e[x][i].first;
			if (y == father[x]) {
				continue;
			}
			q.push_back(y);
			father[y] = x;
		}
	}
	int cent = -1, minV = INF;
	for(int i = n - 1; i >= 0; i--) {
		int x = q[i], cur = 0;
		size[x] = 1;
		for(int j = 0; j < (int)e[x].size(); j++) {
			int y = e[x][j].first;
			if (y == father[x]) {
				continue;
			}
			cur = max(cur, size[y]);
			size[x] += size[y];
		}
		cur = max(cur, n - size[x]);
		if (cur < minV) {
			minV = cur;
			cent = x;
		}
	}
	assert(minV <= n / 2);
	return cent;
}

#define open OPEN

int tot, open[N];
int closed[N], who[N], match[N], belone[N];
int sl[N], sr[N];

int minID[N << 2], visited[N];
priority_queue<pair<int, int> > values;



void dfs(int x, int fat, long long value) {
	father[x] = fat;
	dist[x] = value;
	open[x] = ++tot;
	who[tot] = x;
	
	for(int i = 0; i < (int)e[x].size(); i++) {
		int y = e[x][i].first;
		if (y == fat) {
			continue;
		}
		dfs(y, x, value + e[x][i].second);
	}
	closed[x] = tot;
}

void build(int x, int l, int r) {
	if (l == r) {
		minID[x] = who[l];
	} else {
		int mid = (l + r) / 2;
		build(x << 1, l, mid);
		build(x << 1 | 1, mid + 1, r);
		minID[x] = min(minID[x << 1], minID[x << 1 | 1]);
	}
}

int ask(int x, int l, int r, int ql, int qr) {
	if (qr < l || r < ql) {
		return INF;
	}
	if (ql <= l && r <= qr) {
		return minID[x];
	}
	int mid = (l + r) / 2;
	return min(ask(x << 1, l, mid, ql, qr), ask(x << 1 | 1, mid + 1, r, ql, qr));
}

void delet(int x, int l, int r, int pos) {
	if (l == r) {
		minID[x] = INF;
	} else {
		int mid = (l + r) >> 1;
		if (pos <= mid) {
			delet(x << 1, l, mid, pos);
		} else {
			delet(x << 1 | 1, mid + 1, r, pos);
		}
		minID[x] = min(minID[x << 1], minID[x << 1 | 1]);
	}
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i < n; i++) {
		int a, b, w;
		scanf("%d %d %d", &a, &b, &w);
		e[a].push_back(make_pair(b, w));
		e[b].push_back(make_pair(a, w));
	}
	if (n == 1) {
		printf("0\n");
		printf("1\n");
		return 0;
	}
	center = getCenter();
	dfs(center, 0, 0);
	closed[center] = 1;
	
	belone[center] = center;
	sl[center] = sr[center] = 1;
	values.push(make_pair(sl[center] + sr[center], center));
	for(int i = 0; i < (int)e[center].size(); i++) {
		int y = e[center][i].first;
		for(int j = open[y]; j <= closed[y]; j++) {
			int it = who[j];
			belone[it] = y;
		}
		sl[y] = sr[y] = closed[y] - open[y] + 1;
		values.push(make_pair(sl[y] + sr[y], y));
	}
	
	build(1, 1, n);
	for(int x = 1; x <= n; x++) {
		while(1) {
			int it = values.top().second;
			if (sl[it] + sr[it] != values.top().first) {
				values.pop();
			} else {
				break;
			}
		}
		
		pair<int, int> top = values.top();
		assert(top.first <= n - x + 1);
		if (top.first == n - x + 1) {
			int which = top.second;
			if (which == center) {
				if (x == n) {
					for(int i = 1; i <= n; i++) {
						if (!visited[i]) {
							match[x] = i;
						}
					}
				} else {
					vector<int> ls, rs;
					for(; x <= n; x++) {
						ls.push_back(x);
					}
					for(int i = 1; i <= n; i++) {
						if (!visited[i]) {
							rs.push_back(i);
						}	
					}
					sort(rs.begin(), rs.end());
					if (ls[0] == rs[0] && ls[0] != center || ls[1] == rs[1] && ls[1] != center) {
						swap(rs[0], rs[1]);
					}
					match[ls[0]] = rs[0];
					match[ls[1]] = rs[1];
				}
				break;
			}
			vector<int> inner, outer;
			for(int i = 1; i <= n; i++) {
				if (visited[i]) {
					continue;
				}
				if (open[i] >= open[which] && open[i] <= closed[which]) {
					inner.push_back(i);
				} else {
					outer.push_back(i);
				}
			}
			sort(inner.begin(), inner.end());
			reverse(inner.begin(), inner.end());
			sort(outer.begin(), outer.end());
			reverse(outer.begin(), outer.end());
			for(; x <= n; x++) {
				if (open[which] <= open[x] && open[x] <= closed[which]) {
					match[x] = outer.back();
					outer.pop_back();
				} else {
					match[x] = inner.back();
					inner.pop_back();
				}
				visited[match[x]] = 1;
			}
			break;
		} else {
			int bel = belone[x];
			int y = min(ask(1, 1, n, 1, open[bel] - 1), ask(1, 1, n, closed[bel] + 1, n));
			if (x == center && !visited[center]) {
				y = min(y, center);
			}
			match[x] = y;
			// del x
			sl[bel]--;
			values.push(make_pair(sl[bel] + sr[bel], bel));
			delet(1, 1, n, open[y]);
			bel = belone[y];
			sr[bel]--;
			values.push(make_pair(sl[bel] + sr[bel], bel));
			visited[y] = 1;
		}
	}
	long long answer = 0;
	for(int i = 1; i <= n; i++) {
		answer += dist[i];
	}
	cout << 2 * answer << endl;
	for(int i = 1; i <= n; i++) {
		printf("%d%c", match[i], i < n ? ' ' : '\n');
	}
	return 0;
}