#include <cstdlib>
#include <cstdio>
char a[55][55], b[55][55]; 
int len, ansx[100005], ansy[100005], n, m; 
inline void fail()
{
	puts("-1"); 
	exit(0); 
}
inline void rotate(int x, int y)
{
	ansx[len] = x; 
	ansy[len++] = y; 
	if (a[x][y] == 'U' && a[x + 1][y] == 'D' && a[x][y + 1] == 'U' && a[x + 1][y + 1] == 'D')
	{
		a[x][y] = 'L'; 
		a[x][y + 1] = 'R'; 
		a[x + 1][y] = 'L'; 
		a[x + 1][y + 1] = 'R'; 
	}
	else if (a[x][y] == 'L' && a[x][y + 1] == 'R' && a[x + 1][y] == 'L' && a[x + 1][y + 1] == 'R')
	{
		a[x][y] = 'U';
		a[x + 1][y] = 'D'; 
		a[x][y + 1] = 'U'; 
		a[x + 1][y + 1] = 'D'; 
	}
	else
		fail(); 
}
inline void rot_hor(int x, int y); 
inline void rot_ver(int x, int y)
{
	if (x < 0 || y < 0 || x >= n || y >= m)
		fail(); 
	if (a[x][y] == 'U' && a[x + 1][y] == 'D')
		return; 
	rot_hor(x + 1, y); 
	rotate(x, y); 
}
inline void rot_hor(int x, int y)
{
	if (x < 0 || y < 0 || x >= n || y >= m)
		fail(); 
	if (a[x][y] == 'L' && a[x][y + 1] == 'R')
		return; 
	if (a[x][y] == 'R')
	{
		rot_hor(x + 1, y - 1); 
		rotate(x, y - 1);
		if (a[x][y + 1] == 'L')
		{
			rot_hor(x + 1, y + 1); 
			rotate(x, y + 1); 
		}
		rotate(x, y); 
	}
	else
	{
		rot_ver(x, y + 1); 
		rotate(x, y); 
	}
}
int main()
{
	// freopen("D.in", "r", stdin); 
	// freopen("D.out", "wt", stdout); 
	scanf("%d%d", &n, &m); 
	for (int i = 0; i < n; i++)
		scanf("%s", a[i]); 
	for (int i = 0; i < n; i++)
		scanf("%s", b[i]); 
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (a[i][j] == b[i][j])
				continue; 
			if (a[i][j] == 'U' && a[i + 1][j] == 'D')
			{
				rot_ver(i, j + 1); 
				rotate(i, j); 
			}
			else if (a[i][j] == 'L' && a[i][j + 1] == 'R')
			{
				rot_hor(i + 1, j); 
				rotate(i, j); 
			}
			else
				fail(); 
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (a[i][j] != b[i][j])
				fail(); 
		}
	}
	printf("%d\n", len);
	for (int i = 0; i < len; i++)
		printf("%d %d\n", ansx[i] + 1, ansy[i] + 1);
	return 0; 
}