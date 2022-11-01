#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

const int N = 22;

int n, m;
char row[N], col[N];
int visit[N][N];

int main() {
	scanf("%d %d", &n, &m);
	scanf("%s", row);
	scanf("%s", col);
	bool flag = true;
	vector<pair<int, int> > queue;
	for(int sx = 0; sx < n; sx++)
		for(int sy = 0; sy < m; sy++) {
			memset(visit, 0, sizeof(visit));
			queue.clear();
			queue.push_back(make_pair(sx, sy));
			visit[sx][sy] = 1;
			for(int head = 0; head < (int)queue.size(); head++) {
				pair<int, int> pos = queue[head];
				if (row[pos.first] == '>' && pos.second + 1 < m && !visit[pos.first][pos.second + 1]) {
					visit[pos.first][pos.second + 1] = 1;
					queue.push_back(make_pair(pos.first, pos.second + 1));
				}
				if (row[pos.first] == '<' && pos.second > 0 && !visit[pos.first][pos.second - 1]) {
					visit[pos.first][pos.second - 1] = 1;
					queue.push_back(make_pair(pos.first, pos.second - 1));
				}
				if (col[pos.second] == 'v' && pos.first + 1 < n && !visit[pos.first + 1][pos.second]) {
					visit[pos.first + 1][pos.second] = 1;
					queue.push_back(make_pair(pos.first + 1, pos.second));
				}
				if (col[pos.second] == '^' && pos.first > 0 && !visit[pos.first - 1][pos.second]) {
					visit[pos.first - 1][pos.second] = 1;
					queue.push_back(make_pair(pos.first - 1, pos.second));
				}
			}
			//printf("%d %d %d\n", sx, sy, (int)queue.size());
			flag &= (queue.size() == (n * m));
		}
	puts(flag ? "YES" : "NO");
	return 0;
}