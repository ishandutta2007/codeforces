#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cassert>
#include <iomanip>
//#include <ctime>
//#include <cmath>

using namespace std;

typedef long long int int64;
typedef long double double80;

struct point
{
	int d;
	int h;
};

point arr[100005];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n, m;

	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; ++i)
	{
		scanf("%d %d", &arr[i].d, &arr[i].h);
	}

	int answer = 0;
	bool good = true;

	answer = max(arr[0].h + arr[0].d - 1, arr[m-1].h+n-arr[m-1].d);

	for (int i = 0; i < m - 1; ++i)
	{
		if (abs(arr[i + 1].h - arr[i].h) > arr[i + 1].d - arr[i].d)
		{
			good = false;
			break;
		}
		else
		{
			answer = max(answer, ((arr[i + 1].d - arr[i].d) - abs(arr[i + 1].h - arr[i].h)) / 2 +max(arr[i + 1].h, arr[i].h));
		}
	}

	if (good)
	{
		printf("%d", answer);
	}
	else
	{
		printf("IMPOSSIBLE");
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}