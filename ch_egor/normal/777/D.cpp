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

const int MAX_N = 500 * 1000 + 5;
const int MAX_LEN = 500 * 1000 + 5;

int n;
string arr[MAX_N];
char buff[MAX_LEN];
bool is_del[MAX_N];

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
		scanf("%s", buff);
		arr[i] = buff;
	}
	
	memset(is_del, 0, sizeof(is_del));
	for (int i = n - 1; i > 0; --i)
	{
		int j = 1;
		while (j < arr[i].size() && j < arr[i - 1].size() && arr[i][j] == arr[i - 1][j]) ++j;
		if (j < arr[i].size() && j < arr[i - 1].size())
		{
			if (arr[i - 1][j] > arr[i][j])
			{
				arr[i - 1] = arr[i - 1].substr(0, j);
				is_del[i - 1] = true;
			}
		}
		else if (j < arr[i - 1].size())
		{
			arr[i - 1] = arr[i - 1].substr(0, j);
			is_del[i - 1] = true;
		}
	}
	
	for (int i = 0; i < n; ++i)
	{
		printf("%s%s\n", arr[i].c_str(), (is_del[i] ? "" : ""));
	}

	return 0;
}