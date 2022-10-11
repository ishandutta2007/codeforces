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

const int MAX_N = 1000 + 5;

int n, m, c;
int arr[MAX_N];

int main()
{
#ifdef CH_EGOR
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
#endif

	for (int i = 0; i < MAX_N; ++i) arr[i] = -1;

	scanf("%d%d%d", &n, &m, &c);
	
	int bad = n;
	for (int i = 0; i < m && bad; ++i)
	{
		int x;
		scanf("%d", &x);
	
		if (2 * x <= c)
		{
			for (int i = 0; i < n; ++i)
			{
				if (arr[i] == -1 || arr[i] > x)
				{
					if (arr[i] == -1) --bad;
					
					printf("%d\n", i + 1);
					fflush(stdout);
					
					arr[i] = x;
					break;
				}
			}
		}
		else
		{
			for (int i = n - 1; i >= 0; --i)
			{
				if (arr[i] == -1 || arr[i] < x)
				{
					if (arr[i] == -1) --bad;
					
					printf("%d\n", i + 1);
					fflush(stdout);
					
					arr[i] = x;
					break;
				}
			}
		}
	}

	return 0;
}