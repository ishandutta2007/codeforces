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

string st;
int tp[400];


int main()
{
#ifdef CH_EGOR
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
#endif

	int n;
	cin >> n;
	cin >> st;
	for (int i = 0; i < 26; ++i) tp[i] = -1;
	
	for (int i = 0; i < n; ++i)
	{
		if (st[i] != '*') tp[st[i] - 'a'] = 1;
	}

	int t;
	cin >> t;
	while (t--)	{
		string now;
		cin >> now;
		
		bool good = true;
		for (int i = 0; i < n; ++i)
		{
			if (st[i] != '*')
			{
				good &= (now[i] == st[i]);
			}
			else
			{
				good &= (tp[now[i] - 'a'] != 1);
			}
		}

		if (good)
		{
			set<int> ff;
			for (int i = 0; i < n; ++i)
			{
				if (st[i] == '*')
				{
					ff.insert(now[i] - 'a');
				}
			}

			for (auto it = ff.begin(); it != ff.end(); ++it)
			{
				if (tp[*it] == -1)
				{
					tp[*it] = 3;
				}
				else if (tp[*it] != 228)
				{
					tp[*it] = 3;
				}
			}

			for (int i = 0; i < 26; ++i)
			{
				if (tp[i] == 3) tp[i] = 2;
				else if (tp[i] == 2) tp[i] = 228;
				else if (tp[i] == -1) tp[i] = 228;
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < 26; ++i)
		ans += (tp[i] == 2);
	printf("%d\n", ans);

	return 0;
}