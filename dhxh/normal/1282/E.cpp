#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <map>
using namespace std;
const int maxn = 210000;
int A[maxn][3];
set<int> G[maxn];
map<pair<int, int>, int> between;
vector<int> p;
void dfs(int x, int y) {
	int a = min(x, y), b = max(x, y);
	auto pr = make_pair(a, b);
	p.push_back(x);
	if (between.count(pr)) {
		int mid = between[pr];
		p.pop_back();
		dfs(x, mid);
		p.pop_back();
		dfs(mid, y);
		p.pop_back();
	}
	p.push_back(y);
}
int main() {
	//freopen("in.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	while (T--) {
		int n;
		scanf("%d", &n);
		p.clear();
		between.clear();
		for (int i = 0; i <= n; ++i) {
			G[i].clear();
		}
		for (int i = 1; i <= n - 2; ++i) {
			scanf("%d %d %d", &A[i][0], &A[i][1], &A[i][2]);
			for (int j = 0; j <= 2; ++j)
				G[A[i][j]].insert(i);
		}
		queue<int> Q;
		for (int i = 1; i <= n; ++i) if (G[i].size() == 1) {
			Q.push(*G[i].begin());
		}
		vector<int> q;
		int pos[3];
		for (int times = 1; times <= n - 2; ++times){
			int x = Q.front(); Q.pop();
			for (int i = 0; i <= 2; ++i) {
				G[A[x][i]].erase(x);
				if (G[A[x][i]].size() == 1) {
					Q.push(*G[A[x][i]].begin());
				}
				if (G[A[x][i]].size() == 0) {
					q.push_back(x);
					int u[3], sz = 0;
					for (int j = 0; j <= 2; ++j) if (j != i)
						u[sz++] = A[x][j];
					int a = min(u[0], u[1]), b = max(u[0], u[1]);
					if (times != n - 2) {
						between[make_pair(a, b)] = A[x][i];
					}
					else {
						for (int j = 0; j <= 2; ++j)
							pos[j] = A[x][j];
					}
				}
			}
		}
		//printf("->%d %d %d\n", pos[0], pos[1], pos[2]);
		dfs(pos[0], pos[1]);
		p.pop_back();
		dfs(pos[1], pos[2]);
		p.pop_back();
		dfs(pos[2], pos[0]);
		p.pop_back();
		for (auto i : p)
			printf("%d ", i);
		printf("\n");
		for (int i = 0; i < n - 2; ++i)
			printf("%d ", q[i]);
		printf("\n");
	}
	return 0;
}