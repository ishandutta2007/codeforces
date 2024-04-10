#include <cstdio>
#include <cstdlib>

const int MAXN = 60;

struct node
{
	int x, y;
}q[MAXN * MAXN];
int bot, top, visit[MAXN][MAXN];

int N, M, Tot;
char map[MAXN][MAXN];

void Init()
{
	scanf("%d %d\n", &N, &M);
	for(int i = 1;i <= N;i++)
		gets(map[i] + 1);
}

int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};

int Check(int Target)
{
	int sx, sy;
	for(int i = 1;i <= N;i++)
		for(int j = 1;j <= M;j++)
		{
			visit[i][j] = 0;
			if (map[i][j] == '#')
				sx = i, sy = j;
		}
	visit[sx][sy] = 1;
	q[top = 1] = (node){sx, sy};
	bot = 0;
	while(bot < top)
	{
		node tmp = q[++bot];
		for(int i = 0;i < 4;i++)
		{
			int x = tmp.x + dx[i];
			int y = tmp.y + dy[i];
			if (x < 1 || x > N || y < 1 || y > M || map[x][y] == '.' || visit[x][y])
				continue;
			q[++top] = (node){x, y};
			visit[x][y] = 1;
		}
	}
	return top != Target;
}

void Work()
{
	for(int i = 1;i <= N;i++)
		for(int j = 1;j <= M;j++)
			Tot += (map[i][j] == '#');
	if (Check(Tot))
	{
		printf("0\n");
		exit(0);
	}
	if (Tot <= 1)
	{
		printf("-1\n");
		exit(0);
	}
	if (Tot > 2)
	for(int i = 1;i <= N;i++)
		for(int j = 1;j <= M;j++)
		if (map[i][j] == '#')
		{
			map[i][j] = '.';
			if (Check(Tot - 1))
			{
				printf("1\n");
				exit(0);
			}
			map[i][j] = '#';
		}
	if (Tot < 4)
	{
		printf("-1\n");
		exit(0);
	}
	printf("2\n");
}

int main()
{
	Init();
	Work();
	return 0;
}