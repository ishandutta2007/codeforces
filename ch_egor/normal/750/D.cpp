#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <assert.h>
#include <algorithm>
#include <iomanip>
#include <time.h>
#include <math.h>
#include <bitset>

#pragma comment(linker, "/STACK:256000000")

using namespace std;

typedef long long int int64;
typedef long double double80;

const int INF = (1 << 29) + 5;
const int64 LLINF = (1ll << 59) + 5;
const int MOD = 1000 * 1000 * 1000 + 7;

#define st asdfasdf
#define mv asdfsda
struct st
{
	int dx;
	int dy;
	int ln;
};

#define next next228
#define prev prev228
pair<int, int> next(int x, int y)
{
	if (x == 1 && y == 0)
	{
		return{ 1, -1 };
	}
	else if (x == 1 && y == -1)
	{
		return{ 0, -1 };
	}
	else if (x == 0 && y == -1)
	{
		return{ -1, -1 };
	}
	else if (x == -1 && y == -1)
	{
		return{ -1, 0 };
	}
	else if (x == -1 && y == 0)
	{
		return{ -1, 1 };
	}
	else if (x == -1 && y == 1)
	{
		return{ 0, 1 };
	}
	else if (x == 0 && y == 1)
	{
		return{ 1, 1 };
	}
	else
	{
		return{ 1, 0 };
	}
}

pair<int, int> prev(int x, int y)
{
	if (x == 1 && y == 0)
	{
		return{ 1, 1 };
	}
	else if (x == 1 && y == 1)
	{
		return{ 0, 1 };
	}
	else if (x == 0 && y == 1)
	{
		return{ -1, 1 };
	}
	else if (x == -1 && y == 1)
	{
		return{ -1, 0 };
	}
	else if (x == -1 && y == 0)
	{
		return{ -1, -1 };
	}
	else if (x == -1 && y == -1)
	{
		return{ 0, -1 };
	}
	else if (x == 0 && y == -1)
	{
		return{ 1, -1 };
	}
	else
	{
		return{ 1, 0 };
	}
}
#define us gasgd
int n;
int arr[35];
bool used[320][320][3][3][7];

bool us[320][320];
vector<st> mv[2][320][320];
int cur;

void add(int x, int y, int dx, int dy, int len)
{
	if (!used[x][y][dx + 1][dy + 1][len])
	{
		used[x][y][dx + 1][dy + 1][len] = true;
		mv[cur ^ 1][x][y].push_back({ dx, dy, len });
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &arr[i]);
	}

	mv[0][155][155].push_back({ 1, 0, arr[0] - 1});
	memset(used, 0, sizeof(used));
	memset(us, 0, sizeof(us));
	used[155][155][2][1][arr[0] - 1] = true;
	arr[n] = 0;
	cur = 0;
	for (int it = 0; it < n; ++it)
	{
	   
	   memset(used, 0, sizeof(used));
		for (int x = 0; x < 320; ++x)
		{
			for (int y = 0; y < 320; ++y)
			{
				for (int i = 0; i < mv[cur][x][y].size(); ++i)
				{
					//cout << x - 155 << " " << y - 155 << " " << it << endl;
					int dx = mv[cur][x][y][i].dx;
					int dy = mv[cur][x][y][i].dy;
					int ln = mv[cur][x][y][i].ln;
					//cout << dx << " " << dy  << " " << ln << endl;
					//cout << "EB\n";
					for (int p = 0; p <= ln; ++p)
					{
						us[x + dx * p][y + dy * p] = true;
					}
					int ln2 = ln;

					int a = next(dx, dy).first;
					int b = next(dx, dy).second;
					int nx = x + dx * ln2;
					int ny = y + dy * ln2;
					add(nx, ny, a, b, arr[it + 1]);
					a = prev(dx, dy).first;
					b = prev(dx, dy).second;
					add(nx, ny, a, b, arr[it + 1]);
				}
				mv[cur][x][y].clear();
			}
		}
		cur ^= 1;
	}

	int answer = 0;
	for (int i = 0; i < 320; ++i)
	{
		for (int j = 0; j < 320; ++j)
		{
			answer += us[i][j];
		}
	}

	cout << answer;

	fclose(stdin);
	fclose(stdout);

	return 0;
}