#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <cassert>
#include <algorithm>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <bitset>

#pragma comment(linker, "/STACK:256000000")

using namespace std;

typedef long long int int64;
typedef long double double80;

const int INF = (1 << 29) + 5;
const int64 LLINF = (1ll << 59) + 5;
const int MOD = 1000 * 1000 * 1000 + 7;
const int MAX_N = 105;

const int GG = 1000 * 1000 * 1000 + 1;

struct pp
{
	int type;
	int x;
};

int n, m, q;
int arr[MAX_N][MAX_N];
int new_g[MAX_N];
vector<pair<int, int> > move1;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d %d %d", &n, &m, &q);

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			arr[i][j] = 0;
		}
	}

	int t, x, y, z;
	for (int i = 0; i < q; ++i)
	{
		scanf("%d", &t);
		if (t == 1)
		{
			scanf("%d", &x);
			--x;
			for (int j = 0; j < m; ++j)
			{
				new_g[j] = arr[x][(j + 1) % m];
			}
			for (int j = 0; j < m; ++j)
			{
				arr[x][j] = new_g[j];
			}
			move1.push_back(make_pair(t, x));
		}
		else if (t == 2)
		{
			scanf("%d", &x);
			--x;
			for (int j = 0; j < n; ++j)
			{
				new_g[j] = arr[(j + 1) % n][x];
			}
			for (int j = 0; j < n; ++j)
			{
				arr[j][x] = new_g[j];
			}
			move1.push_back(make_pair(t, x));
		}
		else
		{
			scanf("%d %d %d", &x, &y, &z);
			--x; --y;
			arr[x][y] = z;
		}
	}

	
	for (int i = (int)move1.size() - 1; i >= 0; --i)
	{
		x = move1[i].second;
		if (move1[i].first == 1)
		{
			for (int j = 0; j < m; ++j)
			{
				new_g[j] = arr[x][(j - 1 + m) % m];
			}
			for (int j = 0; j < m; ++j)
			{
				arr[x][j] = new_g[j];
			}
		}
		else
		{
			for (int j = 0; j < n; ++j)
			{
				new_g[j] = arr[(j - 1 + n) % n][x];
			}
			for (int j = 0; j < n; ++j)
			{
				arr[j][x] = new_g[j];
			}
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	
	fclose(stdin);
	fclose(stdout);

	return 0;
}