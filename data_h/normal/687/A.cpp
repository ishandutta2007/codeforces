#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

const int N = 1e5 + 6;

vector<int> e[N];
vector<int> cover[2];
int color[N];

int n, m;

bool bfs(int s) {
	static vector<int> queue;
	queue.clear();
	queue.push_back(s);
	color[s] = 0;
	for (int head = 0; head < (int)queue.size(); head++) {
		int x = queue[head];
		for (int i = 0; i < (int)e[x].size(); i++) {
			int y = e[x][i];
			if (color[y] == -1) {
				color[y] = color[x] ^ 1;
				queue.push_back(y);
			} else if ((color[y] ^ 1) != color[x]) {
				return false;
			}
		}
	}
	for (vector<int> :: iterator it = queue.begin(); it != queue.end(); ++it) {
		cover[color[*it]].push_back(*it);
	}
	return true;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		e[u].push_back(v);
		e[v].push_back(u);
	}

	fill(color + 1, color + n + 1, -1);
	for (int i = 1; i <= n; i++) {
		if (color[i] == -1) {
			if (!bfs(i)) {
				puts("-1");
				return 0;
			}
		}
	}
	for (int i = 0; i < 2; i++) {
		printf("%d\n", cover[i].size());
		for (int j = 0; j < cover[i].size(); j++) {
			printf("%d%c", cover[i][j], j + 1 == cover[i].size() ? '\n' : ' ');
		}
	}
	return 0;
}