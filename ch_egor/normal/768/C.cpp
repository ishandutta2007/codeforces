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

const int MAX_X = 1024;

int n, k, x;
int arr[228228];
int cnt[2][MAX_X];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d%d", &n, &k, &x);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &arr[i]);
		++cnt[0][arr[i]];
	}

	int pt = 0;
	for (int i = 0; i < k; ++i)
	{
		int prev = 0;
		for (int j = 0; j < MAX_X; ++j)
		{
			if (prev % 2 == 0)
			{
				cnt[pt ^ 1][j^x] += ((cnt[pt][j] + 1) >> 1);
				cnt[pt ^ 1][j] += cnt[pt][j] - ((cnt[pt][j] + 1) >> 1);
			}
			else
			{
				if (cnt[pt][j] > 0)
				{
					cnt[pt ^ 1][j] += 1;
					prev += 1;
					--cnt[pt][j];
					cnt[pt ^ 1][j^x] += ((cnt[pt][j] + 1) >> 1);
					cnt[pt ^ 1][j] += cnt[pt][j] - ((cnt[pt][j] + 1) >> 1);
				}
			}
			prev += cnt[pt][j];
		}
		pt ^= 1;
		memset(cnt[pt ^ 1], 0, sizeof(int)* MAX_X);
	}

	int ma = -1;
	int mi = 228228;
	for (int i = 0; i < MAX_X; ++i)
	{
		//cout << cnt[pt^1][i] << " " << i << endl;
		if (cnt[pt][i] != 0)
		{
			ma = max(ma, i);
			mi = min(mi, i);
		}
	}

	cout << ma << " " << mi << endl;

	fclose(stdin);
	fclose(stdout);

	return 0;
}