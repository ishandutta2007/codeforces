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

const int MAX_N = 505;

const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

int n, m;
char arr[MAX_N][MAX_N];

int main()
{
#ifdef CH_EGOR
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
#endif

	scanf("%d%d", &n, &m);

	for (int i = 0; i < n; ++i) scanf("%s", arr[i]);
	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j)
	{
		if (arr[i][j] == '.') arr[i][j] = 'D';
		if (arr[i][j] == 'S')
		{
			for (int p = 0; p < 4; ++p)
			{
				int nx = i + dx[p];
				int ny = j + dy[p];

				if (0 <= nx && nx < n && 0 <= ny && ny < m && arr[nx][ny] == 'W') return 0 * printf("No\n");
			}
		}
	}
	
	printf("Yes\n");
	for (int i = 0; i < n; ++i) printf("%s\n", arr[i]);

	return 0;
}