#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 111111;

vector<int> e[N], road;
int n, m, root, visit[N], v[N];

void dfs(int x, int father) {
	v[x] = 1;
	road.push_back(x);
	visit[x] ^= 1;
	int lastSon = -1;
	for(int i = 0; i < (int)e[x].size(); i++) {
		int y = e[x][i];
		if (v[y]) {
			continue;
		}
		dfs(y, x);
		road.push_back(x);
		visit[x] ^= 1;
		lastSon = y;
	} 
	if (visit[x]) {
		if (father != 0) {
			road.push_back(father);
			visit[father] ^= 1;
			road.push_back(x);
			visit[x] ^= 1;
		} else {
			if (lastSon == -1) {
				return ;
			}
			road.pop_back();
			visit[x] ^= 1;
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		e[a].push_back(b);
		e[b].push_back(a);
	}	
	for(int i = 1; i <= n; i++) {
		scanf("%d", &visit[i]);
		v[i] = 0;
	}
	
	bool flag = false;
	for(int i = 1; i <= n; i++) {
		if (visit[i]) {
			root = i;
			dfs(i, 0);
			flag = true;
			break;
		}
	}
	if (!flag) {
		printf("%d\n", 0);
	} else {
		for(int i = 1; i <= n; i++) {
			if (visit[i]) {
				printf("-1\n");
				exit(0);
			}
		}
		printf("%d\n", (int)road.size());
		for(int i = 0; i < (int)road.size(); i++) {
			printf("%d%c", road[i], i == (int)road.size() - 1 ? '\n' : ' ');
		}
	}
	return 0;
}