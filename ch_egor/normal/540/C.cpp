#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cassert>
#include <iomanip>
//#include <ctime>
//#include <cmath>

using namespace std;

typedef long long int int64;
typedef long double double80;

struct point
{
	int x;
	int y;
};

int n, m;
int r1, c1, r2, c2;
string graf[1005];
bool used[1005][1005];

int moveX[4] = { 1, -1, 0, 0 };
int moveY[4] = { 0, 0, 1, -1 };
queue<point> arr;

bool is_correct(int x, int y)
{
	return 0 <= x && x < n && 0 <= y && y < m;
}

void bfs(int x, int y)
{
	point add;
	point now;
	add.x = x;
	add.y = y;
	arr.push(add);

	while (!arr.empty())
	{
		now = arr.front();
		arr.pop();

		for (int i = 0; i < 4; ++i)
		{
			if (is_correct(now.x + moveX[i], now.y + moveY[i]))
			{
				if (graf[now.x + moveX[i]][now.y + moveY[i]] != 'X' && !used[now.x + moveX[i]][now.y + moveY[i]])
				{
					add.x = now.x + moveX[i];
					add.y = now.y + moveY[i];
					arr.push(add);
					used[add.x][add.y] = true;
				}
			}
		}
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		cin >> graf[i];
		for (int j = 0; j < m; ++j)
		{
			used[i][j] = false;
		}
	}

	cin >> r1 >> c1;
	cin >> r2 >> c2;

	--r1;
	--c1;
	--r2;
	--c2;


	used[r1][c1] = true;
	bfs(r1, c1);

	point now;

	now.x = r2;
	now.y = c2;

	bool good = false;
	int cnt = 0;
	for (int i = 0; i < 4; ++i)
	{
		if (is_correct(now.x + moveX[i], now.y + moveY[i]))
		{
			if (used[now.x + moveX[i]][now.y + moveY[i]])
			{
				good = true;
				++cnt;
			}
			else if (graf[now.x + moveX[i]][now.y + moveY[i]] == '.')
			{
				++cnt;
			}
		}
	}

	//for (int i = 0; i < n; ++i)
	//{
	//	for (int j = 0; j < m; ++j)
	//	{
	//		cout << used[i][j] ? "X" : ".";
	//	}
	//	cout << "\n";
	//}

	if (good && graf[r2][c2] == 'X')
	{
		cout << "YES";
	}
	else if (good && cnt >= 2)
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}