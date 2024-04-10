#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 60;
const int MAXLEN = 10000000;

vector<int> vision[MAXN][MAXN];
int dir[MAXN][MAXN];
int queue[MAXLEN + 5];

const int MID = MAXLEN / 2;
int n, m;

int Go(int sx, int sy) {
	int L = MID, R = MID - 1;
	for(int i = 0; i < vision[sx][sy].size(); i++) 
		queue[++R] = vision[sx][sy][i];
	int pl = -1, pr = -1;
	for(int i = L + 1; i <= R; i++)
		if (queue[i - 1] == sx && queue[i] == sy) 
			pl = i - 1, pr = i;
	if (pl == -1)
		return 0;
	
	//before
	while(R - L + 1 <= 2 * n && pl > L) {
		int x = queue[pl - 1], now = queue[pl];
		if (x == sx && now == sy || dir[x][now] == 0)
			return 0;
		for(int i = vision[x][now].size() - 1; i >= 0; i--)
			queue[--L] = vision[x][now][i];
		pl--;
	}
	
	//after
	while(R - L + 1 <= 2 * n && pr < R) {
		int x = queue[pr + 1], now = queue[pr];
		if (now == sx && x == sy || dir[now][x] == 0)
			return 0;
		for(int i = 0; i < vision[now][x].size(); i++)
			queue[++R] = vision[now][x][i];
		pr++;
	}
	
	if (R - L + 1 <= 2 * n) {
		printf("%d\n", R - L + 1);
		for(int i = L; i <= R; i++) {
			printf("%d%c", queue[i], i == R ? '\n' : ' ');
		}
		return 1;
	}
	return 0;
}

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		dir[x][y] = 1;
		int k;
		scanf("%d", &k);
		int v;
		for(int j = 0; j < k; j++) {
			scanf("%d", &v);
			vision[x][y].push_back(v);
		}
	}
	bool flag = false;
	for(int i = 1; i <= n && flag == false; i++)
		for(int j = 1; j <= n && flag == false; j++)
			if (vision[i][j].size() > 1) {
				flag |= Go(i, j);
			}
	if (!flag)
		printf("0\n");
	return 0;
}