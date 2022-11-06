#include <iostream>
#include <cstdlib>
#include <cstdio>
#define L 0
#define R 1
#define U 2
#define D 3
using namespace std; 
int x, y, enx, eny, lr, ud, tot, n, m, clr, cud; 
char word[] = "LRUD", str[105][105]; 
int dx[] = {0, 0, -1, 1}, dy[] = {-1, 1, 0, 0}; 
bool vis[105][105]; 
int que[20005], prex[105][105], prey[105][105], pred[105][105], ans[20005]; 
inline void query(int dir)
{
	if (lr == 1)
	{
		if (dir == L)
			dir = R; 
		else if (dir == R)
			dir = L; 
	}
	if (ud == 1)
	{
		if (dir == U)
			dir = D; 
		else if (dir == D)
			dir = U; 
	}
#ifdef ONLINE_JUDGE
	printf("%c\n", word[dir]);
	fflush(stdout); 
	scanf("%d%d", &x, &y); 
	x--; 
	y--; 
	if (x == enx && y == eny)
		exit(0); 
#else
	if (clr)
	{
		if (dir == L)
			dir = R; 
		else if (dir == R)
			dir = L; 
	}
	if (cud)
	{
		if (dir == U)
			dir = D; 
		else if (dir == D)
			dir = U; 
	}
	x += dx[dir]; 
	y += dy[dir]; 
	if (x < 0)
		x = 0; 
	if (x >= n)
		x = n - 1; 
	if (y < 0)
		y = 0; 
	if (y >= m)
		y = m - 1; 
	if (str[x][y] == '*')
	{
		printf("Wrong Answer reached *\n");
		exit(0); 
	}
	if (x == enx && y == eny)
	{
		printf("Correct reached F\n");
		exit(0); 
	}
#endif
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("811D.in", "r", stdin); 
#endif
	scanf("%d%d", &n, &m); 
#ifndef ONLINE_JUDGE
	scanf("%d%d", &clr, &cud); 
#endif
	for (int i = 0; i < n; i++)
	{
		scanf("%s", str[i]); 
		for (int j = 0; j < m; j++)
		{
			if (str[i][j] == 'F')
			{
				enx = i; 
				eny = j; 
			}
		}
	}
	lr = ud = -1; 
	if (str[0][1] != '*')
	{
		query(L);
		if (!x && !y)
			lr = 0; 
		else
			lr = 1; 
		if (str[1][0] != '*')
		{
			if (x || y)
				query(L); 
		}
		else
		{
			while (str[1][y] == '*')
				query(R); 
		}
		query(U); 
		if (!x)
			ud = 0; 
		else
			ud = 1; 
	}
	else
	{
		query(U);
		if (!x && !y)
			ud = 0; 
		else
			ud = 1; 
		if (str[0][1] != '*')
		{
			if (x || y)
				query(U); 
		}
		else
		{
			while (str[x][1] == '*')
				query(D); 
		}
		query(L); 
		if (!y)
			lr = 0; 
		else
			lr = 1; 
	}
#ifndef ONLINE_JUDGE
	printf("%d %d\n", lr, ud);
#endif
	int he = 0, ta = 0, stx = x, sty = y; 
	que[ta++] = stx; 
	que[ta++] = sty; 
	vis[stx][sty] = true; 
	while (he < ta)
	{
		int x = que[he++]; 
		int y = que[he++]; 
		if (x == enx && y == eny)
			break; 
		for (int i = 0; i < 4; i++)
		{
			int newx = x + dx[i], newy = y + dy[i]; 
			if (newx < 0 || newx >= n || newy < 0 || newy >= m || vis[newx][newy] || str[newx][newy] == '*')
				continue; 
			vis[newx][newy] = true; 
			prex[newx][newy] = x; 
			prey[newx][newy] = y;
			pred[newx][newy] = i; 
			que[ta++] = newx; 
			que[ta++] = newy; 
		}
	}
	int curx = enx, cury = eny; 
	while (curx != stx || cury != sty)
	{
		ans[tot++] = pred[curx][cury]; 
		int tmp = prey[curx][cury]; 
		curx = prex[curx][cury]; 
		cury = tmp; 
	}
	for (int i = tot - 1; i >= 0; i--)
		query(ans[i]); 
	return 0; 
}