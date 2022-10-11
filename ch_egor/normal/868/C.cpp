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

const int MAX_N = 100 * 1000 + 228;
const int MAX_K = 5;

int n, k;
int arr[MAX_N][MAX_K];
set<int> have;

int main()
{
#ifdef CH_EGOR
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
#endif 	

	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i)
	{
		int now = 0;
		for (int j = 0; j < k; ++j)
		{
			scanf("%d", &arr[i][j]);
			now |= (arr[i][j] << j);
		}
		have.insert(now);
	}
	
	// i believe i can fly
	for (auto it1 = have.begin(); it1 != have.end(); ++it1)
	{
		for (auto it2 = have.begin(); it2 != have.end(); ++it2)
		{
			if (!((*it1) & (*it2)))
				return 0 * printf("YES\n");
		}
	}

	printf("NO\n");

	return 0;
}