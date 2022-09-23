#include <stdio.h>
#define MIN(a, b)	(((a) < (b)) ? (a) : (b))
#define MAX(a, b)	(((a) > (b)) ? (a) : (b))

int N, M;
char board[105][105];

int main()
{
	scanf("%d %d", &N, &M);

	for(int i = 0; i < N; i++)
	{
		scanf("%s", board[i]);
	}
	int black = 0;

	int minx, miny;
	int maxx, maxy;
	minx = miny = 987654321;
	maxx = maxy = -1;

	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			if(board[i][j] == 'B')
			{
				black++;
				if(minx > i)	minx = i;
				if(miny > j)	miny = j;
				if(maxx < i)	maxx = i;
				if(maxy < j)	maxy = j;
			}
		}
	}

	int length = MAX(maxx - minx + 1, maxy - miny + 1);

	if(length > MIN(N, M))	puts("-1");
	else if(black == 0)	puts("1");
	else	printf("%d", length * length - black);
	return 0;
}