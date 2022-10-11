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
const int64 LLINF = (1ll << 60) + 5;
const int MOD = 1000 * 1000 * 1000 + 7;

const int MAX_W = 505;

int h, w;
int q;
char desk[MAX_W][MAX_W];
int line[MAX_W][MAX_W];
int down[MAX_W][MAX_W];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d %d", &h, &w);

	for (int i = 0; i < h; ++i)
	{
		scanf("%s", desk[i]);
	}

	for (int i = 0; i < h; ++i)
	{
		line[i][0] = 0;
		for (int j = 1; j < w; ++j)
		{
			line[i][j] = (desk[i][j] == '.' && desk[i][j - 1] == '.');
		}
		for (int j = 1; j < w; ++j)
		{
			line[i][j] += line[i][j - 1];
		}
	}

	for (int i = 0; i < w; ++i)
	{
		down[0][i] = 0;
	}

	for (int i = 1; i < h; ++i)
	{
		for (int j = 0; j < w; ++j)
		{
			down[i][j] = (desk[i - 1][j] == '.' && desk[i][j] == '.');
		}
		for (int j = 1; j < w; ++j)
		{
			down[i][j] += down[i][j - 1];
		}
	}

	scanf("%d", &q);

	int x1, y1, x2, y2;
	int answer;
	for (int l = 0; l < q; ++l)
	{
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		--x1, --y1;

		answer = 0;
		for (int i = x1; i < x2; ++i)
		{
			answer += line[i][y2 - 1] - ((y1 > 0) ? line[i][y1] : 0); 
			if (i != x1)
			{
				answer += down[i][y2 - 1] - ((y1 > 0) ? down[i][y1 - 1] : 0);
			}
		}

		printf("%d\n", answer);
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}