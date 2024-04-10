#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <cstring>
using namespace std;

const int N = 2e6 + 10, M = 2e6 + 10;
const int K = 6;
const int INF = 1e9;

vector<pair<int, int> > answer;
int n;
int edge[11][11];
int number[10];
int boss[8] = {0, 1, 10, 100, 1000, 10000, 100000, 1000000};
int go[7] = {0, 1, 10, 100, 1000, 10000, 100000};

class Eglist {
public:
	int other[M << 1], succ[M << 1], last[N], sum, cap[M << 1];
	void clear() {
		sum = 0;
		fill(last, last + 100, -1);
	}
	void add_edge(int a, int b, int c) {
		other[sum] = b, succ[sum] = last[a], last[a] = sum, cap[sum++] = c;
		other[sum] = a, succ[sum] = last[b], last[b] = sum, cap[sum++] = 0;
	}
}e;

int dist[N], source, target;
map<pair<int, int>, int> cross_edge;
int group_number;

bool bfs() {
	static vector<int> queue;
	queue.clear();
	queue.push_back(target);
	fill(dist, dist + target + 1, -1);
	dist[target] = 0;
	for (int head = 0; head < (int)queue.size(); ++head) {
		int x = queue[head];
		//cout << x << " " << dist[x] << endl;
		for (int i = e.last[x]; ~i; i = e.succ[i]) {
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
	for (int i = e.last[x]; ~i; i = e.succ[i]) {
		int y = e.other[i];
		if (dist[y] == dist[x] - 1 && e.cap[i]) {
			int t = dfs(y, min(delta, e.cap[i]));
			delta -= t;
			e.cap[i] -= t;
			e.cap[i ^ 1] += t;
			if (delta == 0) {
				return flow;
			}
		}
	}
	return flow - delta;
}

int max_flow() {
	int res = 0;
	while (bfs()) {
		res += dfs(source, INF);
	}
	return res;
}

int father[N];

bool solve() {
	e.clear();
	source = group_number + cross_edge.size();
	target = source + 1;

	for (int i = 0; i < group_number; i++) {
		e.add_edge(source, i, number[i + 1] - 1);
	}

	int total_edge = 0, start_edge = e.sum;
	{
		int x = 0;
		for (map<pair<int, int>, int> :: iterator it = cross_edge.begin(); it != cross_edge.end(); ++it, ++x) {
			if (it->first.first == it->first.second) {
				e.add_edge(it->first.first - 1, target, it->second);
			} else {
				e.add_edge(it->first.first - 1, group_number + x, INF);
				e.add_edge(it->first.second - 1, group_number + x, INF);
				int flag = 0;
				if (father[it->first.second] == it->first.first ||
					father[it->first.first] == it->first.second) {
						flag = 1;
					}
				e.add_edge(group_number + x, target, it->second - flag);
			}
		}
	}

	//cout << "enter" << endl;
	int flow = max_flow();
	//cout << "out" << endl;
	//cout << flow << " xx " << group_number << endl;
	if (flow < n - 1 - group_number + 1) {
		return false;
	}
	for (int i = 1; i <= group_number; i++) {
		if (father[i] != i) {
			printf("%d %d\n", boss[father[i]], boss[i]);
		}
	}

	{
		int ex = start_edge;
		for (map<pair<int, int>, int> :: iterator it = cross_edge.begin(); it != cross_edge.end(); ++it) {
			if (it->first.first == it->first.second) {
				for (int i = 0; i < e.cap[ex + 1]; i++) {
					printf("%d %d\n", boss[it->first.first], ++go[it->first.first]);
				}
				ex += 2;
			} else {
				for (int i = 0; i < e.cap[ex + 1]; i++) {
					printf("%d %d\n", boss[it->first.second], ++go[it->first.first]);
				}
				ex += 2;
				for (int i = 0; i < e.cap[ex + 1]; i++) {
					printf("%d %d\n", boss[it->first.first], ++go[it->first.second]);
				}
				ex += 4;
			}
		}
	}
	exit(0);
}

void generate_tree(int dep) {
	if (dep == group_number + 1) {
		int self = -1;
		for (int i = 1; i <= group_number; i++) {
			if (father[i] == i) {
				if (self != -1) {
					return ;
				} else {
					self = i;
				}
			}
		}
		if (self == -1) {
			return ;
		}
		for (int i = 1; i <= group_number; i++) {
			int x = i;
			for (int j = 1; j <= 6; j++) {
				x = father[x];
			}
			if (x != self) {
				return ;
			}
		}

		solve();
		return ;
	}
	for (int i = 1; i <= group_number; i++) {
		if (cross_edge[make_pair(min(i, dep), max(i, dep))] > 0) {
			father[dep] = i;
			generate_tree(dep + 1);
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1, j = 1; i <= 6; i++, j *= 10) {
		number[i] = max(0, min(j * 10 - 1, n) - j + 1);
		if (n < j * 10) {
			group_number = i;
			break;
		}
	}

	for (int i = 1; i < n; i++) {
		char sa[55], sb[55];
		scanf("%s %s", sa, sb);
		int a = strlen(sa), b = strlen(sb);
		if (number[a] == 0 || number[b] == 0) {
			puts("-1");
			return 0;
		}
		if (a > b) swap(a, b);
		cross_edge[make_pair(a, b)]++;
	}

	generate_tree(1);
	puts("-1");
	return 0;
}