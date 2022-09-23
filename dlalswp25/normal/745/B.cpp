#include <stdio.h>

char board[505][505];

int main()
{
	int n, m;	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++)
	{
		scanf("%s", board[i]);
	}

	int lx = 1000, ly = 1000, rx = -1, ry = -1;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(board[i][j] == 'X')
			{
				if(lx > i)	lx = i;
				if(rx < i)	rx = i;
				if(ly > j)	ly = j;
				if(ry < j)	ry = j;
			}
		}
	}

	bool possible = true;
	for(int i = lx; i <= rx; i++)
	{
		for(int j = ly; j <= ry; j++)
		{
			if(board[i][j] != 'X')	possible = false;
		}
	}
	if(possible)	puts("YES");
	else	puts("NO");
	return 0;
}