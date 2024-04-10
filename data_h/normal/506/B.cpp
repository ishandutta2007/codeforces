#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 111111;

vector<int> e[N];
vector<int> ee[N];
vector<int> vecs;

int n, m, visit[N], degree[N];

void dfs(int x) {
	if (visit[x]) {
		return ;
	}
	visit[x] = 1;
	vecs.push_back(x);
	for(int i = 0; i < (int)e[x].size(); i++) {
		int y = e[x][i];
		dfs(y);
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		e[a].push_back(b);
		e[b].push_back(a);
		ee[a].push_back(b);
		degree[b]++;
	}

	int answer = n;

	for(int i = 1; i <= n; i++) {
		if (visit[i]) {
			continue;
		}
		vecs.clear();
		dfs(i);
		static vector<int> queue;
		queue.clear();
		for(int j = 0; j < (int)vecs.size(); j++) {
			int x = vecs[j];
			//printf("xx = %d\n", x);
			if (degree[x] == 0) {
				queue.push_back(x);
			}
		}
		for(int head = 0; head < (int)queue.size(); head++) {
			int x = queue[head];
			//printf("x = %d\n", x);
			for (int j = 0; j < (int)ee[x].size(); j++) {
				int y = ee[x][j];
				if (--degree[y] == 0) {
					queue.push_back(y);
				}
			}
		}
		if ((int)queue.size() == (int)vecs.size()) {
			answer--;
		}
	}
	printf("%d\n", answer);
	return 0;
}