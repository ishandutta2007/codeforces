#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

const int N = 111, M = N * N * 2;
const int INF = 100000000;

int n, m;
int a[N];
vector<int> values;

int visit[N];
vector<pair<int, int> > pairs;
int source, target;
int dist[N], cur[N];

struct eglist {
	int other[M], cap[M], succ[M], last[N], sum;
	void clear(int n) {
		fill(last + 1, last + n + 1, -1);
		sum = 0;
	}
	void addEdge(int a, int b, int c) {
		other[sum] = b, succ[sum] = last[a], last[a] = sum, cap[sum++] = c;
		other[sum] = a, succ[sum] = last[b], last[b] = sum, cap[sum++] = 0;
	}
}e;

bool bfs() {
	static vector<int> queue;
	queue.clear();
	queue.push_back(target);
	for(int i = 1; i <= target; i++) {
		dist[i] = -1;
		cur[i] = e.last[i];
	}
	dist[target] = 0;
	for(int head = 0; head < (int)queue.size(); head++) {
		int x = queue[head];
		for(int i = e.last[x]; ~i; i = e.succ[i]) {
			int y = e.other[i];
			if (dist[y] == -1 && e.cap[i ^ 1]) {
				dist[y] = dist[x] + 1;
				queue.push_back(y);
			}
		}
	}
	return dist[source] != -1;
}

int dfs(int x, int flow) {
	if (x == target) {
		return flow;
	}
	int delta = flow;
	for(int &i = cur[x]; ~i; i = e.succ[i]) {
		int y = e.other[i];
		if (dist[y] + 1 == dist[x] && e.cap[i]) {
			int temp = dfs(y, min(delta, e.cap[i]));
			e.cap[i] -= temp;
			e.cap[i ^ 1] += temp;
			delta -= temp;
			if (!delta) {
				break;
			}
		}
	}
	return flow - delta;
}

int solve(int v) {
	//cout << v << endl;
	source = n + 1, target = n + 2;
	e.clear(target);
	for(int i = 0; i < (int)pairs.size(); i++) {
		e.addEdge(pairs[i].first, pairs[i].second, INF);
	}
	for(int i = 1; i <= n; i++) {
		int cnt = 0;
		while(a[i] % v == 0) {
			cnt++;
			a[i] /= v;
		}
		if (i % 2 == 1) {
			e.addEdge(source, i, cnt);
		} else {
			e.addEdge(i, target, cnt);
		}
	}
	//cout << "flow" << endl;
	int result = 0;
	while(bfs()) {
		result += dfs(source, INF);
	}
	return result;
}

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		int x = a[i];
		for(long long j = 2; j * j <= x; j++) {
			if (x % j == 0) {
				values.push_back(j);
				while(x % j == 0) {
					x /= j;
				}
			}
		}
		if (x > 1) {
			values.push_back(x);
		}
	}
	for(int i = 1; i <= m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		if (a % 2 == 0) {
			swap(a, b);
		}
		pairs.push_back(make_pair(a, b));
	}

	sort(values.begin(), values.end());
	values.erase(unique(values.begin(), values.end()), values.end());

	int answer = 0;
	for(int i = 0; i < (int)values.size(); i++) {
		answer += solve(values[i]);
	}
	printf("%d\n", answer);
	return 0;
}