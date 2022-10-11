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

int n;
int64 arr1[228228];
int64 arr2[228228];
vector<pair<int64, int64> > gg;

vector<int> arr11;
vector<int> arr22;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);


	int64 l = 0;
	int64 r = LLINF;

	int64 bl = 0;
	for (int i = 0; i < n; ++i)
	{
		scanf("%lld %lld", &arr1[i], &arr2[i]);
		gg.push_back({ -arr2[i], bl });
		bl += arr1[i];
	}

	sort(gg.begin(), gg.end());
	for (int i = 0; i < (int)gg.size() - 1; ++i)
	{
		//cout << gg[i].first << " " << gg[i].second << endl;
		if (gg[i].second > gg[i + 1].second)
		{
			printf("Impossible");
			return 0;
		}
		if (gg[i].second == gg[i + 1].second && gg[i].first != gg[i + 1].first)
		{
			printf("Impossible");
			return 0;
		}
	}

	for (int i = 0; i < (int)gg.size(); ++i)
	{
		if (gg[i].first == -2)
		{
			arr22.push_back(gg[i].second);
		}
		else
		{
			arr11.push_back(gg[i].second);
		}
	}

	if (arr11.empty())
	{
		int64 last = arr22.back();
		int64 answer = 1899 - last + bl;
		cout << answer;
	}
	else if (arr22.empty())
	{
		printf("Infinity");
	}
	else
	{
		int64 last = arr22.back();
		int64 fr = arr11[0];

		int64 right = 1899 - last;
		int64 left = 1900 - fr;
		if (left > right)
		{
			printf("Impossible");
			return 0;
		}
		cout << right + bl;
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}