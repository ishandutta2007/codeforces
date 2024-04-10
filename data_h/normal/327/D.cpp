#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>
#include <cstring>

using namespace std;

const int MAXN = 600;

char map[MAXN][MAXN];
int hash[MAXN][MAXN];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

struct node
{
	char t;
	int x, y;
}p[MAXN * MAXN * 3], q[MAXN * MAXN];
int n, m, top;

void Bfs(int sx, int sy)
{
	int t, w;
	t = 0, w = 0;
	hash[sx][sy] = 1;
	q[++w].x = sx, q[w].y = sy;
	while(t < w) {
		t++;
		for(int i = 0; i < 4; i++) {
			int x = q[t].x + dx[i];
			int y = q[t].y + dy[i];
			if (x > n || x < 1 || y > m || y < 1 || hash[x][y])
				continue;
			hash[x][y] = 1;
			q[++w].x = x;
			q[w].y = y;
		}
	}
	for(int i = 1; i <= w; i++)
		p[++top].t = 'B', p[top].x = q[i].x, p[top].y = q[i].y;
	for(int i = w; i > 1; i--) {
		p[++top].t = 'D', p[top].x = q[i].x, p[top].y = q[i].y;
		p[++top].t = 'R', p[top].x = q[i].x, p[top].y = q[i].y;
	}
}

int main()
{
	scanf("%d %d", &n, &m); getchar();
	for(int i = 1; i <= n; i++)
		gets(map[i] + 1);
	top = 0;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			if (map[i][j] == '#')
				hash[i][j] = 1;
			else
				hash[i][j] = 0;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			if (hash[i][j] == 0)
				Bfs(i, j);
	printf("%d\n", top);
	for(int i = 1; i <= top; i++) {
		printf("%c %d %d\n", p[i].t, p[i].x, p[i].y);
	}
	return 0;
}