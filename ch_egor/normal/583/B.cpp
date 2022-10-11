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
const int MAX_N = 1005;

int n;
int arr[MAX_N];
bool used[MAX_N];
int now = 0;


int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &arr[i]);
		used[i] = false;
	}

	int answer = -1;

	while (now != n)
	{
		++answer;
		for (int i = 0; i < n; ++i)
		{
			if (!used[i] && arr[i] <= now)
			{
				used[i] = true;
				++now;
			}
		}
		if (now == n)
		{
			break;
		}

		++answer;
		for (int i = n - 1; i >= 0; --i)
		{
			if (!used[i] && arr[i] <= now)
			{
				used[i] = true;
				++now;
			}
		}
	}

	printf("%d", answer);

	fclose(stdin);
	fclose(stdout);

	return 0;
}