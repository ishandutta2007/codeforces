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

const int MAX_N = 1005;

#define fr first
#define sc second

int n;
pair<string, string> arr[MAX_N];
int pt[MAX_N];
map<string, vector<int>> gg;
map<string, bool> used;

int main()
{
#ifdef CH_EGOR
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
#endif 	

	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		string st1, st2;
		cin >> st1 >> st2;
		arr[i].first = st1.substr(0, 3);
		arr[i].second = st1.substr(0, 2) + st2.substr(0, 1);
	}
	
	for (int i = 0; i < n; ++i)
	{
		gg[arr[i].first].push_back(i);
	}
	
	for (auto it = gg.begin(); it != gg.end(); ++it)
	{
		if (it->second.size() >= 2)
		{
			for (int i = 0; i < (int)it->second.size(); ++i)
			{
				pt[it->second[i]] = 2;
				if (used[arr[it->second[i]].sc])
					return 0 * printf("NO\n");
				used[arr[it->second[i]].sc] = true;
			}
		}
	}
	
	for (int i = 0; i < n; ++i)
	{
		if (pt[i] == 0)
		{
			if (used[arr[i].fr])
			{
				if (used[arr[i].sc])
					return 0 * printf("NO\n");
				used[arr[i].sc] = true;
				pt[i] = 2;
				i = -1;
			}
		}
	}

	printf("YES\n");
	for (int i = 0; i < n; ++i)
	{
		if (pt[i] == 0)
		{
			printf("%s\n", arr[i].fr.c_str());
		}
		else
		{
			printf("%s\n", arr[i].sc.c_str());
		}
	}

	return 0;
}