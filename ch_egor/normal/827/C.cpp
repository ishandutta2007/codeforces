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

const int MAX_N = 1000 * 100 + 228;

inline int get_id(char c)
{
	if (c == 'A')
		return 0;
	else if (c == 'T')
		return 1;
	else if (c == 'G')
		return 2;
	else
		return 3;
}


int n, q;
char st[MAX_N];
char st_now[MAX_N];
int gg[11][11][4][MAX_N];

inline void add(int a, int b, int c, int x, int to_add)
{
	for (; x < n; x = ((x + 1) | x))
		gg[a][b][c][x] += to_add;
}

inline int get(int a, int b, int c, int x)
{
	int ans = 0;
	for (; x > -1; x = ((x + 1) & x) - 1)
		ans += gg[a][b][c][x];
	return ans;
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

	scanf("%s", st);
	n = strlen(st);
	
	for (int i = 0; i < 11; ++i)
	{
		for (int j = 0; j < 11; ++j)
		{
			for (int k = 0; k < 4; ++k)
			{
				for (int p = 0; p < MAX_N; ++p)
				{
					gg[i][j][k][p] = 0;
				}
			}
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 1; j < 11; ++j)
		{
			add(j, i % j, get_id(st[i]), i, 1);
		}
	}
	
	scanf("%d", &q);

	int t, l, r, x;
	char c;
	for (int i = 0; i < q; ++i)
	{
		scanf("%d", &t);

		if (t == 1)
		{
			scanf("%d %c\n", &x, &c);
			--x;
			for (int i = 1; i < 11; ++i)
			{
				add(i, x % i, get_id(st[x]), x, -1);
				add(i, x % i, get_id(c), x, 1);
			}
			st[x] = c;
		}
		else
		{
			scanf("%d %d %s\n", &l, &r, st_now);
			--l; --r;	
			int len = strlen(st_now);
			int ans = 0;
			
			for (int i = 0; i < len; ++i)
			{
				ans += get(len, (l + i) % len, get_id(st_now[i]), r) - 
					   get(len, (l + i) % len, get_id(st_now[i]), l - 1);
			}
			
			printf("%d\n", ans);
		}
	}

	return 0;
}