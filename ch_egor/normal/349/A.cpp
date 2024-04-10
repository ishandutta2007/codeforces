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

const int MAX_N = 1000 * 100 + 5;

int n;
int arr[MAX_N];
int cnt[2];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cnt[0] = cnt[1] = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &arr[i]);

		if (arr[i] == 25)
		{
			++cnt[0];
		}
		else if (arr[i] == 50)
		{
			if (cnt[0] == 0)
			{
				printf("NO");
				return 0;
			}
			else
			{
				--cnt[0];
				++cnt[1];
			}
		}
		else
		{
			if (cnt[1] >= 1 && cnt[0] >= 1)
			{
				--cnt[1];
				--cnt[0];
			}
			else if (cnt[0] >= 3)
			{
				cnt[0] -= 3;
			}
			else
			{
				printf("NO");
				return 0;
			}
		}
	}

	printf("YES");

	fclose(stdin);
	fclose(stdout);

	return 0;
}