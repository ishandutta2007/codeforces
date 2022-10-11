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

typedef long long int ll;
typedef long double ld;

const int INF = 1000 * 1000 * 1000 + 21;
const ll LLINF = (1ll << 60) + 5;
const int MOD = 1000 * 1000 * 1000 + 7;

const int MAX_N = 1228;

const char an[] = "DLRU";
const int dy[4] = {0, -1, 1, 0};
const int dx[4] = {1, 0, 0, -1};

int n, m, k;
int x, y;
char arr[MAX_N][MAX_N];
int dp[MAX_N][MAX_N];
char answer[1228228];
int ptr = 0;

bool is_correct(int x, int y)
{
	return 0 <= x && x < n && 0 <= y && y < m && arr[x][y] != '*';
}

int main()
{
#ifdef CH_EGOR
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
#endif 	

	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; ++i)
	{
		scanf("%s", arr[i]);
		for (int j = 0; j < m; ++j)
		{
			if (arr[i][j] == 'X')
			{
				x = i;
				y = j;
			}
		}
	}
	
	for (int i = 0; i < n; ++i)
	{
	    for (int j = 0; j < m; ++j)
	    {
	        dp[i][j] = INF;
	    }
	}
	
	dp[x][y] = 0;
	queue<pair<int, int>> kek;
	kek.push({x, y});
	while (!kek.empty())
	{
	    int xx = kek.front().first;
	    int yy = kek.front().second;
	    kek.pop();
	    for (int i = 0; i < 4; ++i)
	    {
	        int newx = xx + dx[i];
	        int newy = yy + dy[i];
	        if (is_correct(newx, newy) && dp[newx][newy] > dp[xx][yy] + 1)
	        {
	            kek.push({newx, newy});
	            dp[newx][newy] = dp[xx][yy] + 1;
	        }
	    }
	}
	
	if (k & 1)
		return 0 * printf("IMPOSSIBLE\n");
	
	for (int i = 0; i < k; ++i)
	{
	    for (int j = 0; j < 4; ++j)
	    {
	        int newx = x + dx[j];
	        int newy = y + dy[j];
	        if (is_correct(newx, newy) && dp[newx][newy] <= k - i - 1)
	        {
	            x = newx;
	            y = newy;
	            answer[ptr++] = an[j];
	            break;
	        }
	    }
	}
	
	if (ptr != k)
		return 0 * printf("IMPOSSIBLE\n");

	answer[k] = '\0';
	printf("%s\n", answer);

	return 0;
}