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
const int64 LLINF = (1ll << 59) + 5;
const int MOD = 1000 * 1000 * 1000 + 7;

int n, m, k;
vector<int> time1;
vector<int> time2;
vector<int> arr1;
vector<int> arr2;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d %d %d", &n, &m, &k);

	time1.resize(n);
	arr1.resize(n);
	time2.resize(m);
	arr2.resize(m);
	
	for (int i = 0; i < n; ++i)
	{
		arr1[i] = time1[i] = 0;
	}
	for (int i = 0; i < m; ++i)
	{
		arr2[i] = time2[i] = 0;
	}


	int type, a, b;

	for (int i = 1; i <= k; ++i)
	{
		scanf("%d %d %d", &type, &a, &b);
		--a;
		if (type == 1)
		{
			arr1[a] = b;
			time1[a] = i;
		}
		else
		{
			arr2[a] = b;
			time2[a] = i;
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (time1[i] > time2[j])
			{
				printf("%d ", arr1[i]);
			}
			else
			{
				printf("%d ", arr2[j]);
			}
		}
		printf("\n");
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}