#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 222, M = N * N * 2, INF = 1e9;

struct eglist {
	int sum, other[M], succ[M], last[M], cap[M];
	eglist() {
		fill(last, last + M, -1);
		sum = 0;
	}
	void add_edge(int a, int b, int c) {
		other[sum] = b, succ[sum] = last[a], last[a] = sum, cap[sum++] = c;
		other[sum] = a, succ[sum] = last[b], last[b] = sum, cap[sum++] = 0;	
	}
};


eglist e;
int n, visit[N], a[N];

void dead() {
	puts("Impossible");
	exit(0);
}

bool isPrime(int x) {
	for(int i = 2; i * i <= x; i++) {
		if (x % i == 0) {
			return false;
		}
	}
	return true;
}

vector<pair<int, int> > evens, odds;
int source, target, dist[N];

bool bfs() {
	static vector<int> queue;
	queue.clear();
	queue.push_back(target);
	for(int i = 1; i <= target; i++) {
		dist[i] = -1;
	}
	dist[target] = 0;
	for(int head = 0; head < (int)queue.size(); head++) {
		int x = queue[head];
		for(int i = e.last[x]; ~i; i = e.succ[i]) {
			int y = e.other[i];
			if (e.cap[i ^ 1] && dist[y] == -1) {
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
	for(int i = e.last[x]; ~i; i = e.succ[i]) {
		int y = e.other[i];
		if (e.cap[i] && dist[y] + 1 == dist[x]) {
			int t = dfs(y, min(delta, e.cap[i]));
			e.cap[i] -= t;
			e.cap[i ^ 1] += t;
			delta -= t;
			if (delta == 0) {
				break;
			}
		}
	}
	return flow - delta;
}

void dfs(int x, int from, vector<int> &tmp) {
	visit[x] = 1;
	tmp.push_back(x);
	for(int i = e.last[x]; ~i; i = e.succ[i]) {
		int y = e.other[i];
		if (y == from || y == source || y == target || visit[y]) {
			continue;
		}
		if ((a[x] % 2 == 0 && e.cap[i] == 0) || (a[x] % 2 == 1 && e.cap[i] == 1)) {
			dfs(y, x, tmp);
			break;
		}
	}
}

int main() {
	scanf("%d", &n);
	source = n + 1;
	target = n + 2;
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		if (a[i] % 2 == 0) {
			e.add_edge(source, i, 2);
		} else {
			e.add_edge(i, target, 2);
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if (isPrime(a[i] + a[j]) && a[i] % 2 == 0) {
				e.add_edge(i, j, 1);
			}
		}
	}
	
	int ret = 0;
	while(bfs()) {
		ret += dfs(source, INF);
	}
	//printf("%d\n", ret);
	if (ret != n) {
		dead();
	}

	vector<vector<int> > answer;
	fill(visit + 1, visit + n + 1, 0);
	
	for(int i = 1; i <= n; i++) {
		if (!visit[i]) {
			answer.push_back(vector<int>());
			dfs(i, -1, answer.back());
		}
	}
	printf("%d\n", (int)answer.size());
	for(int i = 0; i < (int)answer.size(); i++) {
		printf("%d", (int)answer[i].size());
		for(int j = 0; j < (int)answer[i].size(); j++) {
			printf(" %d", answer[i][j]);
		}
		puts("");
	}
	return 0;
}